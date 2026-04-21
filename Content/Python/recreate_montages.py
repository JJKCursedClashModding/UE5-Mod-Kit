"""
recreate_montages.py
====================
Unreal Editor Python script.

Walks the project Content folder on disk, finds every .uasset whose name
starts with 'AM_' (cooked / game-extracted AnimMontage), loads each one,
and recreates it as a schema-correct AnimMontage using a C++ deep copy.

Why this is needed
------------------
Game-extracted AnimMontages are serialised against the game engine build which
has extra UPROPERTYs compared to stock UE 5.1.  Loading them triggers
'SchemaIt != SchemaEnd' asserts.  Replacing each file with a fresh
editor-created AnimMontage removes the schema mismatch while keeping the
asset at the path that mod assets reference.

What Python does here
---------------------
  1. Walks the Content directory to find candidate .uasset files.
  2. Loads each asset and checks it is an AnimMontage with a readable skeleton.
  3. Creates a fresh AnimMontage at a temporary path (same directory, name
     suffixed '_jjktmp') using AnimMontageFactory so the editor registers it.
   4. Calls  unreal.MontageBridgeLibrary.copy_montage_data(source, dest)
     which performs the full deep copy in C++ (JJKModKit plugin):
       - SlotAnimTracks     (slot names → AnimSegment arrays → AnimSequence refs)
       - CompositeSections  (section names, start times, next-section links)
       - Notifies           (FAnimNotifyEvent array with proper sub-object
                             ownership AND correct LinkedMontage pointer fixup
                             via FProperty reflection — no timing recalculation)
       - AnimNotifyTracks   (track label rows)
       - BlendIn / BlendOut / RateScale / AutoBlendOut settings
   5. Deletes the cooked original.
   6. Renames the temp asset to the original path.
   7. Saves.

Python does NOT touch animation data — that is entirely owned by the C++ bridge.

Prerequisites
-------------
  • Run inside UE 5.1 editor (requires 'unreal' Python module).
  • Compile the JJKModKit plugin first (see README.md for the build command).

Usage
-----
  JJK ModKit menu → Asset Tools → Recreate Montages
  or:
      import recreate_montages; recreate_montages.run()
  or with a narrower search root:
      recreate_montages.run(search_root='/Game/Characters/CP_010/Animations')
"""

import unreal
import os

# ─── Configuration ─────────────────────────────────────────────────────────────

ONLY_AM_PREFIX = True   # Set False to process every .uasset (non-standard names)
_TEMP_SUFFIX   = '_jjktmp'


# ─── Helpers ───────────────────────────────────────────────────────────────────

def _get_content_dir() -> str:
    raw = unreal.Paths.convert_relative_path_to_full(unreal.Paths.project_content_dir())
    return raw.replace('\\', '/').rstrip('/')


def _engine_path_to_disk(engine_root: str, content_dir: str) -> str:
    rel = engine_root.lstrip('/').replace('Game/', '', 1)
    return (content_dir + '/' + rel).rstrip('/')


def _disk_to_engine(disk_path: str, content_dir: str):
    norm = disk_path.replace('\\', '/')
    rel  = norm[len(content_dir):].lstrip('/')
    parts = rel.split('/')
    asset_name   = parts[-1][:-7]           # strip ".uasset"
    package_path = '/Game/' + '/'.join(parts[:-1])
    return package_path, asset_name


def _find_montage_files(search_dir: str) -> list:
    results = []
    for root, _dirs, files in os.walk(search_dir):
        for fname in files:
            if not fname.endswith('.uasset'):
                continue
            if ONLY_AM_PREFIX and not fname.startswith('AM_'):
                continue
            results.append(os.path.join(root, fname).replace('\\', '/'))
    return sorted(results)


# ─── Core ──────────────────────────────────────────────────────────────────────

def _recreate_one(disk_path: str, content_dir: str, asset_tools) -> str:
    """
    Recreate a single cooked AnimMontage.

    Returns 'ok' | 'fail' | 'skipped' | 'unreadable'.
    """
    package_path, asset_name = _disk_to_engine(disk_path, content_dir)
    engine_path      = f'{package_path}/{asset_name}'
    temp_name        = asset_name + _TEMP_SUFFIX
    temp_engine_path = f'{package_path}/{temp_name}'

    unreal.log(f'[RecreateMontages] Processing {engine_path}')

    # ── 0. Clean up any stale temp from a previous crashed run ────────────────
    if unreal.EditorAssetLibrary.does_asset_exist(temp_engine_path):
        unreal.log_warning(f'[RecreateMontages]   Stale temp found — deleting {temp_engine_path}')
        unreal.EditorAssetLibrary.delete_asset(temp_engine_path)

    # ── 1. Load the existing asset ────────────────────────────────────────────
    try:
        existing = unreal.load_asset(engine_path)
    except Exception:
        existing = None

    if existing is None:
        unreal.log_error(
            f'[RecreateMontages]   SKIPPED (unreadable): {engine_path}\n'
            '    Asset could not be loaded — left untouched.'
        )
        return 'unreadable'

    if not isinstance(existing, (unreal.AnimMontage, unreal.AnimComposite)):
        unreal.log(f'[RecreateMontages]   Skipping — {type(existing).__name__} is not an AnimMontage.')
        return 'skipped'

    # ── 2. Read skeleton (needed by the factory to create the new asset) ──────
    try:
        skeleton = existing.get_editor_property('skeleton')
    except Exception:
        skeleton = None

    if skeleton is None:
        unreal.log_error(
            f'[RecreateMontages]   SKIPPED (no skeleton): {engine_path}\n'
            '    Could not read skeleton — left untouched.'
        )
        return 'unreadable'

    # ── 3. Create a clean AnimMontage at the TEMP path ────────────────────────
    # Must happen BEFORE deleting 'existing' so the source stays valid in memory
    # for the C++ bridge copy in step 4.
    factory = unreal.AnimMontageFactory()
    factory.set_editor_property('target_skeleton', skeleton)

    temp_montage = asset_tools.create_asset(
        asset_name   = temp_name,
        package_path = package_path,
        asset_class  = unreal.AnimMontage,
        factory      = factory,
    )

    if temp_montage is None:
        unreal.log_error(f'[RecreateMontages]   create_asset returned None for {temp_engine_path}.')
        return 'fail'

    # ── 4. C++ deep copy ──────────────────────────────────────────────────────
    # MontageBridgeLibrary.copy_montage_data copies ALL montage data in C++:
    #   SlotAnimTracks, CompositeSections, Notifies (with proper LinkedMontage
    #   fixup via FProperty reflection + DuplicateObject for sub-objects),
    #   AnimNotifyTracks, BlendIn/Out, RateScale, AutoBlendOut settings.
    bridge = getattr(unreal, 'MontageBridgeLibrary', None)
    if bridge is None:
        unreal.log_error(
            '[RecreateMontages]   MontageBridgeLibrary NOT AVAILABLE.\n'
            '    Compile and enable the JJKModKit plugin, then reopen the editor.\n'
            '    See README.md for the build command.'
        )
        unreal.EditorAssetLibrary.delete_asset(temp_engine_path)
        return 'fail'

    try:
        bridge.copy_montage_data(existing, temp_montage)
    except Exception as e:
        unreal.log_error(f'[RecreateMontages]   copy_montage_data raised: {e}')
        unreal.EditorAssetLibrary.delete_asset(temp_engine_path)
        return 'fail'

    # ── 5. Save the temp asset ────────────────────────────────────────────────
    unreal.EditorAssetLibrary.save_asset(temp_engine_path, only_if_is_dirty=False)

    # ── 6. Delete the cooked original ────────────────────────────────────────
    deleted_original = unreal.EditorAssetLibrary.delete_asset(engine_path)
    if not deleted_original:
        unreal.log_error(
            f'[RecreateMontages]   delete original FAILED: {engine_path}\n'
            f'    Aborting — original left untouched, temp stranded at {temp_engine_path}.'
        )
        unreal.EditorAssetLibrary.delete_asset(temp_engine_path)
        return 'fail'

    unreal.log(f'[RecreateMontages]   Deleted original: {engine_path}')

    # ── 7. Rename temp → original path ───────────────────────────────────────
    renamed = unreal.EditorAssetLibrary.rename_asset(temp_engine_path, engine_path)
    if not renamed:
        unreal.log_error(
            f'[RecreateMontages]   rename_asset FAILED: {temp_engine_path} → {engine_path}\n'
            f'    Replacement stranded at {temp_engine_path} — rename manually in Content Browser.'
        )
        return 'fail'

    # ── 8. Save at final path ─────────────────────────────────────────────────
    unreal.EditorAssetLibrary.save_asset(engine_path, only_if_is_dirty=False)

    # ── 9. Post-rename timing check ───────────────────────────────────────────
    # Reload the asset from its final path and log notify times so we can
    # confirm that the rename / PostLoad cycle does not corrupt timing.
    try:
        renamed_montage = unreal.load_asset(engine_path)
        if renamed_montage and isinstance(renamed_montage, unreal.AnimMontage):
            bridge.log_notify_times(renamed_montage)
    except Exception as e:
        unreal.log_warning(f'[RecreateMontages]   log_notify_times raised: {e}')

    unreal.log(f'[RecreateMontages]   ✓ Recreated: {engine_path}')
    return 'ok'


# ─── Content-Browser context-menu helpers ─────────────────────────────────────

def _get_selected_cb_folder() -> 'str | None':
    """
    Return the currently selected Content Browser folder path, or None.

    Tries two sources in order:

    1. unreal.MontageBridgeLibrary.get_selected_folder_paths()
       Provided by the JJKModKit C++ plugin — calls
       IContentBrowserSingleton::GetSelectedFolders() directly.
       Guaranteed to be available when the plugin is compiled and loaded.

    2. unreal.EditorUtilityLibrary.get_selected_folder_paths()
       Present in UE 5.2+ engine builds; may or may not be bound in UE 5.1.

    Returns an engine path like '/Game/Characters/CP_010', or None.
    """
    # ── 1. JJKModKit bridge (most reliable in UE 5.1) ─────────────────────────
    bridge = getattr(unreal, 'MontageBridgeLibrary', None)
    if bridge is not None:
        fn = getattr(bridge, 'get_selected_folder_paths', None)
        if fn is not None:
            try:
                paths = fn()
                if paths:
                    return str(paths[0]).rstrip('/')
            except Exception:
                pass

    # ── 2. Built-in EditorUtilityLibrary (UE 5.2+) ────────────────────────────
    fn = getattr(unreal.EditorUtilityLibrary, 'get_selected_folder_paths', None)
    if fn is not None:
        try:
            paths = fn()
            if paths:
                return str(paths[0]).rstrip('/')
        except Exception:
            pass

    return None


def _pick_engine_folder() -> 'str | None':
    """
    Show a native folder-picker dialog (tkinter askdirectory) rooted at the
    project Content directory.

    Returns an engine path like '/Game/Characters/CP_010', or None if cancelled.
    """
    import tkinter as tk
    from tkinter import filedialog

    content_dir = _get_content_dir()

    root = tk.Tk()
    root.withdraw()
    root.attributes('-topmost', True)
    folder = filedialog.askdirectory(
        title='Select Content folder — Recreate Montages will process it recursively',
        initialdir=content_dir,
        parent=root,
    )
    root.destroy()

    if not folder:
        return None

    folder = folder.replace('\\', '/')
    content_dir = content_dir.rstrip('/')

    # Convert absolute disk path → engine path (must be inside Content/)
    if folder.startswith(content_dir):
        rel = folder[len(content_dir):].lstrip('/')
        return ('/Game/' + rel).rstrip('/') if rel else '/Game'

    # User navigated outside Content/ — treat as full-game scan
    return '/Game'


# ─── Context-menu entry points ────────────────────────────────────────────────

def run_on_selected_folder() -> None:
    """
    Recreate AnimMontage assets in the folder currently selected in the
    Content Browser.

    Called from:
        Content Browser → right-click folder → JJK ModKit → Recreate Montages in Folder

    Reads the selected folder via UEditorUtilityLibrary::GetSelectedFolderPaths()
    (→ IContentBrowserSingleton::GetSelectedFolders()).  The right-clicked folder
    is still selected while the context menu is open, so no dialog is normally
    needed.  Falls back to a folder-picker dialog only if the API returns empty.
    """
    folder = _get_selected_cb_folder()

    if folder is None:
        unreal.log(
            '[RecreateMontages] get_selected_folder_paths() returned empty — '
            'opening folder picker.'
        )
        folder = _pick_engine_folder()

    if folder is None:
        unreal.log('[RecreateMontages] Folder selection cancelled — nothing done.')
        return

    unreal.log(f'[RecreateMontages] Context-menu folder: {folder}')
    run(search_root=folder)


def run_on_selected_assets() -> None:
    """
    Recreate only the AnimMontage asset(s) currently selected in the
    Content Browser.

    Called from:
        Content Browser → right-click asset(s) → JJK ModKit → Recreate Montage(s)

    Non-AnimMontage / AnimComposite assets in the selection are silently skipped.
    The AM_* filename prefix filter (ONLY_AM_PREFIX) is intentionally bypassed —
    if you explicitly selected an asset for recreation, it is processed regardless
    of its name.
    """
    try:
        selected = unreal.EditorUtilityLibrary.get_selected_assets()
    except Exception as e:
        unreal.log_error(f'[RecreateMontages] get_selected_assets() failed: {e}')
        return

    if not selected:
        unreal.log_warning('[RecreateMontages] No assets selected in the Content Browser.')
        return

    bridge = getattr(unreal, 'MontageBridgeLibrary', None)
    if bridge is None:
        unreal.log_error(
            '[RecreateMontages] JJKModKit bridge NOT AVAILABLE — aborting.\n'
            '    Compile the JJKModKit plugin (see README.md) then reopen the editor.'
        )
        return

    content_dir = _get_content_dir()
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

    # Keep only AnimMontage / AnimComposite assets.
    montage_assets = [
        a for a in selected
        if isinstance(a, (unreal.AnimMontage, unreal.AnimComposite))
    ]

    if not montage_assets:
        unreal.log_warning(
            '[RecreateMontages] None of the selected assets is an AnimMontage / '
            'AnimComposite — nothing to do.'
        )
        return

    unreal.log('─' * 60)
    unreal.log(
        f'[RecreateMontages] Running on {len(montage_assets)} selected montage(s) '
        f'({len(selected)} total in selection).'
    )

    ok = fail = skipped = unreadable = 0

    with unreal.ScopedSlowTask(
        len(montage_assets), 'Recreating selected AnimMontage assets…'
    ) as slow:
        slow.make_dialog(True)

        for asset in montage_assets:
            if slow.should_cancel():
                unreal.log_warning('[RecreateMontages] Cancelled by user.')
                break

            slow.enter_progress_frame(1, asset.get_name())

            # asset.get_path_name() → '/Game/Chars/.../AM_Foo.AM_Foo'
            # Strip the '.ObjectName' outer-object suffix to get the package path.
            engine_path = asset.get_path_name().split('.')[0]

            # Convert engine path → disk path
            rel       = engine_path.lstrip('/').replace('Game/', '', 1)
            disk_path = f'{content_dir}/{rel}.uasset'

            result = _recreate_one(disk_path, content_dir, asset_tools)
            if   result == 'ok':          ok         += 1
            elif result == 'fail':        fail       += 1
            elif result == 'unreadable':  unreadable += 1
            else:                         skipped    += 1

    unreal.log('─' * 60)
    unreal.log(
        f'[RecreateMontages] ━━━ Complete ━━━  '
        f'recreated={ok}  skipped={skipped}  unreadable={unreadable}  failed={fail}'
    )
    if unreadable:
        unreal.log_warning(
            f'[RecreateMontages] {unreadable} asset(s) could not be loaded or had '
            'no skeleton — left untouched. Check the Output Log for details.'
        )
    if fail:
        unreal.log_warning(
            f'[RecreateMontages] {fail} asset(s) failed — '
            'check the Output Log for details.'
        )


# ─── Public API ────────────────────────────────────────────────────────────────

def run(search_root: str = '/Game') -> None:
    """
    Recreate all cooked AnimMontage assets found under *search_root*.

    Parameters
    ----------
    search_root : str
        Engine path to search (default '/Game' = entire Content folder).
        Pass a narrower path to limit scope, e.g.
        '/Game/Characters/CP_010/Animations'.
    """
    content_dir = _get_content_dir()
    unreal.log('─' * 60)
    unreal.log('[RecreateMontages] Starting AnimMontage recreation pass')
    unreal.log(f'[RecreateMontages] Content dir  : {content_dir}')
    unreal.log(f'[RecreateMontages] Search root  : {search_root}')
    unreal.log(f'[RecreateMontages] Prefix filter : {"AM_* only" if ONLY_AM_PREFIX else "all .uasset"}')

    if getattr(unreal, 'MontageBridgeLibrary', None) is None:
        unreal.log_error(
            '[RecreateMontages] JJKModKit bridge NOT AVAILABLE — aborting.\n'
            '    Compile the JJKModKit plugin (see README.md) then reopen the editor.'
        )
        return
    unreal.log('[RecreateMontages] JJKModKit bridge: AVAILABLE.')

    disk_search_dir = content_dir if search_root == '/Game' \
        else _engine_path_to_disk(search_root, content_dir)

    if not os.path.isdir(disk_search_dir):
        unreal.log_error(f'[RecreateMontages] Search dir does not exist: {disk_search_dir}')
        return

    montage_files = _find_montage_files(disk_search_dir)
    unreal.log(f'[RecreateMontages] Found {len(montage_files)} candidate file(s).')

    if not montage_files:
        unreal.log('[RecreateMontages] Nothing to process — done.')
        return

    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    ok = fail = skipped = unreadable = 0

    with unreal.ScopedSlowTask(len(montage_files), 'Recreating AnimMontage assets…') as slow:
        slow.make_dialog(True)
        for disk_path in montage_files:
            if slow.should_cancel():
                unreal.log_warning('[RecreateMontages] Cancelled by user.')
                break
            slow.enter_progress_frame(1, disk_path.split('/')[-1])
            result = _recreate_one(disk_path, content_dir, asset_tools)
            if   result == 'ok':          ok          += 1
            elif result == 'fail':        fail        += 1
            elif result == 'unreadable':  unreadable  += 1
            else:                         skipped     += 1

    unreal.log('─' * 60)
    unreal.log(
        f'[RecreateMontages] ━━━ Complete ━━━  '
        f'recreated={ok}  skipped={skipped}  unreadable={unreadable}  failed={fail}'
    )
    if unreadable:
        unreal.log_warning(
            f'[RecreateMontages] {unreadable} asset(s) could not be loaded or had no skeleton — '
            'left untouched. Check the Output Log for details.'
        )
    if fail:
        unreal.log_warning(
            f'[RecreateMontages] {fail} asset(s) failed — check the Output Log for details.'
        )

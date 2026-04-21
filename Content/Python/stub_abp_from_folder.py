"""
stub_abp_from_folder.py
=======================
Unreal Editor Python script.

Shows a folder-picker dialog, then walks the chosen folder recursively,
finds every ABP_*.uasset / *_ABP.uasset file, and creates a minimal stub
AnimBlueprint at the matching /Game/... engine path (same directory hierarchy).

Skeleton resolution (per-ABP, checked against live engine content):
  1. Look for any Skeleton asset inside the sibling  ../Skeletons/  folder
     relative to the ABP's engine package folder.
     e.g.  ABP at  /Game/Characters/CN_020/Animations/ABP_CN_020_00
           checks   /Game/Characters/CN_020/Skeletons/
  2. If no skeleton is found there, fall back to the shared human skeleton:
       /Game/Characters/Commons/Skeletons/SK_Human_Skeleton

If an asset already exists at the target engine path, its on-disk .uasset file
is removed first so create_asset can write a fresh stub in its place.

Usage — JJK ModKit menu → Asset Tools → Stub ABP From Folder…
     or UE Python console:
         import importlib, stub_abp_from_folder
         importlib.reload(stub_abp_from_folder)
         stub_abp_from_folder.pick_and_run()
"""

import os
import re
import unreal


# ─── Configuration ─────────────────────────────────────────────────────────────

# Used when no skeleton is found in the sibling Skeletons/ folder.
FALLBACK_SKELETON_PATH = '/Game/Characters/Commons/Skeletons/SK_Human_Skeleton'

# Matches  ABP_*.uasset  and  *_ABP.uasset  (case-insensitive).
_ABP_PATTERN = re.compile(r'^(?:ABP_.+|.+_ABP)\.uasset$', re.IGNORECASE)


# ─── Helpers ───────────────────────────────────────────────────────────────────

def _get_content_dir() -> str:
    """Return the absolute path to the project Content directory, no trailing slash."""
    raw = unreal.Paths.convert_relative_path_to_full(unreal.Paths.project_content_dir())
    return raw.replace('\\', '/').rstrip('/')


def _pick_folder() -> 'str | None':
    """
    Show a native folder-picker dialog (tkinter askdirectory).
    Returns the selected absolute path, or None if the user cancelled.
    """
    import tkinter as tk
    from tkinter import filedialog

    root = tk.Tk()
    root.withdraw()
    root.attributes('-topmost', True)
    folder = filedialog.askdirectory(
        title='Select source folder — ABP stubs will be created under /Game/ '
              'mirroring this folder\'s hierarchy',
        parent=root,
    )
    root.destroy()
    return folder.replace('\\', '/') if folder else None


def _source_to_engine(abs_path: str, source_root: str) -> 'tuple[str, str]':
    """
    Convert an absolute source disk path to (package_path, asset_name).

    The chosen *source_root* is treated as the Content/ mount point, so the
    relative sub-path is mapped directly under /Game/.

    Example
    -------
    abs_path    : C:/JJK/Content/Characters/CN_020/Animations/ABP_CN_020_00.uasset
    source_root : C:/JJK/Content
    result      : ('/Game/Characters/CN_020/Animations', 'ABP_CN_020_00')
    """
    source_root  = source_root.replace('\\', '/').rstrip('/')
    abs_path     = abs_path.replace('\\', '/')
    rel          = abs_path[len(source_root):].lstrip('/')   # e.g. Characters/CN_020/.../ABP_foo.uasset
    parts        = rel.split('/')
    asset_name   = parts[-1][:-7]                             # strip .uasset
    package_path = '/Game/' + '/'.join(parts[:-1])
    return package_path, asset_name


def _resolve_skeleton(package_path: str) -> 'unreal.Skeleton | None':
    """
    Find the best Skeleton for an ABP whose package folder is *package_path*.

    Resolution order
    ----------------
    1. Any Skeleton asset found in  <parent of package_path>/Skeletons/
       e.g.  /Game/Characters/CN_020/Animations  →  /Game/Characters/CN_020/Skeletons
    2. FALLBACK_SKELETON_PATH  (/Game/Characters/Commons/Skeletons/SK_Human_Skeleton)

    Returns a loaded unreal.Skeleton, or None if even the fallback is missing.
    """
    # Navigate one level up from the ABP's folder to find a sibling Skeletons/ dir.
    parent_folder = '/'.join(package_path.rstrip('/').split('/')[:-1])
    skel_folder   = f'{parent_folder}/Skeletons'

    candidates = unreal.EditorAssetLibrary.list_assets(
        skel_folder, recursive=False, include_folder=False
    )
    for asset_ref in sorted(candidates):          # deterministic order
        asset = unreal.load_asset(asset_ref)
        if isinstance(asset, unreal.Skeleton):
            unreal.log(f'[StubABPFromFolder]   Skeleton: {asset_ref}')
            return asset

    # Nothing in the sibling folder — use the shared human skeleton.
    unreal.log(
        f'[StubABPFromFolder]   No skeleton found in "{skel_folder}" '
        f'— falling back to {FALLBACK_SKELETON_PATH}'
    )
    fallback = unreal.load_asset(FALLBACK_SKELETON_PATH)
    if fallback is None:
        unreal.log_error(
            f'[StubABPFromFolder]   Fallback skeleton not found: "{FALLBACK_SKELETON_PATH}". '
            'Ensure the asset exists before running this tool.'
        )
    return fallback


def _find_abp_files(folder: str) -> list:
    """
    Recursively find all ABP_*.uasset / *_ABP.uasset files under *folder*.
    Returns a sorted list of absolute paths (forward-slashes).
    """
    found = []
    for root, _dirs, files in os.walk(folder):
        for fname in files:
            if _ABP_PATTERN.match(fname):
                found.append(os.path.join(root, fname).replace('\\', '/'))
    found.sort()
    return found


# ─── Main ──────────────────────────────────────────────────────────────────────

def run(source_folder: str) -> None:
    """
    Create ABP stubs for every ABP_*.uasset / *_ABP.uasset found under
    *source_folder*, placing each stub at the matching /Game/... engine path.

    The *source_folder* is treated as the Content/ root for path mapping:
    the relative structure beneath it is reproduced verbatim under /Game/.

    Parameters
    ----------
    source_folder : str
        Absolute path to the folder to scan (cooked Content/ root or any
        subfolder you want to treat as the hierarchy origin).
    """
    source_folder = source_folder.replace('\\', '/').rstrip('/')
    content_dir   = _get_content_dir()
    asset_tools   = unreal.AssetToolsHelpers.get_asset_tools()

    abp_files = _find_abp_files(source_folder)
    unreal.log(f'[StubABPFromFolder] Source folder : {source_folder}')
    unreal.log(f'[StubABPFromFolder] ABPs found    : {len(abp_files)}')

    if not abp_files:
        unreal.log('[StubABPFromFolder] No ABP assets found — nothing to do.')
        return

    ok = fail = 0

    with unreal.ScopedSlowTask(len(abp_files), 'Creating ABP stubs…') as slow:
        slow.make_dialog(True)

        for disk_path in abp_files:
            if slow.should_cancel():
                unreal.log_warning('[StubABPFromFolder] Cancelled by user.')
                break

            fname = disk_path.split('/')[-1]
            slow.enter_progress_frame(1, fname)

            package_path, asset_name = _source_to_engine(disk_path, source_folder)
            engine_path = f'{package_path}/{asset_name}'
            unreal.log(f'[StubABPFromFolder] Processing {engine_path}')

            # ── Resolve skeleton ───────────────────────────────────────────
            skeleton = _resolve_skeleton(package_path)
            if skeleton is None:
                unreal.log_error(
                    f'[StubABPFromFolder]   No skeleton available — skipping {engine_path}'
                )
                fail += 1
                continue

            # ── Remove existing .uasset on disk (if any) ───────────────────
            # package_path is like /Game/Characters/CN_020/Animations
            # strip the leading /Game to get the relative content sub-path
            rel_package = package_path[len('/Game'):].lstrip('/')
            disk_out    = f'{content_dir}/{rel_package}/{asset_name}.uasset'

            if os.path.exists(disk_out):
                try:
                    os.remove(disk_out)
                    unreal.log(f'[StubABPFromFolder]   Removed stale file: {disk_out}')
                except OSError as exc:
                    unreal.log_warning(
                        f'[StubABPFromFolder]   Cannot remove "{disk_out}": {exc}'
                    )
                    fail += 1
                    continue

            # ── Create the stub AnimBlueprint ──────────────────────────────
            factory = unreal.AnimBlueprintFactory()
            factory.set_editor_property('target_skeleton', skeleton)
            factory.set_editor_property('parent_class', unreal.AnimInstance)

            stub = asset_tools.create_asset(
                asset_name   = asset_name,
                package_path = package_path,
                asset_class  = unreal.AnimBlueprint,
                factory      = factory,
            )

            if stub is None:
                unreal.log_error(
                    f'[StubABPFromFolder]   create_asset returned None for {engine_path}'
                )
                fail += 1
                continue

            unreal.EditorAssetLibrary.save_asset(engine_path, only_if_is_dirty=False)
            unreal.log(f'[StubABPFromFolder]   ✓ {engine_path}  (skeleton: {skeleton.get_name()})')
            ok += 1

    unreal.log(
        f'[StubABPFromFolder] ━━━ Complete ━━━  '
        f'created: {ok}, failed: {fail}'
    )


# ─── Menu entry point ──────────────────────────────────────────────────────────

def pick_and_run() -> None:
    """
    Show a folder-picker dialog and run the ABP stubber on the chosen folder.
    Called by the JJK ModKit menu entry.
    """
    folder = _pick_folder()
    if folder is None:
        unreal.log('[StubABPFromFolder] Folder selection cancelled — nothing done.')
        return
    run(folder)

"""
mod_tools.py — JujutsuKaisenCC Mod Toolkit
===========================================
Cook and stage UE5 mod assets for Jujutsu Kaisen Cursed Clash.

Usage (standalone CLI):
    python Content/Python/mod_tools.py list
    python Content/Python/mod_tools.py cook [ModName]   — omit ModName to cook all
    python Content/Python/mod_tools.py export <ModName>
    python Content/Python/mod_tools.py export-all
    python Content/Python/mod_tools.py stage <ModName>
"""

from __future__ import annotations   # allows X | Y union hints on Python 3.9 (UE5.1)

import sys
import shutil
import subprocess
from pathlib import Path

# ─── Extra cook flags (appended to every cook command) ───────────────────────
#
# The core flags (-run=Cook, -TargetPlatform, -CookDir, -Unversioned,
# -NoLogTimes, -NoSplash, -Unattended, -NullRHI, -stdout) are fixed inside
# cook().  Add *optional* overrides here when needed.
_MOD_COOK_FLAGS: list[str] = []

# ─── Paths ───────────────────────────────────────────────────────────────────

def _get_project_root() -> Path:
    """Return the project root by walking up from this file until a .uproject is found."""
    candidate = Path(__file__).resolve().parent
    for _ in range(10):
        if any(candidate.glob("*.uproject")):
            return candidate
        candidate = candidate.parent
    raise RuntimeError("Could not locate project root (.uproject not found).")


def _get_project_file() -> Path:
    root = _get_project_root()
    matches = list(root.glob("*.uproject"))
    if not matches:
        raise RuntimeError(f"No .uproject file found in {root}")
    return matches[0]


def _get_cooked_dir() -> Path:
    root = _get_project_root()
    project_name = _get_project_file().stem   # e.g. "JujutsuKaisenCC"
    return root / "Saved" / "Cooked" / "Windows" / project_name


def _get_content_mods_dir() -> Path:
    return _get_project_root() / "Content" / "Mods"


def _find_ue_editor_cmd() -> Path:
    """Try to locate UnrealEditor-Cmd.exe in well-known Epic install paths."""
    candidates = [
        Path("C:/Program Files/Epic Games/UE_5.1/Engine/Binaries/Win64/UnrealEditor-Cmd.exe"),
        Path("C:/Program Files/Epic Games/UE_5.2/Engine/Binaries/Win64/UnrealEditor-Cmd.exe"),
        Path("C:/Program Files/Epic Games/UE_5.3/Engine/Binaries/Win64/UnrealEditor-Cmd.exe"),
    ]
    for p in candidates:
        if p.exists():
            return p
    raise RuntimeError(
        "Could not find UnrealEditor-Cmd.exe. "
        "Set 'UnrealEditor-Cmd Path' in Edit → Project Settings → Plugins → JJK Mod Kit."
    )


# ─── Config (CDO only) ───────────────────────────────────────────────────────

def _get_settings_cdo():
    """
    Return the UJJKModKitSettings CDO, or None if not running inside the editor.

    Settings live in Edit → Project Settings → Plugins → JJK Mod Kit and are
    persisted to Config/DefaultGame.ini by UE automatically.
    """
    try:
        import unreal
        return unreal.JJKModKitSettings.get_default_object()
    except Exception:
        return None


def load_config() -> dict:
    """
    Return the current ModKit settings as a plain dict by reading the
    UJJKModKitSettings CDO.

    Keys returned:
      game_exe_path      — str  (GameExePath.FilePath UPROPERTY)
                           The path to Jujutsu Kaisen CC.exe.
                           The mods folder is derived automatically as:
                             <exe folder>/../../Content/Mods
      ue_editor_cmd_path — str  (UeEditorCmdPath UPROPERTY)

    Returns an empty dict when called outside the Unreal Editor (CDO unavailable).
    """
    cdo = _get_settings_cdo()
    if cdo is None:
        return {}
    try:
        exe_path = str(cdo.game_exe_path.file_path).strip()
    except Exception:
        exe_path = ""
    return {
        "game_exe_path":      exe_path,
        "ue_editor_cmd_path": str(cdo.ue_editor_cmd_path).strip(),
    }


def save_config(config: dict) -> None:
    """
    Write *config* values to the UJJKModKitSettings CDO.

    Recognised keys:
      game_exe_path      → sets GameExePath.FilePath  (path to the game .exe)
      ue_editor_cmd_path → sets UeEditorCmdPath

    Changes are applied to the CDO immediately.  UE persists them to
    Config/DefaultGame.ini when the editor saves or closes.

    Note: this function has no effect when called outside the Unreal Editor.
    """
    cdo = _get_settings_cdo()
    if cdo is None:
        print(
            "[JJK ModKit] save_config: UJJKModKitSettings CDO not available. "
            "Use Edit → Project Settings → Plugins → JJK Mod Kit to change settings."
        )
        return

    if "game_exe_path" in config:
        try:
            import unreal
            fp = unreal.FilePath()
            fp.file_path = str(config["game_exe_path"])
            cdo.set_editor_property("game_exe_path", fp)
        except Exception as e:
            print(f"[JJK ModKit] save_config: could not set game_exe_path: {e}")

    if "ue_editor_cmd_path" in config:
        cdo.set_editor_property("ue_editor_cmd_path", str(config["ue_editor_cmd_path"]))

    try:
        import unreal
        unreal.log("[JJK ModKit] Settings updated on CDO.")
    except Exception:
        pass


def _get_game_mods_path() -> Path:
    """
    Derive the game's Content/Mods path from the GameExePath CDO setting.

    The exe is expected at:
        <GameRoot>/Binaries/Win64/Jujutsu Kaisen CC.exe

    So the mods path is:
        <GameRoot>/Content/Mods
        = <exe folder>/../../Content/Mods

    Falls back to the default Steam install path when the CDO is unavailable
    or the exe path is blank.
    """
    cdo = _get_settings_cdo()
    if cdo is not None:
        try:
            val = str(cdo.game_exe_path.file_path).strip()
        except Exception:
            val = ""
        if val:
            exe_path = Path(val)
            # Win64/ → Binaries/ → GameRoot/  then  Content/Mods
            game_root = exe_path.parent.parent.parent
            return (game_root / "Content" / "Mods").resolve()
    # Fallback default
    return Path(
        r"C:\Program Files (x86)\Steam\steamapps\common"
        r"\Jujutsu Kaisen CC\Jujutsu Kaisen CC\Content\Mods"
    )


def _get_ue_editor_cmd() -> Path:
    """Read UeEditorCmdPath from the UJJKModKitSettings CDO, auto-detect if blank."""
    cdo = _get_settings_cdo()
    if cdo is not None:
        val = str(cdo.ue_editor_cmd_path).strip()
        if val:
            return Path(val)
    return _find_ue_editor_cmd()


# ─── Logging ─────────────────────────────────────────────────────────────────

def _log(msg: str) -> None:
    print(msg)


def _log_error(msg: str) -> None:
    print(f"ERROR: {msg}", file=sys.stderr)


# ─── Public API ──────────────────────────────────────────────────────────────

def open_settings_dialog() -> None:
    """Open the JJK Mod Kit Settings dialog."""
    import importlib
    import settings_dialog
    importlib.reload(settings_dialog)
    settings_dialog.show()


def open_new_mod_dialog() -> bool:
    """
    Open the New Mod creation dialog (UE5 GUI).

    Lets the user fill in a mod manifest (title, description, version, priority),
    then creates the folder under Content/Mods/ and writes manifest.json.

    Returns True if a mod was created, False if the dialog was cancelled.
    """
    import importlib
    import new_mod_dialog
    importlib.reload(new_mod_dialog)
    return new_mod_dialog.show_create_dialog()


def open_edit_manifest_dialog(mod_folder_path: str = "") -> bool:
    """
    Open the Edit Mod Manifest dialog for an existing mod (UE5 GUI).

    Parameters
    ----------
    mod_folder_path : str
        Either a filesystem path or a UE content-browser path
        (e.g. '/Game/Mods/My_Mod').  When blank a Content/Mods picker
        is shown so the user can choose which mod to edit.

    Returns True if the manifest was saved, False if cancelled.
    """
    import importlib
    import new_mod_dialog
    importlib.reload(new_mod_dialog)

    if not mod_folder_path or not str(mod_folder_path).strip():
        # No path supplied — let the user pick a mod from Content/Mods/
        mods_dir = _get_content_mods_dir()
        if not mods_dir.exists():
            _log_error("open_edit_manifest_dialog: Content/Mods/ does not exist yet.")
            return False

        mod_names = [d.name for d in sorted(mods_dir.iterdir()) if d.is_dir()]
        if not mod_names:
            _log_error("open_edit_manifest_dialog: No mods found under Content/Mods/.")
            return False

        if len(mod_names) == 1:
            mod_folder_path = str(mods_dir / mod_names[0])
        else:
            action, chosen = new_mod_dialog.show_mod_picker(mod_names)
            if action is None or not chosen:
                return False
            if action == "delete":
                return new_mod_dialog.delete_mod(chosen)
            # action == "edit"
            mod_folder_path = str(mods_dir / chosen)

    return new_mod_dialog.show_edit_dialog(mod_folder_path)


# ─── ORIGINAL_ tag batch operations ──────────────────────────────────────────

def _find_original_assets() -> list:
    """Return a list of AssetData objects whose name starts with 'ORIGINAL_'."""
    try:
        import unreal
        ar = unreal.AssetRegistry.get()
        ar_filter = unreal.ARFilter(
            package_paths=["/Game"],
            recursive_paths=True,
        )
        all_assets = ar.get_assets(ar_filter)
        return [a for a in all_assets if str(a.asset_name).startswith("ORIGINAL_")]
    except Exception as e:
        _log_error(f"_find_original_assets: {e}")
        return []


def delete_all_original_assets() -> None:
    """
    Find every asset whose name starts with 'ORIGINAL_' under /Game and delete
    them all after a UE GUI confirmation dialog.
    """
    try:
        import unreal
    except ImportError:
        _log_error("delete_all_original_assets must be called inside the Unreal Editor.")
        return

    originals = _find_original_assets()
    if not originals:
        unreal.EditorDialog.show_message(
            title="Delete ORIGINAL_ Assets",
            message="No assets with the 'ORIGINAL_' prefix were found.",
            message_type=unreal.AppMsgType.OK,
            default_value=unreal.AppReturnType.OK,
        )
        return

    preview_names = [str(a.asset_name) for a in originals]
    preview = "\n".join(preview_names[:20])
    if len(preview_names) > 20:
        preview += f"\n… and {len(preview_names) - 20} more"

    result = unreal.EditorDialog.show_message(
        title="Delete ORIGINAL_ Assets",
        message=(
            f"This will permanently delete {len(originals)} asset(s) "
            f"whose name starts with 'ORIGINAL_':\n\n{preview}\n\nContinue?"
        ),
        message_type=unreal.AppMsgType.YES_NO,
        default_value=unreal.AppReturnType.NO,
    )
    if result != unreal.AppReturnType.YES:
        unreal.log("[JJK Mod Kit] Delete ORIGINAL_ assets — cancelled.")
        return

    deleted = 0
    for asset_data in originals:
        pkg_path = str(asset_data.package_name)
        if unreal.EditorAssetLibrary.delete_asset(pkg_path):
            unreal.log(f"[JJK Mod Kit] Deleted  {pkg_path}")
            deleted += 1
        else:
            unreal.log_warning(f"[JJK Mod Kit] Failed to delete  {pkg_path}")

    unreal.EditorDialog.show_message(
        title="Delete ORIGINAL_ Assets",
        message=f"Done. Deleted {deleted} / {len(originals)} asset(s).",
        message_type=unreal.AppMsgType.OK,
        default_value=unreal.AppReturnType.OK,
    )


def restore_all_original_assets() -> None:
    """
    Find every asset whose name starts with 'ORIGINAL_', strip the prefix and
    rename it.  If an asset with the stripped name already exists it is deleted
    first, then the rename proceeds.

    A UE GUI confirmation dialog is shown before any changes are made.
    """
    try:
        import unreal
    except ImportError:
        _log_error("restore_all_original_assets must be called inside the Unreal Editor.")
        return

    originals = _find_original_assets()
    if not originals:
        unreal.EditorDialog.show_message(
            title="Restore ORIGINAL_ Assets",
            message="No assets with the 'ORIGINAL_' prefix were found.",
            message_type=unreal.AppMsgType.OK,
            default_value=unreal.AppReturnType.OK,
        )
        return

    preview_names = [str(a.asset_name) for a in originals]
    preview = "\n".join(preview_names[:20])
    if len(preview_names) > 20:
        preview += f"\n… and {len(preview_names) - 20} more"

    result = unreal.EditorDialog.show_message(
        title="Restore ORIGINAL_ Assets",
        message=(
            f"This will rename {len(originals)} asset(s) by removing the 'ORIGINAL_' prefix.\n"
            "If a target name already exists it will be deleted first.\n\n"
            f"{preview}\n\nContinue?"
        ),
        message_type=unreal.AppMsgType.YES_NO,
        default_value=unreal.AppReturnType.NO,
    )
    if result != unreal.AppReturnType.YES:
        unreal.log("[JJK Mod Kit] Restore ORIGINAL_ assets — cancelled.")
        return

    renamed = 0
    for asset_data in originals:
        pkg_path = str(asset_data.package_name)   # e.g. /Game/Foo/ORIGINAL_Bar
        folder   = "/".join(pkg_path.split("/")[:-1])
        old_name = pkg_path.split("/")[-1]         # ORIGINAL_Bar

        if not old_name.startswith("ORIGINAL_"):
            continue

        new_name = old_name[len("ORIGINAL_"):]
        new_path = f"{folder}/{new_name}"

        # Delete the existing non-prefixed asset if it is already there
        if unreal.EditorAssetLibrary.does_asset_exist(new_path):
            unreal.log(f"[JJK Mod Kit] Deleting existing  {new_path}")
            unreal.EditorAssetLibrary.delete_asset(new_path)

        ok = unreal.EditorAssetLibrary.rename_asset(pkg_path, new_path)
        if ok:
            unreal.log(f"[JJK Mod Kit] Renamed  {pkg_path}  →  {new_path}")
            renamed += 1
        else:
            unreal.log_warning(f"[JJK Mod Kit] Failed to rename  {pkg_path}  →  {new_path}")

    unreal.EditorDialog.show_message(
        title="Restore ORIGINAL_ Assets",
        message=f"Done. Renamed {renamed} / {len(originals)} asset(s).",
        message_type=unreal.AppMsgType.OK,
        default_value=unreal.AppReturnType.OK,
    )


def list_mods() -> list:
    """Return a list of mod names found under Content/Mods/."""
    mods_dir = _get_content_mods_dir()
    if not mods_dir.exists():
        return []
    mods = [d.name for d in sorted(mods_dir.iterdir()) if d.is_dir()]
    _log(f"Available mods: {mods if mods else '(none)'}")
    return mods


# ─── Core cook ───────────────────────────────────────────────────────────────

def cook(folder: str = "/Game/Mods") -> int:
    """
    Cook assets under *folder* using the UE5 Cook commandlet.

    Replicates cook.bat exactly:

        UnrealEditor-Cmd.exe <project> \\
            -run=Cook -TargetPlatform=Windows \\
            -CookDir=<folder> \\
            -Unversioned -NoLogTimes -NoSplash -Unattended -NullRHI -stdout

    Output is streamed to the console line-by-line and simultaneously written
    to  <project>/log.txt  (the same destination as cook.bat's  > log.txt).

    Parameters
    ----------
    folder : str
        UE content path to cook.
        ``"/Game/Mods"``          → cook every mod in Content/Mods/
        ``"/Game/Mods/MyMod"``   → cook only the MyMod subfolder

    Returns 0 on success, non-zero on failure.
    """
    try:
        ue_cmd       = _get_ue_editor_cmd()
        project_file = _get_project_file()
        project_root = _get_project_root()
    except RuntimeError as e:
        _log_error(str(e))
        return 1

    log_file = project_root / "log.txt"

    cmd = [
        str(ue_cmd),
        str(project_file),
        "-run=Cook",
        "-TargetPlatform=Windows",
        f"-CookDir={folder}",
        "-Unversioned",
        "-NoLogTimes",
        "-NoSplash",
        "-Unattended",
        "-NullRHI",
        "-stdout",
    ] + _MOD_COOK_FLAGS

    _log(f"=== Cooking: {folder} ===")
    _log("Command: " + " ".join(f'"{a}"' if " " in a else a for a in cmd))
    _log(f"Log → {log_file}")

    with open(log_file, "w", encoding="utf-8") as log_f:
        proc = subprocess.Popen(
            cmd,
            cwd=str(project_root),
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
        )
        for line in proc.stdout:
            stripped = line.rstrip()
            if stripped:
                print(f"[JJK Cook] {stripped}")
            log_f.write(line)
        proc.wait()
        rc = proc.returncode

    if rc == 0:
        _log(f"Cook succeeded.  Output: {_get_cooked_dir() / 'Content'}")
    elif rc == 1:
        # Exit code 1 = cook completed but non-fatal errors were logged
        # (e.g. a handled ensure from a missing plugin such as CRI Ware).
        # Assets are still produced; callers treat this as a soft success.
        _log(f"Cook finished with warnings (exit code 1).  Check {log_file} for details.")
    else:
        _log_error(f"Cook failed (exit code {rc}).  See {log_file}")
    return rc


# ─── Stage helpers ───────────────────────────────────────────────────────────

def _stage(cooked_mod_dir: Path, dest: Path, mod_name: str) -> int:
    """Copy files from *cooked_mod_dir* into *dest*, return file count or -1 on error."""
    if not cooked_mod_dir.exists():
        _log_error(
            f"No cooked output found for '{mod_name}'.\n"
            f"Expected: {cooked_mod_dir}\n"
            f"Run  cook()  first."
        )
        return -1

    dest.mkdir(parents=True, exist_ok=True)
    count = 0
    for src in sorted(cooked_mod_dir.rglob("*")):
        if src.is_file():
            rel = src.relative_to(cooked_mod_dir)
            dst = dest / rel
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src, dst)
            count += 1
    return count


def stage_mod(mod_name: str) -> int:
    """
    Copy cooked assets for *mod_name* to the game's mods folder.

    Destination:
        <game_mods_path>/<mod_name>/assets/Jujutsu Kaisen CC/<cooked files>

    The game_mods_path is derived from GameExePath:
        <exe folder>/../../Content/Mods

    Returns 0 on success, non-zero on failure.
    """
    if not mod_name or not mod_name.strip():
        _log_error("stage_mod: mod_name must not be empty.")
        return 1

    mod_name       = mod_name.strip()
    cooked_mod_dir = _get_cooked_dir() / "Content" / "Mods" / mod_name
    dest           = _get_game_mods_path() / mod_name / "assets" / "Jujutsu Kaisen CC"

    _log(f"=== Staging mod: {mod_name} ===")
    _log(f"  Source : {cooked_mod_dir}")
    _log(f"  Dest   : {dest}")

    count = _stage(cooked_mod_dir, dest, mod_name)
    if count < 0:
        return 1
    _log(f"Staged {count} file(s) to {dest}")
    return 0


def stage_mod_to_mods_path(mod_name: str) -> int:
    """
    Copy cooked assets for *mod_name* using the flat layout:
        <game_mods_path>/<mod_name>/assets/<relative_path>

    The game_mods_path is derived from GameExePath:
        <exe folder>/../../Content/Mods

    Returns 0 on success, non-zero on failure.
    """
    if not mod_name or not mod_name.strip():
        _log_error("stage_mod_to_mods_path: mod_name must not be empty.")
        return 1

    mod_name       = mod_name.strip()
    cooked_mod_dir = _get_cooked_dir() / "Content" / "Mods" / mod_name
    dest           = _get_game_mods_path() / mod_name / "assets"

    _log(f"=== Staging mod: {mod_name} ===")
    _log(f"  Source : {cooked_mod_dir}")
    _log(f"  Dest   : {dest}")

    count = _stage(cooked_mod_dir, dest, mod_name)
    if count < 0:
        return 1
    _log(f"Staged {count} file(s) to {dest}")
    return 0


# ─── Async notification helper ───────────────────────────────────────────────

def _jjk_notify(text: str, success: bool | None = None) -> None:
    """
    Emit *text* to the output log and, when inside the Unreal Editor,
    attempt to post a toast notification via EditorNotificationHelper.

    Parameters
    ----------
    success : bool | None
        None  → informational / in-progress (log only, no toast)
        True  → success toast  (green ✓)
        False → failure toast  (red  ✗)
    """
    try:
        import unreal
        if success is False:
            unreal.log_error(text)
        else:
            unreal.log(text)

        if success is not None:
            try:
                unreal.EditorNotificationHelper.add_notification_item(text, success)
            except Exception:
                pass   # API not exposed in this UE build — log is enough
    except ImportError:
        # Outside the editor
        if success is False:
            print(f"ERROR: {text}", file=sys.stderr)
        else:
            print(text)


# ─── Shared async-cook state ─────────────────────────────────────────────────
#
# A single module-level dict is used so that both the worker thread and the
# Slate tick callback (game thread) can read/write it without extra locking.
# CPython's GIL guarantees that individual dict item reads/writes are atomic.

_async_cook_state: dict = {
    "running":     False,   # True while the worker thread is alive
    "result":      None,    # True=success, False=failure, None=not yet done
    "message":     "",      # Human-readable outcome description
    "tick_handle": None,    # Handle returned by register_slate_post_tick_callback
}


# ─── Asset Registry generation ───────────────────────────────────────────────

def _generate_mod_asset_registries(mods: list[str], game_mods_path: Path) -> None:
    """
    For each mod in *mods*, write an AssetRegistry.json into its staged assets
    folder by running:

        Tools/jjkue.exe registry print-rows --bin <cooked>/AssetRegistry.bin

    stdout  → JSON array of all registry rows  (filtered per-mod by content path)
    stderr  → stats line(s)                    (logged only)

    Output:
        <game_mods_path>/<mod_name>/assets/AssetRegistry.json
    """
    import json

    project_root       = _get_project_root()
    jjkue_exe          = project_root / "Tools" / "jjkue.exe"
    asset_registry_bin = _get_cooked_dir() / "AssetRegistry.bin"

    if not jjkue_exe.exists():
        _log_error(
            f"[JJK Registry] jjkue.exe not found at {jjkue_exe} "
            "— skipping AssetRegistry.json generation."
        )
        return

    if not asset_registry_bin.exists():
        _log_error(
            f"[JJK Registry] AssetRegistry.bin not found at {asset_registry_bin} "
            "— skipping AssetRegistry.json generation."
        )
        return

    _log(f"[JJK Registry] Parsing {asset_registry_bin} …")

    try:
        proc = subprocess.run(
            [
                str(jjkue_exe),
                "registry", "print-rows",
                "--bin", str(asset_registry_bin),
            ],
            cwd=str(jjkue_exe.parent),   # run from Tools/ so relative paths work
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
    except Exception as exc:
        _log_error(f"[JJK Registry] Failed to launch jjkue.exe: {exc}")
        return

    # stderr holds stats — log them for visibility
    if proc.stderr.strip():
        _log(f"[JJK Registry] {proc.stderr.strip()}")

    if proc.returncode != 0:
        _log_error(f"[JJK Registry] jjkue.exe exited with code {proc.returncode}.")
        return

    # Parse stdout as a JSON array (schema-agnostic)
    try:
        all_rows: list = json.loads(proc.stdout)
    except json.JSONDecodeError as exc:
        _log_error(f"[JJK Registry] Cannot parse jjkue.exe output as JSON: {exc}")
        return

    if not isinstance(all_rows, list):
        _log_error(
            f"[JJK Registry] Unexpected output type '{type(all_rows).__name__}' "
            "(expected a JSON array of rows)."
        )
        return

    # Write per-mod AssetRegistry.json, filtering rows by the mod's content path.
    # Serialise each row to a string so the filter works regardless of which
    # field(s) hold the package path.
    for mod_name in mods:
        mod_prefix = f"/Game/Mods/{mod_name}"
        mod_rows   = [
            row for row in all_rows
            if mod_prefix in json.dumps(row, ensure_ascii=False)
        ]

        dest = game_mods_path / mod_name / "AssetRegistry.json"
        dest.parent.mkdir(parents=True, exist_ok=True)

        with open(dest, "w", encoding="utf-8") as fh:
            json.dump(mod_rows, fh, indent=2, ensure_ascii=False)

        _log(f"[JJK Registry] ✓ {mod_name}: {len(mod_rows)} entries → {dest}")


# ─── Manifest copy helper ────────────────────────────────────────────────────

def _copy_manifest(mod_name: str, game_mods_path: Path) -> None:
    """
    Copy  Content/Mods/<mod_name>/manifest.json  →  <game_mods_path>/<mod_name>/manifest.json.

    Logs a warning (but does not abort) when the source file is missing.
    """
    src = _get_content_mods_dir() / mod_name / "manifest.json"
    if not src.exists():
        _log(f"[JJK Manifest] ⚠ manifest.json not found for '{mod_name}' ({src}) — skipping.")
        return

    dest = game_mods_path / mod_name / "manifest.json"
    dest.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dest)
    _log(f"[JJK Manifest] ✓ {mod_name}: manifest.json → {dest}")


# ─── Cook + Stage convenience wrappers ───────────────────────────────────────

def cook_and_stage_mod(mod_name: str) -> None:
    """
    Cook a single mod and stage it to <game_mods_path>/<mod_name>/assets/<path>.

    game_mods_path is derived from GameExePath:
        <exe folder>/../../Content/Mods

    Calls cook("/Game/Mods/<mod_name>") then copies the cooked output.
    """
    mod_name = (mod_name or "").strip()
    if not mod_name:
        _log_error("cook_and_stage_mod: mod_name must not be empty.")
        return

    source_dir = _get_content_mods_dir() / mod_name
    if not source_dir.exists():
        _log_error(f"Mod source folder not found: {source_dir}")
        return

    rc = cook(f"/Game/Mods/{mod_name}")
    if rc > 1:
        return

    game_mods_path = _get_game_mods_path()
    cooked_mod_dir = _get_cooked_dir() / "Content" / "Mods" / mod_name
    dest           = game_mods_path / mod_name / "assets"
    count          = _stage(cooked_mod_dir, dest, mod_name)
    if count >= 0:
        _log(f"✓ {mod_name}: staged {count} file(s) → {dest}")
        _copy_manifest(mod_name, game_mods_path)


def cook_and_stage_all_mods() -> None:
    """
    Cook ALL mods under Content/Mods/ then stage each one.

    Calls cook("/Game/Mods") for a single combined cook pass, then copies
    each mod's cooked output to <game_mods_path>/<mod_name>/assets/<path>.

    game_mods_path is derived from the GameExePath setting:
        <exe folder>/../../Content/Mods
    (Edit → Project Settings → Plugins → JJK Mod Kit → Game Exe Path)
    """
    mods = list_mods()
    if not mods:
        _log("[JJK Mod Kit] No mods found under Content/Mods/ — nothing to cook.")
        return

    rc = cook("/Game/Mods")
    if rc > 1:
        _log_error(f"Cook failed (exit {rc}) — aborting stage.")
        return

    game_mods_path = _get_game_mods_path()
    cooked_base    = _get_cooked_dir() / "Content" / "Mods"
    results: dict[str, str] = {}

    for mod_name in mods:
        cooked_mod_dir = cooked_base / mod_name
        dest           = game_mods_path / mod_name / "assets"
        count          = _stage(cooked_mod_dir, dest, mod_name)
        if count < 0:
            results[mod_name] = "SKIPPED (no cooked output)"
        else:
            _log(f"✓ {mod_name}: staged {count} file(s) → {dest}")
            _copy_manifest(mod_name, game_mods_path)
            results[mod_name] = "OK"

    _generate_mod_asset_registries(mods, game_mods_path)

    print("\n" + "=" * 60)
    print("[JJK Cook] Cook & Export All Mods — Summary:")
    for name, status in results.items():
        print(f"[JJK Cook]   {name}: {status}")
    print("=" * 60)


def cook_and_stage_all_mods_async() -> None:
    """
    Cook ALL mods under Content/Mods/ then stage each one — asynchronously.

    Equivalent to cook_and_stage_all_mods() but non-blocking:

      • Returns immediately so the editor stays fully responsive.
      • Shows a "started" notification in the output log.
      • Registers a per-frame Slate tick callback that fires on the game thread
        to detect when the worker finishes and post a success / failure
        notification (similar to the built-in engine cook notification).

    Only one cook can run at a time; a second call while cooking is in
    progress logs a warning and returns without starting a new process.
    """
    import threading

    state = _async_cook_state

    # ── Guard: reject concurrent cooks ───────────────────────────────────────
    if state["running"]:
        _jjk_notify(
            "[JJK Mod Kit] Cook & Export is already in progress — please wait.",
            None,
        )
        return

    mods = list_mods()
    if not mods:
        _jjk_notify(
            "[JJK Mod Kit] No mods found under Content/Mods/ — nothing to cook.",
            None,
        )
        return

    # ── Reset shared state ────────────────────────────────────────────────────
    state["running"] = True
    state["result"]  = None
    state["message"] = ""

    _jjk_notify(
        "[JJK Cook] ⏳ Cook & Export All Mods started — editor stays responsive. "
        "Check the Output Log for cook progress.",
        None,
    )

    # ── Worker thread ─────────────────────────────────────────────────────────
    # Runs entirely outside the game thread.  May call _log/_log_error (plain
    # print) but must NOT touch any unreal.* API — those calls are unsafe off
    # the game thread.
    def _worker() -> None:
        try:
            rc = cook("/Game/Mods")
            if rc > 1:
                state["result"]  = False
                state["message"] = (
                    f"Cook commandlet exited with code {rc}. "
                    f"See log.txt for details."
                )
                return

            game_mods_path = _get_game_mods_path()
            cooked_base    = _get_cooked_dir() / "Content" / "Mods"
            failed: list[str] = []

            for mod_name in mods:
                cooked_mod_dir = cooked_base / mod_name
                dest           = game_mods_path / mod_name / "assets"
                count          = _stage(cooked_mod_dir, dest, mod_name)
                if count < 0:
                    failed.append(mod_name)
                else:
                    _log(f"✓ {mod_name}: staged {count} file(s) → {dest}")
                    _copy_manifest(mod_name, game_mods_path)

            _generate_mod_asset_registries(mods, game_mods_path)

            if failed:
                state["result"]  = False
                state["message"] = (
                    f"Cook succeeded but staging failed for: {', '.join(failed)}"
                )
            else:
                state["result"]  = True
                state["message"] = (
                    f"Cooked & exported {len(mods)} "
                    f"mod{'s' if len(mods) != 1 else ''} to {game_mods_path}"
                )

        except Exception as exc:
            import traceback
            state["result"]  = False
            state["message"] = f"Unexpected error: {exc}\n{traceback.format_exc()}"
        finally:
            # Set running=False LAST so the tick callback only reads 'result'
            # after it is guaranteed to be populated.
            state["running"] = False

    threading.Thread(target=_worker, daemon=True, name="JJKCookThread").start()

    # ── Slate tick callback (game thread) — posts the result notification ─────
    # register_slate_post_tick_callback fires every frame on the game thread.
    # We poll the shared state dict and unregister as soon as the worker exits.
    try:
        import unreal

        def _on_tick(delta_seconds: float) -> None:  # noqa: ARG001
            if state["running"]:
                return  # Worker still alive — check again next frame

            # ── Unregister this callback immediately ──────────────────────────
            handle = state.get("tick_handle")
            if handle is not None:
                try:
                    unreal.unregister_slate_post_tick_callback(handle)
                except Exception:
                    pass
                state["tick_handle"] = None

            result  = state["result"]
            message = state["message"]
            state["result"] = None   # Prevent accidental double-fire

            if result is True:
                _jjk_notify(
                    f"[JJK Cook] ✅ Cook & Export All Mods — {message}",
                    True,
                )
            elif result is False:
                _jjk_notify(
                    f"[JJK Cook] ❌ Cook & Export All Mods — {message}",
                    False,
                )
            # result is None only if worker never set it (crash before assignment)
            # → nothing to report; cook output log will contain the details.

        state["tick_handle"] = unreal.register_slate_post_tick_callback(_on_tick)

    except ImportError:
        # Running outside the Unreal Editor (e.g. standalone CLI test) —
        # the background thread will still complete; caller sees log output.
        pass


# ─── CLI entry point ─────────────────────────────────────────────────────────

if __name__ == "__main__":
    _USAGE = (
        "Usage:\n"
        "  mod_tools.py list\n"
        "  mod_tools.py cook   [ModName]  — cook a single mod, or all if omitted\n"
        "  mod_tools.py export <ModName>  — cook + stage a single mod\n"
        "  mod_tools.py export-all        — cook + stage every mod in Content/Mods/\n"
        "  mod_tools.py stage  <ModName>  — stage already-cooked mod (legacy layout)\n"
        "  mod_tools.py stage-simple <ModName>\n"
        "  mod_tools.py config <key> <value>  — e.g. config game_exe_path 'C:/path/to/Jujutsu Kaisen CC.exe'\n"
    )

    args = sys.argv[1:]
    if not args:
        print(_USAGE)
        sys.exit(0)

    action = args[0].lower()

    if action == "list":
        list_mods()

    elif action == "cook":
        folder = f"/Game/Mods/{args[1]}" if len(args) > 1 else "/Game/Mods"
        sys.exit(cook(folder))

    elif action == "export":
        if len(args) < 2:
            print("Usage: mod_tools.py export <ModName>")
            sys.exit(1)
        cook_and_stage_mod(args[1])

    elif action == "export-all":
        cook_and_stage_all_mods()

    elif action == "stage":
        if len(args) < 2:
            print("Usage: mod_tools.py stage <ModName>")
            sys.exit(1)
        sys.exit(stage_mod(args[1]))

    elif action == "stage-simple":
        if len(args) < 2:
            print("Usage: mod_tools.py stage-simple <ModName>")
            sys.exit(1)
        sys.exit(stage_mod_to_mods_path(args[1]))

    elif action == "config":
        if len(args) < 3:
            print("Usage: mod_tools.py config <key> <value>")
            sys.exit(1)
        save_config({args[1]: args[2]})

    else:
        print(f"Unknown action: {action}\n{_USAGE}")
        sys.exit(1)

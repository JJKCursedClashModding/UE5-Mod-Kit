"""
new_mod_dialog.py — JJK Mod Kit
================================
Dialog layer for creating new mods and editing existing mod manifests.

All UI is provided by the native C++ Slate dialog in ModKitDialogLibrary
(unreal.ModKitDialogLibrary).  Recompile the JJKModKit plugin if any function
here reports that the library is not available.

Public API
----------
show_create_dialog()                 — open the "New Mod" creation dialog
show_edit_dialog(mod_folder_path)    — open the "Edit Manifest" dialog for an existing mod
show_mod_picker(mod_names)           — listbox picker; returns chosen name or None
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path


# ─── Helpers ─────────────────────────────────────────────────────────────────

def _get_mods_dir() -> Path:
    """Return <project>/Content/Mods, walking up from this file to find the .uproject."""
    candidate = Path(__file__).resolve().parent
    for _ in range(10):
        if any(candidate.glob("*.uproject")):
            return candidate / "Content" / "Mods"
        candidate = candidate.parent
    raise RuntimeError("Cannot locate project root (.uproject not found).")


def _title_to_folder_name(title: str) -> str:
    """
    Convert a human-readable title to a safe folder name.

    Rules
    -----
    * Runs of whitespace               → single underscore
    * Characters outside [A-Za-z0-9_-] → removed
    * Leading/trailing underscores     → stripped
    * Empty result                     → "New_Mod"
    """
    name = re.sub(r"[^\w\s\-]", "", title)
    name = re.sub(r"\s+", "_", name.strip())
    name = name.strip("_")
    return name or "New_Mod"


def _read_manifest(manifest_path: Path) -> dict:
    """Load manifest.json; return defaults on any error."""
    try:
        with open(manifest_path, "r", encoding="utf-8") as fh:
            return json.load(fh)
    except Exception:
        return {"title": "", "description": "", "version": "v1", "priority": 0}


def _write_manifest(manifest_path: Path, data: dict) -> None:
    """Write *data* to *manifest_path*, creating parent directories as needed."""
    manifest_path.parent.mkdir(parents=True, exist_ok=True)
    with open(manifest_path, "w", encoding="utf-8") as fh:
        json.dump(data, fh, indent="\t", ensure_ascii=False)
        fh.write("\n")


def _ue_refresh_content_browser(ue_path: str = "/Game/Mods") -> None:
    """Ask the UE Asset Registry to re-scan the mods folder (best-effort)."""
    try:
        import unreal
        registry = unreal.AssetRegistryHelpers.get_asset_registry()
        registry.scan_paths_synchronous([ue_path], force_rescan=True)
    except Exception:
        pass


def _ue_show_message(title: str, message: str, msg_type: str = "info") -> str:
    """
    Show a UE EditorDialog message box.

    Parameters
    ----------
    msg_type : "info" | "warning" | "error" | "yesno"

    Returns "ok", "yes", or "no".
    """
    try:
        import unreal
        if msg_type == "yesno":
            result = unreal.EditorDialog.show_message(
                title, message, unreal.AppMsgType.YES_NO
            )
            return "yes" if result == unreal.AppReturnType.YES else "no"
        else:
            unreal.EditorDialog.show_message(
                title, message, unreal.AppMsgType.OK
            )
            return "ok"
    except Exception:
        print(f"[{msg_type.upper()}] {title}: {message}")
        return "ok"


def _get_lib():
    """
    Return unreal.ModKitDialogLibrary, or raise RuntimeError if unavailable.
    Called at the start of every public function so errors are caught early
    with a clear message.
    """
    try:
        import unreal
    except ImportError:
        raise RuntimeError(
            "unreal module not available — this script must run inside the UE Editor."
        )
    lib = getattr(unreal, "ModKitDialogLibrary", None)
    if lib is None:
        raise RuntimeError(
            "unreal.ModKitDialogLibrary not found.\n"
            "Please recompile the JJKModKit plugin and restart the editor:\n"
            "  Tools → Refresh Visual Studio Project → Build"
        )
    return lib


# ─── Public API ──────────────────────────────────────────────────────────────

def show_create_dialog() -> bool:
    """
    Open the "New Mod" creation dialog (native UE Slate).

    On confirmation:
      1. Creates  <project>/Content/Mods/<folder_name>/
      2. Writes   manifest.json  inside that folder
      3. Triggers a UE Content Browser rescan

    Returns True if a mod was created, False if cancelled.
    """
    import unreal

    try:
        lib = _get_lib()
    except RuntimeError as exc:
        _log_error(str(exc))
        _ue_show_message("New Mod — Plugin Not Ready", str(exc), "error")
        return False

    init = unreal.ModManifestData()
    result = lib.show_mod_manifest_dialog(init, True)

    # UE Python strips the leading 'b' from bool property names before
    # Pythonizing, so bConfirmed → "confirmed".  Try both spellings so this
    # works regardless of engine version, and log available attrs if neither
    # is found (helps diagnose future renames).
    b_confirmed = getattr(result, "confirmed",   None)
    if b_confirmed is None:
        b_confirmed = getattr(result, "b_confirmed", None)
    if b_confirmed is None:
        _log_error(
            "[JJK Mod Kit] Cannot find 'confirmed'/'b_confirmed' on ModManifestData.\n"
            f"Available attributes: {[a for a in dir(result) if not a.startswith('_')]}"
        )
        return False
    if not b_confirmed:
        return False

    manifest_data = {
        "title":       str(result.title).strip(),
        "description": str(result.description).strip(),
        "version":     str(result.version).strip() or "v1",
        "priority":    int(result.priority),
    }
    folder_name = _title_to_folder_name(manifest_data["title"])

    try:
        mods_dir      = _get_mods_dir()
        mod_dir       = mods_dir / folder_name
        manifest_path = mod_dir / "manifest.json"

        if mod_dir.exists():
            reply = _ue_show_message(
                "Folder Already Exists",
                f"A mod folder named '{folder_name}' already exists.\n\n"
                "Do you want to overwrite its manifest?",
                "yesno",
            )
            if reply != "yes":
                return False

        _write_manifest(manifest_path, manifest_data)
        _ue_refresh_content_browser("/Game/Mods")

        _log(f"[JJK Mod Kit] Created mod '{manifest_data['title']}' → {mod_dir}")

        _ue_show_message(
            "Mod Created",
            f"Mod '{manifest_data['title']}' created successfully!\n\n"
            f"Folder:  {mod_dir}\n\n"
            "The folder is now visible in Content/Mods/ in the Content Browser.",
            "info",
        )
        return True

    except Exception as exc:
        _ue_show_message("Error Creating Mod", f"Failed to create mod:\n\n{exc}", "error")
        _log_error(f"[JJK Mod Kit] create mod error: {exc}")
        return False


def show_edit_dialog(mod_folder_path) -> bool:
    """
    Open the "Edit Manifest" dialog for an existing mod (native UE Slate).

    Parameters
    ----------
    mod_folder_path : str | Path
        Filesystem path to the mod's folder (containing manifest.json),
        OR a UE content-browser path like  '/Game/Mods/My_Mod'  which is
        automatically resolved to the project's Content directory.

    Returns True if the manifest was saved, False if cancelled.
    """
    import unreal

    try:
        lib = _get_lib()
    except RuntimeError as exc:
        _log_error(str(exc))
        _ue_show_message("Edit Manifest — Plugin Not Ready", str(exc), "error")
        return False

    # Resolve UE content path → filesystem path
    path_str = str(mod_folder_path)
    if path_str.startswith("/Game/") or path_str.startswith("/All/Game/"):
        relative = re.sub(r"^/(?:All/)?Game/", "", path_str.rstrip("/"))
        try:
            mod_dir = _get_mods_dir().parent / relative
        except RuntimeError:
            _log_error(f"[JJK Mod Kit] Cannot resolve UE path '{path_str}'")
            return False
    else:
        mod_dir = Path(path_str)

    manifest_path = mod_dir / "manifest.json"
    initial       = _read_manifest(manifest_path)

    init = unreal.ModManifestData()
    init.title       = initial.get("title", "")
    init.description = initial.get("description", "")
    init.version     = initial.get("version", "v1")
    init.priority    = int(initial.get("priority", 0))

    result = lib.show_mod_manifest_dialog(init, False)

    b_confirmed = getattr(result, "confirmed",   None)
    if b_confirmed is None:
        b_confirmed = getattr(result, "b_confirmed", None)
    if b_confirmed is None:
        _log_error(
            "[JJK Mod Kit] Cannot find 'confirmed'/'b_confirmed' on ModManifestData.\n"
            f"Available attributes: {[a for a in dir(result) if not a.startswith('_')]}"
        )
        return False
    if not b_confirmed:
        return False

    manifest_data = {
        "title":       str(result.title).strip(),
        "description": str(result.description).strip(),
        "version":     str(result.version).strip() or "v1",
        "priority":    int(result.priority),
    }

    try:
        _write_manifest(manifest_path, manifest_data)
        _log(f"[JJK Mod Kit] Updated manifest for '{manifest_data['title']}' → {manifest_path}")

        _ue_show_message(
            "Manifest Saved",
            f"Manifest for '{manifest_data['title']}' saved successfully!",
            "info",
        )
        return True

    except Exception as exc:
        _ue_show_message("Error Saving Manifest", f"Failed to save manifest:\n\n{exc}", "error")
        _log_error(f"[JJK Mod Kit] edit manifest error: {exc}")
        return False


def show_mod_picker(mod_names: list[str]) -> tuple[str | None, str | None]:
    """
    Show a listbox so the user can pick one mod from *mod_names* (native UE Slate).

    The dialog shows three buttons:
      Edit   → (action="edit",   chosen=<name>)
      Delete → confirmation, then (action="delete", chosen=<name>)
      Cancel → (action=None,    chosen=None)

    Returns
    -------
    (action, chosen_name)
      action      = "edit" | "delete" | None (cancelled / error)
      chosen_name = mod folder name, or None
    """
    try:
        lib = _get_lib()
    except RuntimeError as exc:
        _log_error(str(exc))
        return None, None

    import unreal
    action_enum, chosen = lib.show_mod_picker_dialog(mod_names)

    if action_enum == unreal.ModPickerAction.EDIT:
        return "edit", str(chosen)
    elif action_enum == unreal.ModPickerAction.DELETE:
        return "delete", str(chosen)
    else:
        return None, None


def show_mod_picker_add(mod_names: list[str]) -> tuple[str | None, str | None]:
    """
    Show a listbox in "Add" mode — two buttons: **Add** and **Cancel**.

    Used when the caller needs the user to choose a target mod without
    offering delete or edit actions (e.g. "Add to Core Packages to Cook").

    Double-clicking a row is equivalent to pressing Add.

    Parameters
    ----------
    mod_names : list[str]
        Mod folder names to display in the listbox.

    Returns
    -------
    (action, chosen_name)
      action      = "add" | None (cancelled / error)
      chosen_name = mod folder name, or None
    """
    try:
        lib = _get_lib()
    except RuntimeError as exc:
        _log_error(str(exc))
        return None, None

    if not hasattr(lib, "show_mod_picker_dialog_add"):
        _log_error(
            "[JJK Mod Kit] show_mod_picker_add: "
            "show_mod_picker_dialog_add is not available.\n"
            "Please recompile the JJKModKit plugin and restart the editor:\n"
            "  Close the editor → run build.ps1  (or use Ctrl+Alt+F11 for Live Coding)"
        )
        _ue_show_message(
            "Plugin Recompile Required",
            "show_mod_picker_dialog_add is not available.\n\n"
            "Please recompile the JJKModKit plugin and restart the editor:\n\n"
            "  1. Close the editor\n"
            "  2. Run build.ps1\n"
            "  3. Reopen the editor\n\n"
            "(Or use Ctrl+Alt+F11 for Live Coding while the editor is open.)",
            "error",
        )
        return None, None

    import unreal
    action_enum, chosen = lib.show_mod_picker_dialog_add(mod_names)

    if action_enum == unreal.ModPickerAction.ADD:
        return "add", str(chosen)
    else:
        return None, None


def delete_mod(mod_name: str) -> bool:
    """
    Delete the mod folder *mod_name* from Content/Mods/.

    The confirmation dialog was already shown by the C++ Slate picker before
    this function is called, so we proceed directly to deletion.

    Returns False always (no manifest was edited — callers use the return
    value of open_edit_manifest_dialog to decide whether to refresh).
    """
    import shutil

    try:
        mods_dir = _get_mods_dir()
        target   = mods_dir / mod_name

        if not target.exists():
            _log_error(f"[JJK Mod Kit] delete_mod: '{target}' does not exist.")
            _ue_show_message(
                "Delete Failed",
                f"Mod folder not found:\n{target}",
                "error",
            )
            return False

        shutil.rmtree(target)
        _ue_refresh_content_browser("/Game/Mods")
        _log(f"[JJK Mod Kit] Deleted mod '{mod_name}' ({target})")
        _ue_show_message(
            "Mod Deleted",
            f"Mod '{mod_name}' has been permanently deleted.",
            "info",
        )

    except Exception as exc:
        _log_error(f"[JJK Mod Kit] Failed to delete mod '{mod_name}': {exc}")
        _ue_show_message(
            "Delete Failed",
            f"Could not delete mod '{mod_name}':\n\n{exc}",
            "error",
        )

    return False


# ─── Logging helpers ─────────────────────────────────────────────────────────

def _log(msg: str) -> None:
    try:
        import unreal
        unreal.log(msg)
    except Exception:
        print(msg)


def _log_error(msg: str) -> None:
    try:
        import unreal
        unreal.log_error(msg)
    except Exception:
        print(f"ERROR: {msg}", file=sys.stderr)

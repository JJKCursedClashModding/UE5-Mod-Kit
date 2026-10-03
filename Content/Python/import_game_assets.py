"""
import_game_assets.py
====================
Unreal Editor Python script.

Performs the full game-asset import pipeline in one click:
  1. Ask the user to pick Jujutsu Kaisen CC.exe or a game .pak file
  2. Run retoc to convert cooked pak files to legacy format  (Paks/Data)
  3. Create AnimBlueprint stubs for every ABP_* / *_ABP asset in the Data folder
  4. Delete every ABP_* / *_ABP file from the Data folder (disk-level cleanup)
  5. Delete the three character-capture WBPs from Data/.../Widgets/Commons
  6. Copy the extracted Data content tree into the project Content/ folder

⚠  This operation uses ~50 GB of disk space and can take a long time.
   A file picker and confirmation dialog are shown before anything is changed.

Run via:  JJK ModKit → Asset Tools → Import Game Assets…
     or:  import import_game_assets; import_game_assets.run()
"""

from __future__ import annotations

import os
import re
import shutil
import subprocess
from pathlib import Path

import unreal


# ─── Constants ────────────────────────────────────────────────────────────────

_AES_KEY = "0xBABFB8ACBA15424956C49B4E6CE9CFA43D5924D0B82FFDF8B6D5D70BE4F9DC82"

# Matches ABP_*.uasset and *_ABP.uasset (and companion .uexp / .ubulk / etc.)
_ABP_BASE_PATTERN = re.compile(r'^(?:ABP_.+|.+_ABP)$', re.IGNORECASE)

# The three WBP stubs we remove before copying (we create them via stub_wbp_commons)
_WBP_COMMONS_BASENAMES = [
    "WBP_CharacterCaptureEnemy",
    "WBP_CharacterCapturePlayer",
    "WBP_CharacterCaptureSimple",
]

# Relative path inside the Data folder where WBPs live
_WBP_REL_PATH = Path("Jujutsu Kaisen CC") / "Content" / "Widgets" / "Commons"

# Content sub-path inside the Data folder
_DATA_CONTENT_REL = Path("Jujutsu Kaisen CC") / "Content"


# ─── Helpers ──────────────────────────────────────────────────────────────────

_FILE_PICKER_FILTER_UE = (
    "Game executable or pak (*.exe;*.pak)|*.exe;*.pak|"
    "Jujutsu Kaisen CC.exe|Jujutsu Kaisen CC.exe|"
    "Pak files (*.pak)|*.pak|"
    "All files (*.*)|*.*"
)

# Windows GetOpenFileNameW filter: pairs of (label, pattern) joined by \0, then a final \0.
_FILE_PICKER_FILTER_WIN = (
    "Game executable or pak (*.exe;*.pak)\0*.exe;*.pak\0"
    "Jujutsu Kaisen CC.exe\0Jujutsu Kaisen CC.exe\0"
    "Pak files (*.pak)\0*.pak\0"
    "All files (*.*)\0*.*\0\0"
)


def _default_browse_path() -> str:
    """Best existing exe / paks path to open the file picker in, or ''."""
    import importlib
    import mod_tools
    importlib.reload(mod_tools)

    exe = mod_tools._configured_game_exe()
    if exe is not None and Path(exe).is_file():
        return str(exe)

    root = mod_tools._get_game_root(require_paks=True)
    if root is None:
        root = mod_tools._get_game_root(require_paks=False)
    if root is not None:
        candidate_exe = root / mod_tools._GAME_EXE_REL
        if candidate_exe.is_file():
            return str(candidate_exe)
        paks = root / "Content" / "Paks"
        if paks.is_dir():
            pak_files = sorted(paks.glob("*.pak"))
            if pak_files:
                return str(pak_files[0])
            return str(paks)
    return ""


def _windows_open_file_dialog(title: str, default_path: str) -> str:
    """
    Native Windows GetOpenFileNameW picker. Always returns an absolute path,
    including files on another drive. Empty string means cancelled / failed.
    """
    import ctypes
    from ctypes import wintypes

    class OPENFILENAMEW(ctypes.Structure):
        _fields_ = [
            ("lStructSize",       wintypes.DWORD),
            ("hwndOwner",         wintypes.HWND),
            ("hInstance",         wintypes.HINSTANCE),
            ("lpstrFilter",       wintypes.LPCWSTR),
            ("lpstrCustomFilter", wintypes.LPWSTR),
            ("nMaxCustFilter",    wintypes.DWORD),
            ("nFilterIndex",      wintypes.DWORD),
            ("lpstrFile",         wintypes.LPWSTR),
            ("nMaxFile",          wintypes.DWORD),
            ("lpstrFileTitle",    wintypes.LPWSTR),
            ("nMaxFileTitle",     wintypes.DWORD),
            ("lpstrInitialDir",   wintypes.LPCWSTR),
            ("lpstrTitle",        wintypes.LPCWSTR),
            ("Flags",             wintypes.DWORD),
            ("nFileOffset",       wintypes.WORD),
            ("nFileExtension",    wintypes.WORD),
            ("lpstrDefExt",       wintypes.LPCWSTR),
            ("lCustData",         wintypes.LPARAM),
            ("lpfnHook",          ctypes.c_void_p),
            ("lpTemplateName",    wintypes.LPCWSTR),
            ("pvReserved",        ctypes.c_void_p),
            ("dwReserved",        wintypes.DWORD),
            ("FlagsEx",           wintypes.DWORD),
        ]

    OFN_FILEMUSTEXIST = 0x00001000
    OFN_PATHMUSTEXIST = 0x00000800
    OFN_HIDEREADONLY  = 0x00000004
    OFN_NOCHANGEDIR   = 0x00000008
    OFN_EXPLORER      = 0x00080000

    start_dir = ""
    default_file = ""
    if default_path:
        hint = Path(default_path)
        if hint.is_file():
            start_dir = str(hint.parent)
            default_file = hint.name
        elif hint.is_dir():
            start_dir = str(hint)

    # Embedded NULs would truncate a normal ctypes string assignment.
    filter_buf = (ctypes.c_wchar * (len(_FILE_PICKER_FILTER_WIN) + 1))()
    for i, ch in enumerate(_FILE_PICKER_FILTER_WIN):
        filter_buf[i] = ch

    buffer = ctypes.create_unicode_buffer(32768)
    if default_file:
        buffer.value = default_file

    ofn = OPENFILENAMEW()
    ofn.lStructSize = ctypes.sizeof(OPENFILENAMEW)
    ofn.lpstrFilter = ctypes.cast(filter_buf, wintypes.LPCWSTR)
    ofn.nFilterIndex = 1
    ofn.lpstrFile = buffer
    ofn.nMaxFile = 32768
    ofn.lpstrInitialDir = start_dir or None
    ofn.lpstrTitle = title
    ofn.Flags = (
        OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST
        | OFN_HIDEREADONLY | OFN_NOCHANGEDIR
    )

    comdlg32 = ctypes.WinDLL("comdlg32", use_last_error=True)
    if not comdlg32.GetOpenFileNameW(ctypes.byref(ofn)):
        return ""
    return buffer.value.strip()


def _pick_game_install_file() -> Path | None:
    """
    Ask the user to pick Jujutsu Kaisen CC.exe or any game .pak file.

    Prefers the plugin's native picker (absolute path, any drive). Falls back
    to the Windows common-dialog API if the plugin has not been rebuilt yet.
    """
    title = "Select Jujutsu Kaisen CC.exe or a game .pak file"
    default_path = _default_browse_path()

    picked = ""
    native_shown = False
    lib = getattr(unreal, "JJKModKitLibrary", None)
    fn = getattr(lib, "open_file_picker", None) if lib is not None else None
    if fn is not None:
        try:
            picked = str(fn(title, default_path, _FILE_PICKER_FILTER_UE) or "").strip()
            native_shown = True
        except Exception as exc:
            unreal.log_warning(f"[ImportGameAssets] Native file picker failed: {exc}")
            picked = ""

    # Only fall back if the plugin picker is missing — not if the user cancelled.
    if not picked and not native_shown:
        try:
            picked = _windows_open_file_dialog(title, default_path)
        except Exception as ext:
            unreal.log_error(f"[ImportGameAssets] Windows file picker failed: {ext}")
            return None

    if not picked:
        return None
    return Path(picked)


def _looks_like_paks_dir(folder: Path) -> bool:
    if not folder.is_dir() or folder.name.lower() != "paks":
        return False
    return (
        any(folder.glob("*.pak"))
        or any(folder.glob("*.utoc"))
        or any(folder.glob("*.ucas"))
    )


def _find_paks_from_path(picked: Path) -> Path | None:
    """
    Resolve <GameRoot>/Content/Paks from a user-picked exe, pak, or nearby folder.
    """
    try:
        picked = picked.resolve()
    except Exception:
        pass

    import importlib
    import mod_tools
    importlib.reload(mod_tools)

    if picked.is_file() and picked.suffix.lower() == ".exe":
        paks = mod_tools._game_root_from_exe(picked) / "Content" / "Paks"
        if paks.is_dir():
            return paks

    start = picked.parent if picked.is_file() else picked
    for folder in [start, *start.parents]:
        if _looks_like_paks_dir(folder):
            return folder
        candidate = folder / "Content" / "Paks"
        if _looks_like_paks_dir(candidate):
            return candidate
        if candidate.is_dir():
            return candidate
    return None


def _remember_game_path(picked: Path, paks_dir: Path) -> None:
    """Store Game Exe Path from the picked file so later cooks use this install."""
    import importlib
    import mod_tools
    importlib.reload(mod_tools)

    exe: Path | None = None
    if picked.is_file() and picked.suffix.lower() == ".exe":
        exe = picked
    else:
        candidate = paks_dir.parent.parent / mod_tools._GAME_EXE_REL
        if candidate.is_file():
            exe = candidate

    if exe is None:
        return
    try:
        mod_tools.save_config({"game_exe_path": str(exe)})
        unreal.log(f"[ImportGameAssets] Saved Game Exe Path: {exe}")
    except Exception as exc:
        unreal.log_warning(f"[ImportGameAssets] Could not save Game Exe Path: {exc}")


def _get_project_content_dir() -> Path:
    """Return the absolute path to the project's Content/ directory."""
    raw = unreal.Paths.convert_relative_path_to_full(
        unreal.Paths.project_content_dir()
    )
    return Path(raw.replace("\\", "/").rstrip("/"))


def _get_project_dir() -> Path:
    """Return the absolute path to the project root directory."""
    raw = unreal.Paths.convert_relative_path_to_full(
        unreal.Paths.project_dir()
    )
    return Path(raw.replace("\\", "/").rstrip("/"))


def _find_retoc() -> str:
    """
    Locate the retoc executable.

    Required location:
      <project root>/Tools/retoc.exe
    """
    tools_retoc = _get_project_dir() / "Tools" / "retoc.exe"
    return str(tools_retoc)


def _delete_files_by_basename(folder: Path, pattern: re.Pattern) -> int:
    """
    Walk *folder* recursively and delete every file whose base-name (without
    extension) matches *pattern*.  Companion files (.uexp, .ubulk, etc.) that
    share the same stem are also removed.

    Returns the number of files deleted.
    """
    # Collect matching stems first, then delete all files with those stems.
    deleted = 0
    for root_str, _dirs, files in os.walk(str(folder)):
        root_path = Path(root_str)
        stems_to_delete: set[str] = set()
        for fname in files:
            stem = Path(fname).stem
            if pattern.match(stem):
                stems_to_delete.add(stem)
        for fname in files:
            if Path(fname).stem in stems_to_delete:
                fp = root_path / fname
                try:
                    fp.unlink()
                    unreal.log(f"[ImportGameAssets]   Deleted: {fp}")
                    deleted += 1
                except OSError as exc:
                    unreal.log_warning(
                        f"[ImportGameAssets]   Could not delete {fp}: {exc}"
                    )
    return deleted


def _delete_specific_files(folder: Path, basenames: list[str]) -> int:
    """
    Delete all files whose stem is in *basenames* inside *folder* (non-recursive).
    Returns the number of files deleted.
    """
    deleted = 0
    if not folder.exists():
        unreal.log_warning(
            f"[ImportGameAssets]   WBP directory not found — skipping: {folder}"
        )
        return deleted
    basename_set = {n.lower() for n in basenames}
    for fp in folder.iterdir():
        if fp.stem.lower() in basename_set:
            try:
                fp.unlink()
                unreal.log(f"[ImportGameAssets]   Deleted: {fp}")
                deleted += 1
            except OSError as exc:
                unreal.log_warning(
                    f"[ImportGameAssets]   Could not delete {fp}: {exc}"
                )
    return deleted


def _count_files(folder: Path) -> int:
    """Return the total number of files under *folder* (recursive)."""
    return sum(1 for _, _, files in os.walk(str(folder)) for _ in files)


# ─── Main pipeline ─────────────────────────────────────────────────────────────

def run() -> None:
    """
    Run the full import pipeline with a progress bar and confirmation dialog.
    Called by the JJK ModKit menu entry.
    """
    # ── Locate this machine's game install ───────────────────────────────────
    picked = _pick_game_install_file()
    if picked is None:
        unreal.log("[ImportGameAssets] Cancelled — no game file selected.")
        return

    paks_dir = _find_paks_from_path(picked)
    if paks_dir is None or not paks_dir.exists():
        unreal.EditorDialog.show_message(
            title="Import Game Assets — Error",
            message=(
                "Could not find a Content/Paks folder from:\n"
                f"{picked}\n\n"
                "Select Jujutsu Kaisen CC.exe, or any .pak file inside\n"
                "the game's Content/Paks directory, then try again."
            ),
            message_type=unreal.AppMsgType.OK,
            default_value=unreal.AppReturnType.OK,
        )
        return

    data_dir         = paks_dir / "Data"
    data_content_dir = data_dir / _DATA_CONTENT_REL
    project_content  = _get_project_content_dir()

    # ── Confirmation ─────────────────────────────────────────────────────────
    confirm = unreal.EditorDialog.show_message(
        title="Import Game Assets — Confirmation",
        message=(
            "This operation will use approximately 50 GB of disk space and\n"
            "may take 5-10 minutes depending on your hardware.\n\n"
            "Steps that will run:\n"
            "  1. Unpack game files\n"
            "  2. Create Animation Blueprint stubs from extracted content\n"
            "  3. Delete all problematic assets from the game folder\n"
            "  4. Delete 3 character-capture WBP files from Data/.../Widgets/Commons\n"
            "  5. Copy the extracted content into the project Content/ folder\n\n"
            f"Selected file : {picked}\n"
            f"Paks folder   : {paks_dir}\n\n"
            "The editor will be mostly unresponsive during step 1.\n\n"
            "Do you want to continue?"
        ),
        message_type=unreal.AppMsgType.YES_NO,
        default_value=unreal.AppReturnType.NO,
    )
    if confirm != unreal.AppReturnType.YES:
        unreal.log("[ImportGameAssets] Cancelled by user.")
        return

    _remember_game_path(picked, paks_dir)

    errors: list[str] = []

    # ── Top-level slow-task: 5 phases ─────────────────────────────────────────
    with unreal.ScopedSlowTask(5, "Importing game assets…") as main_task:
        main_task.make_dialog(True)

        # ═══════════════════════════════════════════════════════════════════════
        # Phase 1 — retoc: convert cooked paks to legacy format
        # ═══════════════════════════════════════════════════════════════════════
        if main_task.should_cancel():
            unreal.log("[ImportGameAssets] Cancelled before step 1.")
            return

        main_task.enter_progress_frame(
            1,
            "Step 1 / 5 — Converting pak files to legacy format  (this will take a while)…"
        )

        retoc_exe = _find_retoc()
        cmd = [retoc_exe, "--aes-key", _AES_KEY, "to-legacy", ".", "Data"]
        unreal.log(f"[ImportGameAssets] ─── Phase 1: retoc ───")
        unreal.log(f"[ImportGameAssets] CWD     : {paks_dir}")
        unreal.log(f"[ImportGameAssets] Command : {' '.join(cmd)}")

        try:
            proc = subprocess.run(
                cmd,
                cwd=str(paks_dir),
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                text=True,
            )
            # Stream captured output to the UE output log
            if proc.stdout:
                for line in proc.stdout.splitlines():
                    if line.strip():
                        unreal.log(f"[retoc] {line}")

            if proc.returncode != 0:
                msg = (
                    f"retoc exited with code {proc.returncode}.\n"
                    "Check the Output Log for details."
                )
                unreal.log_error(f"[ImportGameAssets] {msg}")
                unreal.EditorDialog.show_message(
                    title="Import Game Assets — retoc Error",
                    message=msg,
                    message_type=unreal.AppMsgType.OK,
                    default_value=unreal.AppReturnType.OK,
                )
                return

        except FileNotFoundError:
            msg = (
                f"retoc executable not found: '{retoc_exe}'\n\n"
                "Place retoc.exe in the project  Tools/  folder\n"
                "or add it to your system PATH."
            )
            unreal.log_error(f"[ImportGameAssets] {msg}")
            unreal.EditorDialog.show_message(
                title="Import Game Assets — Error",
                message=msg,
                message_type=unreal.AppMsgType.OK,
                default_value=unreal.AppReturnType.OK,
            )
            return

        except Exception as exc:
            unreal.log_error(f"[ImportGameAssets] retoc failed: {exc}")
            errors.append(f"retoc: {exc}")

        unreal.log("[ImportGameAssets] ✓ Phase 1 complete — pak conversion done.")

        # ═══════════════════════════════════════════════════════════════════════
        # Phase 2 — Stub ABPs
        # ═══════════════════════════════════════════════════════════════════════
        if main_task.should_cancel():
            unreal.log("[ImportGameAssets] Cancelled before step 2.")
            return

        main_task.enter_progress_frame(
            1,
            "Step 2 / 5 — Creating AnimBlueprint stubs…"
        )
        unreal.log("[ImportGameAssets] ─── Phase 2: ABP stubs ───")

        if data_content_dir.exists():
            import importlib
            import stub_abp_from_folder
            importlib.reload(stub_abp_from_folder)
            # run() uses its own nested ScopedSlowTask with a cancellable dialog
            stub_abp_from_folder.run(str(data_content_dir))
            unreal.log("[ImportGameAssets] ✓ Phase 2 complete — ABP stubs created.")
        else:
            unreal.log_warning(
                f"[ImportGameAssets] Data content dir not found: {data_content_dir}"
                " — skipping ABP stub creation."
            )
            errors.append(f"Phase 2 skipped — {data_content_dir} does not exist.")

        # ═══════════════════════════════════════════════════════════════════════
        # Phase 3 — Delete ABP_* / *_ABP files from the Data folder
        # ═══════════════════════════════════════════════════════════════════════
        if main_task.should_cancel():
            unreal.log("[ImportGameAssets] Cancelled before step 3.")
            return

        main_task.enter_progress_frame(
            1,
            "Step 3 / 5 — Deleting ABP files from the Data folder…"
        )
        unreal.log("[ImportGameAssets] ─── Phase 3: delete ABP files ───")

        if data_dir.exists():
            abp_deleted = _delete_files_by_basename(data_dir, _ABP_BASE_PATTERN)
            unreal.log(
                f"[ImportGameAssets]   ABP files deleted: {abp_deleted}"
            )

            # Also remove the ACLPlugin editor data folder
            acl_folder = data_dir / _DATA_CONTENT_REL / "Editor" / "ACLPlugin"
            if acl_folder.exists():
                try:
                    shutil.rmtree(str(acl_folder))
                    unreal.log(f"[ImportGameAssets]   Deleted folder: {acl_folder}")
                except OSError as exc:
                    unreal.log_warning(
                        f"[ImportGameAssets]   Could not delete {acl_folder}: {exc}"
                    )
            else:
                unreal.log(
                    f"[ImportGameAssets]   ACLPlugin folder not found (skipping): {acl_folder}"
                )

            unreal.log("[ImportGameAssets] ✓ Phase 3 complete.")
        else:
            unreal.log_warning(
                f"[ImportGameAssets] Data dir not found: {data_dir} — skipping phase 3."
            )
            errors.append(f"Phase 3 skipped — {data_dir} does not exist.")

        # ═══════════════════════════════════════════════════════════════════════
        # Phase 4 — Delete the three character-capture WBP files
        # ═══════════════════════════════════════════════════════════════════════
        if main_task.should_cancel():
            unreal.log("[ImportGameAssets] Cancelled before step 4.")
            return

        main_task.enter_progress_frame(
            1,
            "Step 4 / 5 — Deleting character-capture WBP files…"
        )
        unreal.log("[ImportGameAssets] ─── Phase 4: delete WBP files ───")

        # 2026-09-30: the three capture WBPs are PRESERVED, not deleted.
        # The originals were extracted from the game paks and installed in
        # the project (Content/Widgets/Commons/). They are cold-linker safe
        # and required at cook time so dependents (e.g. the FreeBattle
        # select screen) resolve WBP_CharacterCaptureSimple_C and keep
        # their CharacterVariationImage reference. A future re-import just
        # overwrites them with identical bytes — do NOT delete them here.
        unreal.log("[ImportGameAssets] ─── Phase 4: capture WBPs preserved ───")
        wbp_deleted = 0
        unreal.log(
            f"[ImportGameAssets] ✓ Phase 4 complete — {wbp_deleted} WBP file(s) deleted."
        )

        # ═══════════════════════════════════════════════════════════════════════
        # Phase 5 — Copy Data/Content → project Content/
        # ═══════════════════════════════════════════════════════════════════════
        if main_task.should_cancel():
            unreal.log("[ImportGameAssets] Cancelled before step 5.")
            return

        main_task.enter_progress_frame(
            1,
            "Step 5 / 5 — Moving content into project…"
        )
        unreal.log("[ImportGameAssets] ─── Phase 5: move content ───")

        if not data_content_dir.exists():
            unreal.log_warning(
                f"[ImportGameAssets] Data content dir not found: {data_content_dir}"
                " — skipping move."
            )
            errors.append(f"Phase 5 skipped — {data_content_dir} does not exist.")
        else:
            # Gather all source files up-front so we can show a per-file bar
            all_src_files = [
                Path(r) / f
                for r, _d, files in os.walk(str(data_content_dir))
                for f in files
            ]
            total = len(all_src_files)
            unreal.log(
                f"[ImportGameAssets] Moving {total} file(s) "
                f"from {data_content_dir} → {project_content}"
            )

            with unreal.ScopedSlowTask(total, "Moving files…") as copy_task:
                copy_task.make_dialog(True)
                moved = skipped = 0

                for src in all_src_files:
                    if copy_task.should_cancel():
                        unreal.log_warning(
                            "[ImportGameAssets] Move step cancelled by user."
                        )
                        break

                    rel = src.relative_to(data_content_dir)
                    dst = project_content / rel

                    # Show a short label so the dialog doesn't overflow
                    label = str(rel)
                    if len(label) > 80:
                        label = "…" + label[-77:]
                    copy_task.enter_progress_frame(1, label)

                    dst.parent.mkdir(parents=True, exist_ok=True)
                    try:
                        shutil.move(str(src), str(dst))
                        moved += 1
                    except OSError as exc:
                        unreal.log_warning(
                            f"[ImportGameAssets]   Move failed: {src} → {dst}: {exc}"
                        )
                        skipped += 1

            unreal.log(
                f"[ImportGameAssets] ✓ Phase 5 complete — "
                f"moved: {moved}, failed: {skipped}, total: {total}"
            )

    # ═══════════════════════════════════════════════════════════════════════════
    # Cleanup — delete the Data folder from Paks
    # ═══════════════════════════════════════════════════════════════════════════
    unreal.log("[ImportGameAssets] ─── Cleanup: removing Data folder ───")
    if data_dir.exists():
        try:
            shutil.rmtree(str(data_dir))
            unreal.log(f"[ImportGameAssets] ✓ Deleted Data folder: {data_dir}")
        except OSError as exc:
            unreal.log_warning(
                f"[ImportGameAssets]   Could not delete Data folder {data_dir}: {exc}"
            )
            errors.append(f"Cleanup: could not delete {data_dir}: {exc}")
    else:
        unreal.log(f"[ImportGameAssets]   Data folder already gone: {data_dir}")

    # ═══════════════════════════════════════════════════════════════════════════
    # Phase 6 — BindWidget mass repair (auto-patch C++ headers for all widgets)
    # ═══════════════════════════════════════════════════════════════════════════
    # Imported Widget Blueprints whose C++ parent declares Instanced UWidget*
    # properties without meta=(BindWidget) would fail to recompile after
    # uncooking ("Tried to create a property X ..."), and cooking them emits
    # the corrupt package that dies at load with
    # "WidgetTree.TopWidget: Serial size mismatch".
    # This runs the same reflection-based repair as uncook (bIsVariable widgets
    # only — structural widgets are deliberately left alone) across every
    # imported Widget Blueprint, so no per-asset manual fix is ever needed.
    # Patched headers require ONE rebuild (build.ps1) before any cook.
    unreal.log("[ImportGameAssets] ─── Phase 6: BindWidget header repair ───")
    bw_patched = bw_clean = bw_unpatchable = 0
    try:
        _bw_api = getattr(getattr(unreal, "BlueprintUncookerLibrary", None),
                          "ensure_bind_widget_headers", None)
    except Exception:
        _bw_api = None
    if _bw_api is None:
        unreal.log_warning(
            "[ImportGameAssets] Phase 6 skipped — BlueprintUncooker auto-repair "
            "not in these binaries. Rebuild (build.ps1) to enable it; until then, "
            "uncooked Widgets may still hit the BindWidget cook error."
        )
        errors.append("Phase 6 skipped — rebuild to enable BindWidget auto-repair.")
    else:
        import importlib as _il
        import fix_widget_bindings as _fwb
        try:
            _fwb = _il.reload(_fwb)
        except Exception:
            pass
        try:
            _wb_ps = _fwb.find_widget_blueprints("/Game/Widgets")
        except Exception as _find_ex:
            unreal.log_warning(f"[ImportGameAssets]   widget discovery failed: {_find_ex}")
            _wb_ps = []
        unreal.log(f"[ImportGameAssets]   {len(_wb_ps)} Widget Blueprint(s) to check…")
        import re as _re
        with unreal.ScopedSlowTask(max(len(_wb_ps), 1), "Repairing BindWidget headers…") as _bw_task:
            _bw_task.make_dialog(True)
            for _pkg in _wb_ps:
                if _bw_task.should_cancel():
                    unreal.log_warning("[ImportGameAssets]   Phase 6 cancelled by user.")
                    break
                _bw_task.enter_progress_frame(1, _pkg.rsplit("/", 1)[-1])
                try:
                    _st = _bw_api(_pkg)
                except Exception as _call_ex:
                    unreal.log_warning(f"[ImportGameAssets]   {_pkg} — check failed: {_call_ex}")
                    continue
                if not isinstance(_st, str) or _st.startswith("ERROR"):
                    continue
                _m_p = _re.search(r"HeadersPatched:(\d+)", _st)
                _m_u = _re.search(r"Unpatchable:(\d+)", _st)
                _n_p = int(_m_p.group(1)) if _m_p else 0
                _n_u = int(_m_u.group(1)) if _m_u else 0
                if _n_p > 0:
                    bw_patched += 1
                else:
                    bw_clean += 1
                if _n_u > 0:
                    bw_unpatchable += 1
        unreal.log(
            f"[ImportGameAssets] ✓ Phase 6 complete — "
            f"patched: {bw_patched}, clean: {bw_clean}, "
            f"with unpatchable props: {bw_unpatchable}"
        )
        if bw_patched > 0:
            errors.append(
                f"Phase 6 auto-patched C++ headers for {bw_patched} Widget Blueprint(s) — "
                "REBUILD (close editor → .\\build.ps1) before cooking any Widget override."
            )

    # ── Summary ───────────────────────────────────────────────────────────────
    if errors:
        summary = "Import finished with warnings:\n\n" + "\n".join(f"  • {e}" for e in errors)
        unreal.log_warning(f"[ImportGameAssets] {summary}")
    else:
        summary = "All steps completed successfully."

    unreal.log("[ImportGameAssets] ━━━ Import pipeline complete ━━━")
    unreal.EditorDialog.show_message(
        title="Import Game Assets — Done",
        message=(
            f"✅  Import complete!\n\n{summary}\n\n"
            "Game assets have been moved into the project Content/ folder.\n"
            "You may need to restart the editor for new assets to appear\n"
            "in the Content Browser."
        ),
        message_type=unreal.AppMsgType.OK,
        default_value=unreal.AppReturnType.OK,
    )

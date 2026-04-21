"""
import_game_assets.py
====================
Unreal Editor Python script.

Performs the full game-asset import pipeline in one click:
  1. Run retoc to convert cooked pak files to legacy format  (Paks/Data)
  2. Create AnimBlueprint stubs for every ABP_* / *_ABP asset in the Data folder
  3. Delete every ABP_* / *_ABP file from the Data folder (disk-level cleanup)
  4. Delete the three character-capture WBPs from Data/.../Widgets/Commons
  5. Copy the extracted Data content tree into the project Content/ folder

⚠  This operation uses ~50 GB of disk space and can take a long time.
   A confirmation dialog is shown before anything is changed.

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

def _get_paks_dir() -> Path:
    """
    Derive  <GameRoot>/Content/Paks  from the GameExePath CDO setting.

    Falls back to the default Steam install path when the CDO is unavailable.
    """
    try:
        import mod_tools
        cdo = mod_tools._get_settings_cdo()
        if cdo is not None:
            val = str(cdo.game_exe_path.file_path).strip()
            if val:
                exe_path = Path(val)
                # <exe>/Win64/ → Binaries/ → <GameRoot>/ → Content/Paks
                game_root = exe_path.parent.parent.parent
                return (game_root / "Content" / "Paks").resolve()
    except Exception:
        pass
    return Path(
        r"C:\Program Files (x86)\Steam\steamapps\common"
        r"\Jujutsu Kaisen CC\Jujutsu Kaisen CC\Content\Paks"
    )


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

    Search order:
      1. <project root>/Tools/retoc.exe
      2. System PATH  (retoc / retoc.exe)
    """
    tools_retoc = _get_project_dir() / "Tools" / "retoc.exe"
    if tools_retoc.exists():
        return str(tools_retoc)
    found = shutil.which("retoc") or shutil.which("retoc.exe")
    if found:
        return found
    return "retoc"   # last resort — hope it is in PATH at subprocess time


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
    paks_dir         = _get_paks_dir()
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
            # f"Paks dir      : {paks_dir}\n"
            # f"Data output   : {data_dir}\n"
            # f"Project Content: {project_content}\n\n"
            "The editor will be mostly unresponsive during step 1.\n\n"
            "Do you want to continue?"
        ),
        message_type=unreal.AppMsgType.YES_NO,
        default_value=unreal.AppReturnType.NO,
    )
    if confirm != unreal.AppReturnType.YES:
        unreal.log("[ImportGameAssets] Cancelled by user.")
        return

    # ── Validate Paks directory ───────────────────────────────────────────────
    if not paks_dir.exists():
        unreal.EditorDialog.show_message(
            title="Import Game Assets — Error",
            message=(
                f"Paks directory not found:\n{paks_dir}\n\n"
                "Set the Game Exe Path in  JJK Mod Kit → Settings…"
            ),
            message_type=unreal.AppMsgType.OK,
            default_value=unreal.AppReturnType.OK,
        )
        return

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

        wbp_dir     = data_dir / _WBP_REL_PATH
        wbp_deleted = _delete_specific_files(wbp_dir, _WBP_COMMONS_BASENAMES)
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

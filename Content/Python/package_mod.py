"""
package_mod.py — JujutsuKaisenCC DLC Packager
===============================================
Cooks a mod's assets and packages them into a UE5-compatible .pak file.

The pak uses the standard UE DLC path structure so the game can mount it:
    ../../../Jujutsu Kaisen CC/Content/Mods/<ModName>/...

Output:
    <project>/Saved/StagedMods/<ModName>/<ModName>_P.pak

Usage (UE Python console — runs inside the editor):
    import package_mod
    package_mod.package_mod("SampleNewAnimation")
    package_mod.package_all_mods()

Usage (standalone CLI — runs UnrealEditor-Cmd.exe as a subprocess):
    python Content/Python/package_mod.py SampleNewAnimation
    python Content/Python/package_mod.py --all

Cook strategy
-------------
The previous approach used -DisableUnsolicitedPackages (SkipHardReferences |
SkipSoftReferences) which caused the cooker to produce 0 saved packages because
it refused to follow any reference at all — not even the asset itself when it
had external dependencies.

The correct approach for "cook only mod assets, not base-game assets" is:

  1. Remove SkipHardReferences / SkipSoftReferences so the cooker CAN follow
     references to load and resolve assets.
  2. Rely on the DirectoriesToNeverCook entries already in DefaultGame.ini
     (/Game/Characters, /Game/Commons, etc.) to prevent base-game assets from
     being *written* to the cooked output even though they are *loaded*.
  3. Pass -CookDir=/Game/Mods/<ModName> to limit the initial seed set.

This produces cooked output only for the mod assets while the NeverCook rules
act as a write-side filter for base-game content.
"""

from __future__ import annotations

import os
import sys
import shutil
import subprocess
import tempfile
from pathlib import Path

# ─── Detect whether we are running inside the UE editor ─────────────────────
try:
    import unreal
    _IN_EDITOR = True
except ImportError:
    _IN_EDITOR = False

# ─── Constants ───────────────────────────────────────────────────────────────

# The game's internal content root as it appears in the pak mount path.
# Base-game paks use "Jujutsu Kaisen CC" (with spaces), so we match that.
_GAME_CONTENT_ROOT = "Jujutsu Kaisen CC"

# UE engine location
_UE_ROOT = Path("C:/Program Files/Epic Games/UE_5.1")
_UNREAL_EDITOR_CMD = _UE_ROOT / "Engine/Binaries/Win64/UnrealEditor-Cmd.exe"
_UNREAL_PAK        = _UE_ROOT / "Engine/Binaries/Win64/UnrealPak.exe"


# ─── Path helpers ────────────────────────────────────────────────────────────

def _project_root() -> Path:
    if _IN_EDITOR:
        return Path(unreal.Paths.project_dir()).resolve()
    candidate = Path(__file__).resolve().parent
    for _ in range(10):
        if any(candidate.glob("*.uproject")):
            return candidate
        candidate = candidate.parent
    raise RuntimeError("Could not locate project root (.uproject not found).")


def _project_file() -> Path:
    root = _project_root()
    matches = list(root.glob("*.uproject"))
    if not matches:
        raise RuntimeError(f"No .uproject file found in {root}")
    return matches[0]


def _project_name() -> str:
    return _project_file().stem   # "JujutsuKaisenCC"


def _content_mods_dir() -> Path:
    return _project_root() / "Content" / "Mods"


def _cooked_dir() -> Path:
    """
    Root of the cooked output tree.

    - In-editor (CookByTheBookFromTheEditor): Saved/EditorCooked/Windows/<ProjectName>
    - CLI subprocess (CookByTheBook):         Saved/Cooked/Windows/<ProjectName>
    """
    root = _project_root()
    name = _project_name()
    if _IN_EDITOR:
        return root / "Saved" / "EditorCooked" / "Windows" / name
    return root / "Saved" / "Cooked" / "Windows" / name


def _staged_mods_dir() -> Path:
    return _project_root() / "Saved" / "StagedMods"


# ─── Logging ─────────────────────────────────────────────────────────────────

def _log(msg: str) -> None:
    if _IN_EDITOR:
        unreal.log(msg)
    else:
        print(msg)


def _log_error(msg: str) -> None:
    if _IN_EDITOR:
        unreal.log_error(msg)
    else:
        print(f"ERROR: {msg}", file=sys.stderr)


# ─── Cook ────────────────────────────────────────────────────────────────────

def _cook_in_editor(mod_name: str) -> int:
    """
    Cook /Game/Mods/<mod_name> in-process using UJJKModCooker.

    NOTE: UJJKModCooker currently passes SkipHardReferences | SkipSoftReferences
    which produces 0 saved packages.  Until that C++ code is updated, the
    in-editor path falls back to a subprocess cook (same as CLI) so that the
    correct flags are used.  This means the editor will be briefly unresponsive
    while the subprocess runs.
    """
    _log("[package_mod] In-editor cook: falling back to subprocess to use correct flags.")
    return _cook_subprocess(mod_name)


def _cook_subprocess(mod_name: str) -> int:
    """
    Cook /Game/Mods/<mod_name> via UnrealEditor-Cmd.exe subprocess.

    Key flags:
      -CookDir=/Game/Mods/<mod_name>   seed the cook queue with the mod folder
      -Unversioned                      omit engine version header (smaller output)
      -NoGameAlwaysCook                 skip DirectoriesToAlwaysCook (Interchange etc.)

    Intentionally NOT passed:
      -DisableUnsolicitedPackages       (was SkipHardReferences|SkipSoftReferences —
                                         caused 0 packages saved; removed so the cooker
                                         can follow references to load assets)

    Base-game assets are excluded from the *output* by the DirectoriesToNeverCook
    entries already in Config/DefaultGame.ini (/Game/Characters, /Game/Commons, …).
    """
    if not _UNREAL_EDITOR_CMD.exists():
        _log_error(f"UnrealEditor-Cmd.exe not found at {_UNREAL_EDITOR_CMD}")
        return 1

    project_file = _project_file()
    cook_dir_arg = f"/Game/Mods/{mod_name}"

    cmd = [
        str(_UNREAL_EDITOR_CMD),
        str(project_file),
        "-run=Cook",
        "-TargetPlatform=Windows",
        f"-CookDir={cook_dir_arg}",
        "-Unversioned",
        "-NoLogTimes",
        "-NoGameAlwaysCook",
        "-NoSplash",
        "-Unattended",
        "-NullRHI",
        "-stdout",
        "-FullStdOutLogOutput",
    ]

    _log(f"[package_mod] Cook command: {' '.join(cmd)}")

    proc = subprocess.Popen(
        cmd,
        cwd=str(_project_root()),
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        bufsize=1,
    )
    for line in proc.stdout:
        stripped = line.rstrip()
        if stripped:
            _log(f"[Cook] {stripped}")
    proc.wait()
    return proc.returncode


def cook_mod(mod_name: str) -> int:
    """
    Cook assets for *mod_name*.  Returns 0 on success.

    Cooked output lands in:
        Saved/EditorCooked/Windows/<ProjectName>/Content/Mods/<ModName>/  (editor)
        Saved/Cooked/Windows/<ProjectName>/Content/Mods/<ModName>/        (CLI)
    """
    mod_name = (mod_name or "").strip()
    if not mod_name:
        _log_error("cook_mod: mod_name must not be empty.")
        return 1

    source_dir = _content_mods_dir() / mod_name
    if not source_dir.exists():
        _log_error(f"Mod source directory not found: {source_dir}")
        return 1

    _log(f"[package_mod] === Cooking mod: {mod_name} ===")

    if _IN_EDITOR:
        rc = _cook_in_editor(mod_name)
    else:
        rc = _cook_subprocess(mod_name)

    if rc == 0:
        cooked = _cooked_dir() / "Content" / "Mods" / mod_name
        _log(f"[package_mod] Cook succeeded.  Cooked output: {cooked}")
    else:
        _log_error(f"[package_mod] Cook failed (exit {rc}).")
    return rc


# ─── Pak ─────────────────────────────────────────────────────────────────────

def _build_pak_response_file(cooked_mod_dir: Path, mod_name: str) -> Path:
    """
    Write a UnrealPak response file that maps each cooked file to its
    in-pak mount path:

        "<abs_src_path>" "../../../Jujutsu Kaisen CC/Content/Mods/<ModName>/..."

    Returns the path to the temporary response file.
    """
    if not cooked_mod_dir.exists() or not any(cooked_mod_dir.rglob("*")):
        raise FileNotFoundError(
            f"No cooked files found under {cooked_mod_dir}.\n"
            f"Run cook_mod('{mod_name}') first."
        )

    lines = []
    for src in sorted(cooked_mod_dir.rglob("*")):
        if not src.is_file():
            continue
        rel = src.relative_to(cooked_mod_dir)
        # Build the in-pak path using forward slashes and the game's content root
        pak_path = f"../../../{_GAME_CONTENT_ROOT}/Content/Mods/{mod_name}/{rel.as_posix()}"
        # UnrealPak response file format: "<source>" "<dest>"
        lines.append(f'"{src}" "{pak_path}"\n')

    if not lines:
        raise FileNotFoundError(f"No files to pak under {cooked_mod_dir}.")

    # Write to a temp file (UnrealPak reads it via @<path>)
    tmp = tempfile.NamedTemporaryFile(
        mode="w", suffix=".txt", delete=False, encoding="utf-8"
    )
    tmp.writelines(lines)
    tmp.close()
    _log(f"[package_mod] Response file: {tmp.name} ({len(lines)} entries)")
    return Path(tmp.name)


def pak_mod(mod_name: str) -> int:
    """
    Package the cooked output for *mod_name* into a .pak file.

    Output: Saved/StagedMods/<ModName>/<ModName>_P.pak

    Returns 0 on success, non-zero on failure.
    """
    mod_name = (mod_name or "").strip()
    if not mod_name:
        _log_error("pak_mod: mod_name must not be empty.")
        return 1

    if not _UNREAL_PAK.exists():
        _log_error(f"UnrealPak.exe not found at {_UNREAL_PAK}")
        return 1

    cooked_mod_dir = _cooked_dir() / "Content" / "Mods" / mod_name
    if not cooked_mod_dir.exists():
        _log_error(
            f"No cooked output found for '{mod_name}'.\n"
            f"Expected: {cooked_mod_dir}\n"
            f"Run cook_mod('{mod_name}') first."
        )
        return 1

    # Output pak path
    out_dir = _staged_mods_dir() / mod_name
    out_dir.mkdir(parents=True, exist_ok=True)
    pak_path = out_dir / f"{mod_name}_P.pak"

    _log(f"[package_mod] === Packing mod: {mod_name} ===")
    _log(f"[package_mod]   Source : {cooked_mod_dir}")
    _log(f"[package_mod]   Output : {pak_path}")

    try:
        response_file = _build_pak_response_file(cooked_mod_dir, mod_name)
    except FileNotFoundError as e:
        _log_error(str(e))
        return 1

    try:
        cmd = [
            str(_UNREAL_PAK),
            str(pak_path),
            f"-Create={response_file}",
            "-compress",
        ]
        _log(f"[package_mod] UnrealPak command: {' '.join(cmd)}")

        proc = subprocess.Popen(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
        )
        for line in proc.stdout:
            stripped = line.rstrip()
            if stripped:
                _log(f"[Pak] {stripped}")
        proc.wait()
        rc = proc.returncode
    finally:
        try:
            os.unlink(response_file)
        except OSError:
            pass

    if rc == 0 and pak_path.exists():
        size_mb = pak_path.stat().st_size / (1024 * 1024)
        _log(f"[package_mod] ✓ Pak created: {pak_path} ({size_mb:.2f} MB)")
    else:
        _log_error(f"[package_mod] UnrealPak failed (exit {rc}).")
    return rc


# ─── Combined cook + pak ──────────────────────────────────────────────────────

def package_mod(mod_name: str) -> int:
    """
    Cook *mod_name* and package it into a .pak file.

    Steps:
      1. Cook /Game/Mods/<mod_name> via UnrealEditor-Cmd.exe
      2. Run UnrealPak.exe to create <ModName>_P.pak

    Output: Saved/StagedMods/<ModName>/<ModName>_P.pak

    Returns 0 on success, non-zero on failure.
    """
    mod_name = (mod_name or "").strip()
    if not mod_name:
        _log_error("package_mod: mod_name must not be empty.")
        return 1

    _log(f"[package_mod] ========================================")
    _log(f"[package_mod] Packaging mod: {mod_name}")
    _log(f"[package_mod] ========================================")

    rc = cook_mod(mod_name)
    if rc != 0:
        return rc

    rc = pak_mod(mod_name)
    return rc


def package_all_mods() -> dict:
    """
    Cook and package every mod found under Content/Mods/.

    Returns a dict mapping mod_name → "OK" | "FAILED" | "SKIPPED (no source)".
    """
    mods_dir = _content_mods_dir()
    if not mods_dir.exists():
        _log_error(f"Content/Mods/ directory not found: {mods_dir}")
        return {}

    mods = [d.name for d in sorted(mods_dir.iterdir()) if d.is_dir()]
    if not mods:
        _log("[package_mod] No mod directories found under Content/Mods/.")
        return {}

    _log(f"[package_mod] Found mods: {mods}")
    results = {}

    for mod_name in mods:
        _log(f"\n[package_mod] ── Processing: {mod_name} ──")
        rc = package_mod(mod_name)
        results[mod_name] = "OK" if rc == 0 else "FAILED"

    _log("\n[package_mod] ========================================")
    _log("[package_mod] Summary:")
    for name, status in results.items():
        _log(f"[package_mod]   {name}: {status}")
    _log("[package_mod] ========================================")
    return results


# ─── CLI entry point ─────────────────────────────────────────────────────────

if __name__ == "__main__":
    _USAGE = (
        "Usage:\n"
        "  package_mod.py <ModName>          — cook + pak a single mod\n"
        "  package_mod.py --all              — cook + pak every mod in Content/Mods/\n"
        "  package_mod.py --cook <ModName>   — cook only (no pak)\n"
        "  package_mod.py --pak  <ModName>   — pak only (cook must have run first)\n"
    )

    args = sys.argv[1:]
    if not args:
        print(_USAGE)
        sys.exit(0)

    if args[0] == "--all":
        results = package_all_mods()
        failed = [n for n, s in results.items() if s != "OK"]
        sys.exit(1 if failed else 0)

    elif args[0] == "--cook":
        if len(args) < 2:
            print("Usage: package_mod.py --cook <ModName>")
            sys.exit(1)
        sys.exit(cook_mod(args[1]))

    elif args[0] == "--pak":
        if len(args) < 2:
            print("Usage: package_mod.py --pak <ModName>")
            sys.exit(1)
        sys.exit(pak_mod(args[1]))

    else:
        # Positional: package_mod.py <ModName>
        sys.exit(package_mod(args[0]))

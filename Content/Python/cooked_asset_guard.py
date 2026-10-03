"""
cooked_asset_guard.py
=====================
Pre-staging guard for core-package cooks ("Cook & Export Asset Overrides").

Detects the signature of custom sequencer evaluation loss: a cooked package that contains
AbramsSequencer track classes but no serialized '/Script/...Evaluate' template literals.

Baselines are captured by the BlueprintUncooker plugin when a cooked source is uncooked
(Saved/AssetBaselines/<package>.txt). When a baseline exists, every baseline literal must
still be present in the cooked output. Without a baseline, a heuristic is used (custom track
names present but zero evaluation literals).

See Saved/uncooker_investigation_report.md (findings F2/F3, measure M1).
"""
from __future__ import annotations

import re
from pathlib import Path

# Serialized FMovieSceneEvalTemplatePtr type names, e.g.
#   /Script/AbramsSequencer.AbramsSequencerSetUMGMaterialScalarParameterEvaluate
EVAL_LITERAL_RE = re.compile(rb"/Script/[A-Za-z0-9_]+\.F?[A-Za-z0-9_]*Evaluate")

# Custom game track class names, e.g. AbramsSequencerSetUMGMaterialScalarParameterTrack
TRACK_NAME_RE = re.compile(rb"AbramsSequencer[A-Za-z0-9_]*Track")


def baseline_key(package_path: str) -> str:
    """Filesystem-safe key for a /Game package path (mirrors the C++ BaselinePackageKey)."""
    return package_path.replace("/", "__").replace(".", "_")


def read_package_bytes(cooked_dir: Path, base_name: str) -> bytes:
    """Concatenate all cooked sidecar bytes for one package (.uasset/.uexp/.ubulk)."""
    data = b""
    for suffix in (".uasset", ".uexp", ".ubulk"):
        path = Path(cooked_dir) / (base_name + suffix)
        if path.exists():
            try:
                data += path.read_bytes()
            except OSError:
                pass
    return data


def extract_eval_literals(data: bytes) -> set[str]:
    return {m.group().decode("ascii", "ignore") for m in EVAL_LITERAL_RE.finditer(data)}


def load_baseline(project_root: Path, package_path: str) -> set[str]:
    path = Path(project_root) / "Saved" / "AssetBaselines" / (baseline_key(package_path) + ".txt")
    if not path.exists():
        return set()
    try:
        text = path.read_text(encoding="utf-8", errors="ignore")
    except OSError:
        return set()
    return {line.strip() for line in text.splitlines() if line.strip()}


def verify_package(package_path: str, cooked_dir: Path, project_root: Path) -> str:
    """
    Verify one cooked package.

    Returns "" when the package is safe to stage, or a human-readable error string.
    """
    cooked_dir = Path(cooked_dir)
    base_name = package_path.rsplit("/", 1)[-1]
    data = read_package_bytes(cooked_dir, base_name)

    if not data:
        return f"no cooked files found ({base_name}.* in {cooked_dir})"

    found = extract_eval_literals(data)
    baseline = load_baseline(project_root, package_path)

    if baseline:
        missing = sorted(baseline - found)
        if missing:
            return (
                "cooked output lost serialized sequencer evaluation template(s) that were "
                "present in the game-original source:\n    "
                + "\n    ".join(missing)
                + "\n  The custom game sequencer track(s) will not evaluate at runtime. "
                "This is the uncooked-animation regression described in "
                "Saved/uncooker_investigation_report.md."
            )
        return ""

    # No baseline yet (asset was uncooked before the guard existed): use the heuristic.
    if TRACK_NAME_RE.search(data) and not found:
        return (
            "cooked output contains custom AbramsSequencer track classes but no serialized "
            "'/Script/...Evaluate' template literals. This is the signature of evaluation loss "
            "after an uncook -> cook round trip; refusing to stage. "
            "See Saved/uncooker_investigation_report.md."
        )

    return ""

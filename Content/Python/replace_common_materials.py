"""
replace_common_materials.py
===========================
Unreal Editor Python script.

For every Material/MaterialInterface asset in /Game/Commons/Materials/ whose
name matches one of the keyword rules below, this script:

  1. Deletes the existing asset.
  2. Duplicates the matching ModKit master material to the original package path.

Keyword → ModKit material mapping  (case-insensitive name check,
evaluated in priority order — first match wins):

  "Outline"     →  /Game/ModKit/Materials/M_CH_CelOutline_Masked
  "Face"        →  /Game/ModKit/Materials/M_CH_CelFace_Opaque
  "Translucent" →  /Game/ModKit/Materials/M_CH_Cel_Translucent
  "Opaque"      →  /Game/ModKit/Materials/M_CH_Cel_Opaque

Assets whose names match none of the keywords are left completely untouched.

Usage — JJK ModKit menu → Asset Tools → Replace Common Materials
     or UE Python console:
         import importlib, replace_common_materials
         importlib.reload(replace_common_materials)
         replace_common_materials.run()
"""

import unreal


# ─── Configuration ─────────────────────────────────────────────────────────────

SOURCE_FOLDER = "/Game/Commons/Materials"  # Content/Commons/Materials on disk
MODKIT_FOLDER = "/Game/ModKit/Materials"

# Priority-ordered keyword → ModKit asset name pairs.
# "Outline" and "Face" are checked before "Opaque" so that a name like
# "M_CelFace_Opaque" is matched by "Face", not "Opaque".
# "Translucent" is checked before "Opaque" for the same reason.
_KEYWORD_MAP: list[tuple[str, str]] = [
    ("Outline",     "M_CH_CelOutline_Masked"),
    ("Face",        "M_CH_CelFace_Opaque"),
    ("Translucent", "M_CH_Cel_Translucent"),
    ("Opaque",      "M_CH_Cel_Opaque"),
]


# ─── Helpers ───────────────────────────────────────────────────────────────────

def _find_modkit_material(asset_name: str) -> "unreal.MaterialInterface | None":
    """
    Return the ModKit MaterialInterface whose keyword matches *asset_name*,
    or None if no rule matches or the asset cannot be loaded.
    """
    name_lower = asset_name.lower()
    for keyword, modkit_name in _KEYWORD_MAP:
        if keyword.lower() in name_lower:
            path = f"{MODKIT_FOLDER}/{modkit_name}"
            mat  = unreal.load_asset(path)
            if mat is None:
                unreal.log_error(
                    f"[ReplaceCommonMats] ModKit material not found at '{path}'. "
                    "Ensure ModKit assets are imported before running this tool."
                )
            return mat   # return even if None so the caller can report the failure
    return None          # no keyword matched


# ─── Main ──────────────────────────────────────────────────────────────────────

def run() -> None:
    """
    Scan /Game/Commons/Materials/ (non-recursive) and, for every material whose
    name matches a keyword rule:

      1. Delete the original asset.
      2. Duplicate the matching ModKit master material to the original path.
    """
    # Force the asset registry to discover any on-disk assets in the source
    # folder that haven't been scanned yet (e.g. freshly imported files).
    registry = unreal.AssetRegistryHelpers.get_asset_registry()
    registry.scan_paths_synchronous([SOURCE_FOLDER], force_rescan=True)

    # List all assets in the source folder (top-level only)
    all_refs = unreal.EditorAssetLibrary.list_assets(
        SOURCE_FOLDER, recursive=False, include_folder=False
    )

    unreal.log(f"[ReplaceCommonMats] {len(all_refs)} asset ref(s) found in {SOURCE_FOLDER}")

    # Keep only MaterialInterface assets
    mat_refs = []
    for ref in all_refs:
        asset = unreal.load_asset(ref)
        if isinstance(asset, unreal.MaterialInterface):
            mat_refs.append(ref)
        else:
            unreal.log(f"[ReplaceCommonMats]   Skipped non-material ref: {ref}")

    if not mat_refs:
        unreal.log(
            f"[ReplaceCommonMats] No material assets found in {SOURCE_FOLDER} — nothing to do."
        )
        return

    unreal.log(
        f"[ReplaceCommonMats] Scanning {len(mat_refs)} material(s) in {SOURCE_FOLDER} …"
    )

    replaced = skipped = failed = 0

    with unreal.ScopedSlowTask(len(mat_refs), "Replacing Common Materials…") as slow:
        slow.make_dialog(True)

        for ref in mat_refs:
            if slow.should_cancel():
                unreal.log_warning("[ReplaceCommonMats] Cancelled by user.")
                break

            # ref looks like  /Game/Commons/Materials/M_Foo.M_Foo
            pkg_path   = ref.split(".")[0]               # /Game/Commons/Materials/M_Foo
            folder     = "/".join(pkg_path.split("/")[:-1])  # /Game/Commons/Materials
            asset_name = pkg_path.split("/")[-1]         # M_Foo

            slow.enter_progress_frame(1, asset_name)

            # ── FX materials → skip (Niagara-referenced, avoid DI count crash) ─
            if "_fx" in asset_name.lower():
                unreal.log(f"[ReplaceCommonMats]   FX material — skip: {asset_name}")
                skipped += 1
                continue

            # ── Resolve matching ModKit material ───────────────────────────────
            modkit_mat = _find_modkit_material(asset_name)
            if modkit_mat is None and _find_modkit_material(asset_name) is None:
                # Check whether it was truly a no-match or a load failure
                name_lower = asset_name.lower()
                if not any(kw.lower() in name_lower for kw, _ in _KEYWORD_MAP):
                    unreal.log(f"[ReplaceCommonMats]   No keyword matched — skip: {asset_name}")
                    skipped += 1
                else:
                    # Keyword matched but asset missing — already logged in helper
                    failed += 1
                continue

            # ── Step 1: delete the original ───────────────────────────────────
            deleted = unreal.EditorAssetLibrary.delete_asset(pkg_path)
            if not deleted:
                unreal.log_error(
                    f"[ReplaceCommonMats]   Delete failed for original: {pkg_path}"
                )
                failed += 1
                continue

            unreal.log(f"[ReplaceCommonMats]   Deleted original: {asset_name}")

            # ── Step 2: duplicate ModKit material to the original path ─────────
            modkit_pkg = f"{MODKIT_FOLDER}/{modkit_mat.get_name()}"
            duplicated = unreal.EditorAssetLibrary.duplicate_asset(modkit_pkg, pkg_path)
            if duplicated is None:
                unreal.log_error(
                    f"[ReplaceCommonMats]   duplicate_asset failed: {modkit_pkg} → {pkg_path}"
                )
                failed += 1
                continue

            unreal.EditorAssetLibrary.save_asset(pkg_path, only_if_is_dirty=False)

            unreal.log(
                f"[ReplaceCommonMats]   ✓ {asset_name}  (Material ← {modkit_mat.get_name()})"
            )
            replaced += 1

    unreal.log(
        f"[ReplaceCommonMats] ━━━ Complete ━━━  "
        f"replaced: {replaced},  skipped: {skipped},  failed: {failed}"
    )

"""
uncook_assets.py
================
Make cooked game assets editable for modding in JujutsuKaisen Cursed Clash.

Auto-detects the asset type and applies the appropriate strategy:

  ╔══════════════════════════════════╦═══════════════════════════════════════════╗
  ║ Asset type                       ║ Strategy                                  ║
  ╠══════════════════════════════════╬═══════════════════════════════════════════╣
  ║ Blueprintable UObject subclass   ║ Blueprint subclass (BlueprintFactory)     ║
  ║  e.g. GameWidgetParameterBase    ║ → open in Blueprint editor → Class Defs   ║
  ╠══════════════════════════════════╬═══════════════════════════════════════════╣
  ║ Texture2D / TextureCube / etc.   ║ Export to TGA → re-import at mod path     ║
  ║                                  ║ → edit TGA in Photoshop / GIMP / etc.     ║
  ╠══════════════════════════════════╬═══════════════════════════════════════════╣
  ║ Material / MaterialInstance      ║ Duplicate to a real editable Material     ║
  ║                                  ║ in a sibling Uncooked/ subfolder          ║
  ╠══════════════════════════════════╬═══════════════════════════════════════════╣
  ║ SkeletalMesh / Skeleton          ║ Silent FBX export → re-import as UE asset ║
  ║                                  ║ in a sibling Uncooked/ subfolder          ║
  ║                                  ║ All original settings preserved           ║
  ╚══════════════════════════════════╩═══════════════════════════════════════════╝

Destination conventions (defaults):
    General assets (Blueprints, Textures …)
        /Game/Characters/Mesh/SomeAsset
        → /Game/Mods/Uncooked/Characters/Mesh/SomeAsset

    Materials, SkeletalMeshes, Skeletons  (relative to the source asset)
        /Game/Characters/Materials/SomeMaterial
        → /Game/Characters/Materials/Uncooked/SomeMaterial

        /Game/Characters/Meshes/SK_Char
        → /Game/Characters/Meshes/Uncooked/SK_Char

Usage (UE Python console):
    import importlib, uncook_assets as ua
    importlib.reload(ua)

    # Uncook whatever is currently selected in the Content Browser:
    ua.uncook_selected()

    # Uncook a specific asset (auto-detect type):
    ua.uncook_one("/Game/Widgets/Commons/Parameters/GameWidgetSceneCaptureType_CharacterSelect_BP")

    # Uncook all assets in a folder:
    ua.uncook_folder(
        "/Game/Widgets/Commons/Parameters",
        dst_root="/Game/Mods/Uncooked",
    )
"""

from __future__ import annotations

import os
import unreal


# ─────────────────────────────────────────────────────────────────────────────
# Constants
# ─────────────────────────────────────────────────────────────────────────────

# Default root for general asset types (Blueprints, Textures …)
_DEFAULT_DST_ROOT = "/Game/Mods/Uncooked"


# ─────────────────────────────────────────────────────────────────────────────
# Helpers
# ─────────────────────────────────────────────────────────────────────────────

def _log(msg: str) -> None:
    unreal.log(f"[UncookAssets] {msg}")


def _err(msg: str) -> None:
    unreal.log_error(f"[UncookAssets] {msg}")


def _warn(msg: str) -> None:
    unreal.log_warning(f"[UncookAssets] {msg}")


def _default_dst(src_path: str, dst_root: str = _DEFAULT_DST_ROOT) -> str:
    """
    Derive a destination path by mirroring the source path under *dst_root*.

    /Game/Widgets/Commons/Parameters/Foo  →  /Game/Mods/Uncooked/Widgets/Commons/Parameters/Foo
    """
    stripped = src_path
    for prefix in ("/All/Game/", "/Game/"):
        if stripped.startswith(prefix):
            stripped = stripped[len(prefix):]
            break
    return dst_root.rstrip("/") + "/" + stripped


def _relative_dst(src_path: str, subdir: str = "Uncooked") -> str:
    """
    Place the uncooked copy in a sibling subfolder beside the source asset.

    /Game/A/B/Foo  →  /Game/A/B/Uncooked/Foo
    """
    folder = src_path.rsplit("/", 1)[0]
    name   = src_path.split("/")[-1]
    return f"{folder}/{subdir}/{name}"


def _asset_path_from_object(obj: unreal.Object) -> str:
    """Return the bare package path (/Game/.../Name) for a loaded UObject."""
    return obj.get_path_name().split(".")[0]


def _copy_bp_properties(src: unreal.Object, dst: unreal.Object) -> int:
    """
    Copy every Python-accessible UPROPERTY (BlueprintReadWrite) from src → dst.
    Returns the count of successfully copied properties.
    EditAnywhere-only properties (e.g. ParameterMap) are not accessible via
    Python reflection and must be set manually in Class Defaults.
    """
    copied = 0
    skipped: list[str] = []
    for attr in dir(src):
        if attr.startswith("_"):
            continue
        try:
            val = getattr(src, attr)
        except Exception:
            continue
        if callable(val):
            continue
        try:
            setattr(dst, attr, val)
            copied += 1
        except Exception as ex:
            skipped.append(attr)
    if skipped:
        _warn(f"  Skipped (not writable via Python): {', '.join(skipped[:8])}"
              + ("…" if len(skipped) > 8 else ""))
    return copied


# ─────────────────────────────────────────────────────────────────────────────
# Strategy: Blueprintable UObject → Blueprint subclass
# ─────────────────────────────────────────────────────────────────────────────

def uncook_blueprintable_object(src_obj: unreal.Object, dst_path: str) -> bool:
    """
    Create an editable Blueprint subclass of *src_obj*'s C++ class at
    *dst_path*, then copy ALL UPROPERTY values — including EditAnywhere-only
    bitfields invisible to Python — from *src_obj* to the new Blueprint's CDO.

    Delegates to C++ UncookLibrary.UncookBlueprintableObject which iterates
    every TFieldIterator<FProperty> (no BlueprintReadWrite filter) and copies
    each non-transient property directly between memory addresses.  This is the
    only reliable way to populate parameter assets like GameWidgetParameterBase
    whose ParameterMap and similar fields have no Python exposure.
    """
    try:
        ok = unreal.UncookLibrary.uncook_blueprintable_object(src_obj, dst_path)
    except AttributeError:
        _err(
            "  unreal.UncookLibrary not found — compile and enable JJKModKit "
            "plugin first, then restart the editor."
        )
        return False

    if ok:
        _log(f"  ✓ Blueprint → {dst_path}")
        _log(f"  Open in Blueprint editor → Class Defaults to verify all properties.")
    else:
        _warn(f"  UncookBlueprintableObject returned false — check the Output Log.")
    return ok


# ─────────────────────────────────────────────────────────────────────────────
# Strategy: Texture → export TGA + re-import at mod path
# ─────────────────────────────────────────────────────────────────────────────

def uncook_texture(src_obj: unreal.Texture, dst_path: str) -> bool:
    """
    Duplicate the cooked Texture to *dst_path*, preserving every setting
    (SRGB, CompressionSettings, Filter, MipGenSettings, AddressX/Y, LODBias,
    LODGroup, bFlipGreenChannel, …) in C++ via UncookLibrary.UncookTexture.

    DuplicateAsset is tried first (zero-copy, atomic, all data preserved).
    Falls back to TGA export + reimport + property copy if the asset has no
    in-memory source data.
    """
    try:
        ok = unreal.UncookLibrary.uncook_texture(src_obj, dst_path, "")
    except AttributeError:
        _err(
            "  unreal.UncookLibrary not found — compile and enable JJKModKit "
            "plugin first, then restart the editor."
        )
        return False

    if ok:
        _log(f"  ✓ Texture → {dst_path}")
    else:
        _warn(f"  UncookTexture returned false — check the Output Log for details.")
    return ok


# ─────────────────────────────────────────────────────────────────────────────
# Strategy: Material → duplicate to a real editable Material
# ─────────────────────────────────────────────────────────────────────────────

def uncook_material(src_obj: unreal.MaterialInterface, dst_path: str) -> bool:
    """
    Duplicate the root Material of *src_obj* (resolving any MaterialInstance
    chain) to *dst_path*, producing a fully editable Material with all
    properties intact.

    Delegates to C++ UncookLibrary.UncookMaterial which uses
    IAssetTools::DuplicateAsset so the entire UMaterial object graph (blend
    mode, shading model, usage flags, parameter defaults, static switches, …)
    is carried over atomically — including fields that Python cannot write.
    """
    try:
        ok = unreal.UncookLibrary.uncook_material(src_obj, dst_path)
    except AttributeError:
        _err(
            "  unreal.UncookLibrary not found — compile and enable JJKModKit "
            "plugin first, then restart the editor."
        )
        return False

    if ok:
        _log(f"  ✓ Material → {dst_path}")
    else:
        _warn(f"  UncookMaterial returned false — check the Output Log for details.")
    return ok


def uncook_material_instance(src_obj: unreal.MaterialInstance, dst_path: str) -> bool:
    """Route MaterialInstance to the C++ UncookMaterial (which resolves the chain)."""
    return uncook_material(src_obj, dst_path)


# ─────────────────────────────────────────────────────────────────────────────
# Strategy: SkeletalMesh → FBX export + re-import as UE asset
# ─────────────────────────────────────────────────────────────────────────────

def uncook_skeletal_mesh(
    src_obj:    unreal.SkeletalMesh,
    dst_path:   str,
    export_dir: str | None = None,
) -> bool:
    """
    Export the cooked SkeletalMesh to FBX and re-import it as a new editable
    SkeletalMesh asset at *dst_path*.

    Delegates entirely to the C++ UncookLibrary.UncookMesh() function in the
    JJKModKit plugin, which has full UPROPERTY access and can set every
    FbxSkeletalMeshImportData bitfield that is invisible to Python in UE 5.1:

      bImportMorphTargets          = true
      bPreserveSmoothingGroups     = true
      bImportMeshesInBoneHierarchy = true
      bUseT0AsRefPose              = false
      bConvertScene                = true   (+ bForceFrontXAxis = false)
      Skeleton                     = reused from source mesh

    The intermediate FBX is saved in *export_dir* (or Saved/UncookedMeshes/
    by default) so you can open it in Blender / Maya for further editing.
    """
    fbx_dir = export_dir or os.path.join(
        unreal.Paths.project_saved_dir(), "UncookedMeshes"
    ).replace("\\", "/")
    os.makedirs(fbx_dir, exist_ok=True)

    try:
        ok = unreal.UncookLibrary.uncook_mesh(src_obj, dst_path, fbx_dir)
    except AttributeError:
        _err(
            "  unreal.UncookLibrary not found — compile and enable the JJKModKit "
            "plugin first, then restart the editor."
        )
        return False

    if ok:
        _log(f"  ✓ SkeletalMesh uncooking → {dst_path}")
        _log(f"  FBX in: {fbx_dir}/{src_obj.get_name()}.fbx")
    else:
        _warn(f"  UncookMesh returned false — check the Output Log for details.")
    return ok


def uncook_skeleton(
    src_obj:    unreal.Skeleton,
    dst_path:   str,
    export_dir: str | None = None,
) -> bool:
    """
    Export the Skeleton's reference pose to FBX and re-import it as a
    standalone Skeleton asset at *dst_path*.

    In most cases you should uncook the owning SkeletalMesh instead — the
    skeleton is embedded in that FBX and will be (re)created alongside it.
    This function handles cases where you need only the Skeleton asset itself.
    """
    src_name = src_obj.get_name()

    if export_dir is None:
        export_dir = os.path.join(
            unreal.Paths.project_saved_dir(), "UncookedMeshes"
        ).replace("\\", "/")
    os.makedirs(export_dir, exist_ok=True)

    fbx_path = f"{export_dir}/{src_name}.fbx"

    # ── 1. Export to FBX (fully silent — no options dialog) ──────────────────
    export_task = unreal.AssetExportTask()
    export_task.object            = src_obj
    export_task.filename          = fbx_path
    export_task.selected          = False
    export_task.replace_identical = True
    export_task.prompt            = False
    export_task.automated         = True

    try:
        fbx_export_opts = unreal.FbxExportOption()
        fbx_export_opts.collision       = False
        fbx_export_opts.vertex_color    = True
        fbx_export_opts.level_of_detail = False
        export_task.options = fbx_export_opts
    except Exception:
        pass  # FbxExportOption unavailable in this build — automated flag covers it

    unreal.Exporter.run_asset_export_task(export_task)

    if not os.path.exists(fbx_path):
        _err(f"  Skeleton FBX export failed — file not found: {fbx_path}")
        return False

    _log(f"  Exported Skeleton FBX → {fbx_path}")

    # ── 2. Re-import as SkeletalMesh (skeleton embedded) ─────────────────────
    dst_name   = dst_path.split("/")[-1]
    dst_folder = dst_path.rsplit("/", 1)[0]

    import_ui = unreal.FbxImportUI()
    import_ui.import_mesh                        = True
    import_ui.import_as_skeletal                 = True
    import_ui.import_materials                   = False
    import_ui.import_textures                    = False
    import_ui.import_animations                  = False
    import_ui.automated_import_should_detect_type = False
    import_ui.mesh_type_to_import                = unreal.FBXImportType.FBXIT_SKELETAL_MESH

    sk = import_ui.skeletal_mesh_import_data
    sk.convert_scene      = True   # bool, BlueprintReadWrite (FbxAssetImportData)
    sk.force_front_x_axis = False  # bool, BlueprintReadWrite (FbxAssetImportData)

    import_task = unreal.AssetImportTask()
    import_task.filename         = fbx_path
    import_task.destination_path = dst_folder
    import_task.destination_name = dst_name
    import_task.replace_existing = True
    import_task.automated        = True
    import_task.save             = True
    import_task.options          = import_ui

    unreal.AssetToolsHelpers.get_asset_tools().import_asset_tasks([import_task])

    exists = unreal.EditorAssetLibrary.does_asset_exist(dst_path)
    if exists:
        _log(f"  ✓ Skeleton re-imported → {dst_path}")
        _log(f"  FBX kept at: {fbx_path}")
    else:
        _warn(f"  Re-import may have failed — check {dst_path}")
        _log(f"  FBX available for manual import: {fbx_path}")
    return exists


# ─────────────────────────────────────────────────────────────────────────────
# Auto-dispatch
# ─────────────────────────────────────────────────────────────────────────────

def uncook_one(src_path: str, dst_root: str = _DEFAULT_DST_ROOT) -> bool:
    """
    Load *src_path*, detect its type, and apply the appropriate uncook strategy.

    Destination roots (defaults):
        Textures / Blueprints / other  →  /Game/Mods/Uncooked/<mirrored-path>
        Material / SkeletalMesh        →  <source_folder>/Uncooked/<name>

    Override *dst_root* to change where Texture/Blueprint uncooked assets land.
    Material and mesh destinations are always relative to the source asset.
    """
    src_obj = unreal.load_asset(src_path)
    if src_obj is None:
        _err(f"Cannot load: {src_path}")
        return False

    _log(f"Uncooking  {src_path}")
    _log(f"     class: {src_obj.get_class().get_name()}")

    # ── Dispatch by type ──────────────────────────────────────────────────────
    if isinstance(src_obj, unreal.Texture):
        dst_path = _default_dst(src_path, dst_root)
        _log(f"        →  {dst_path}")
        return uncook_texture(src_obj, dst_path)

    # Materials → sibling Uncooked/ subfolder relative to the source asset
    if isinstance(src_obj, unreal.MaterialInstance):
        dst_path = _relative_dst(src_path)
        _log(f"        →  {dst_path}")
        return uncook_material_instance(src_obj, dst_path)

    if isinstance(src_obj, unreal.Material):
        dst_path = _relative_dst(src_path)
        _log(f"        →  {dst_path}")
        return uncook_material(src_obj, dst_path)

    # SkeletalMesh / Skeleton → sibling Uncooked/ subfolder relative to the source
    if isinstance(src_obj, unreal.SkeletalMesh):
        dst_path = _relative_dst(src_path)
        _log(f"        →  {dst_path}")
        return uncook_skeletal_mesh(src_obj, dst_path)

    if isinstance(src_obj, unreal.Skeleton):
        dst_path = _relative_dst(src_path)
        _log(f"        →  {dst_path}")
        return uncook_skeleton(src_obj, dst_path)

    dst_path = _default_dst(src_path, dst_root)
    _log(f"        →  {dst_path}")

    # Fallback: try as a Blueprintable UObject (e.g. GameWidgetParameterBase)
    cls = src_obj.get_class()
    if isinstance(src_obj, (unreal.Blueprint, unreal.BlueprintGeneratedClass)):
        _warn(f"  {src_obj.get_name()} is a Blueprint — use the BlueprintUncooker "
              f"plugin instead (right-click → Uncook Blueprint).")
        return False

    _log(f"  No dedicated strategy for {cls.get_name()} — "
         f"attempting Blueprint-subclass uncook.")
    return uncook_blueprintable_object(src_obj, dst_path)


def uncook_selected(dst_root: str = _DEFAULT_DST_ROOT) -> None:
    """
    Uncook every asset currently selected in the Content Browser.
    Call this from a menu entry or the Python console.
    """
    try:
        selected = unreal.EditorUtilityLibrary.get_selected_assets()
    except Exception as ex:
        _err(f"get_selected_assets failed: {ex}")
        return

    if not selected:
        _warn("No assets selected.")
        return

    ok = fail = 0
    for asset in selected:
        src_path = _asset_path_from_object(asset)
        if uncook_one(src_path, dst_root):
            ok += 1
        else:
            fail += 1

    _log(f"Done — {ok} succeeded, {fail} failed.")


def uncook_folder(
    src_folder: str,
    dst_root:   str  = _DEFAULT_DST_ROOT,
    recursive:  bool = False,
) -> None:
    """
    Uncook every asset under *src_folder*.

    Example:
        ua.uncook_folder("/Game/Widgets/Commons/Parameters",
                         dst_root="/Game/Mods/MyMod")
    """
    ar     = unreal.AssetRegistryHelpers.get_asset_registry()
    assets = ar.get_assets_by_path(src_folder, recursive=recursive)

    if not assets:
        _warn(f"No assets found in: {src_folder}")
        return

    ok = fail = 0
    for ad in assets:
        src_path = f"{src_folder}/{ad.asset_name}"
        if uncook_one(src_path, dst_root):
            ok += 1
        else:
            fail += 1

    _log(f"Done — {ok}/{len(assets)} succeeded  ({src_folder})")

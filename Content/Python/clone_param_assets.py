"""
clone_param_assets.py
=====================
Create editable, moddable Blueprint copies of cooked
UGameWidgetCharacterSceneCaptureParameter / UGameWidgetSceneCaptureTypeParameter
(and any other UGameParameterBase subclass) assets.

Why a Blueprint subclass instead of a direct duplicate?
  - Direct Duplicate fails: "Package is cooked or missing editor data"
  - DataAssetFactory fails: these classes inherit UObject, not UDataAsset
  - BlueprintFactory succeeds: all UGameParameterBase classes are
    UCLASS(Blueprintable), so BlueprintFactory accepts them as parent classes.
  - The Blueprint CDO stores the same EditAnywhere properties and is
    fully editable via the Class Defaults tab.
  - The Blueprint can be cooked and packaged as part of a mod.

Usage (UE Python console):
    import importlib, clone_param_assets as cp
    importlib.reload(cp)

    # Inspect a single cooked asset's property values:
    cp.dump_param("/Game/Widgets/Commons/Parameters/GameWidgetSceneCaptureType_CharacterSelect_BP")

    # Clone one asset to your mod folder:
    cp.clone_one(
        src="/Game/Widgets/Commons/Parameters/GameWidgetSceneCaptureType_CharacterSelect_BP",
        dst="/Game/Mods/MyMod/Parameters/GameWidgetSceneCaptureType_CharacterSelect_BP",
    )

    # Clone every asset in the Parameters folder at once:
    cp.clone_all(
        src_folder="/Game/Widgets/Commons/Parameters",
        dst_folder="/Game/Mods/MyMod/Parameters",
    )
"""

from __future__ import annotations

import unreal


# ─────────────────────────────────────────────────────────────────────────────
# Helpers
# ─────────────────────────────────────────────────────────────────────────────

def _log(msg: str) -> None:
    unreal.log(f"[CloneParam] {msg}")


def _err(msg: str) -> None:
    unreal.log_error(f"[CloneParam] {msg}")


def _warn(msg: str) -> None:
    unreal.log_warning(f"[CloneParam] {msg}")


def _copy_properties(src: unreal.Object, dst: unreal.Object) -> int:
    """
    Copy every Python-accessible UPROPERTY from *src* to *dst*.
    Returns the number of properties successfully copied.

    Properties without BlueprintReadWrite may not be accessible via Python —
    they are silently skipped.  Use dump_param() first to see which ones
    transfer before running a batch clone.
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
            skipped.append(f"{attr}: {ex}")

    if skipped:
        _warn(f"  Skipped {len(skipped)} props: " + ", ".join(skipped[:5]) +
              ("…" if len(skipped) > 5 else ""))
    return copied


# ─────────────────────────────────────────────────────────────────────────────
# Public API
# ─────────────────────────────────────────────────────────────────────────────

def dump_param(src_path: str) -> None:
    """
    Print all readable UPROPERTY values from a cooked parameter asset.

    Run this first to see what values need to be transferred, and to confirm
    that Python can access the EditAnywhere-only properties.

    Example:
        cp.dump_param("/Game/Widgets/Commons/Parameters/GameWidgetSceneCaptureType_CharacterSelect_BP")
    """
    src = unreal.load_asset(src_path)
    if src is None:
        _err(f"Cannot load: {src_path}")
        return

    _log(f"=== {src_path}")
    _log(f"    Class : {src.get_class().get_name()}")
    _log(f"    Parent: {src.get_class().get_super_class().get_name()}")
    _log("    Properties:")

    found = 0
    for attr in sorted(dir(src)):
        if attr.startswith("_"):
            continue
        try:
            val = getattr(src, attr)
        except Exception:
            continue
        if callable(val):
            continue
        _log(f"      {attr} = {val!r}")
        found += 1

    _log(f"    ({found} properties printed)")


def clone_one(src: str, dst: str, copy_props: bool = True) -> bool:
    """
    Clone a single cooked parameter asset as an editable Blueprint.

    Parameters
    ----------
    src          : Content-browser path to the cooked source, e.g.
                   "/Game/Widgets/Commons/Parameters/GameWidgetSceneCaptureType_CharacterSelect_BP"
    dst          : Destination path, e.g.
                   "/Game/Mods/MyMod/Parameters/GameWidgetSceneCaptureType_CharacterSelect_BP"
    copy_props   : Attempt to copy UPROPERTY values from the cooked source
                   into the Blueprint CDO.  Requires the props to be Python-
                   accessible (BlueprintReadWrite or accessible via reflection).

    Returns True on success.
    """
    src_obj = unreal.load_asset(src)
    if src_obj is None:
        _err(f"Cannot load source: {src}")
        return False

    src_class = src_obj.get_class()
    dst_name   = dst.split("/")[-1]
    dst_folder = dst.rsplit("/", 1)[0]

    # Guard: don't overwrite an existing mod asset unless it's a Blueprint
    existing = unreal.load_asset(dst)
    if existing is not None and not isinstance(existing, unreal.Blueprint):
        _warn(f"Destination already exists and is not a Blueprint — skipping: {dst}")
        return False

    # Create a Blueprint subclass of the same C++ parent.
    # This works because all UGameParameterBase-derived classes are
    # UCLASS(Blueprintable).
    factory = unreal.BlueprintFactory()
    factory.parent_class = src_class

    at     = unreal.AssetToolsHelpers.get_asset_tools()
    new_bp = at.create_asset(dst_name, dst_folder, unreal.Blueprint, factory)

    if new_bp is None:
        _err(f"create_asset failed for {dst_name}. "
             f"Parent class = {src_class.get_name()}")
        return False

    # Optionally copy property values from the cooked CDO into the new CDO.
    if copy_props:
        # src_obj IS the CDO of the cooked BPGC (the stored object in a cooked
        # .uasset for a plain-UObject-derived class is the CDO itself).
        # new_bp.generated_class is not always available in Python; fall back
        # to accessing the new Blueprint's CDO via the class registry.
        new_cdo = None
        try:
            gen_class = new_bp.generated_class()        # method call in some UE5 versions
            if gen_class:
                new_cdo = gen_class.get_default_object()
        except Exception:
            pass

        if new_cdo is None:
            # Alternative: load the freshly-saved package's default object
            try:
                new_cdo = unreal.load_object(None, dst + "." + dst_name + "_C:Default__" + dst_name + "_C")
            except Exception:
                pass

        if new_cdo is not None:
            n = _copy_properties(src_obj, new_cdo)
            _log(f"  Copied {n} property/ies from cooked CDO → Blueprint CDO")
        else:
            _warn("  Could not obtain Blueprint CDO for property copy — "
                  "open the Blueprint and set Class Defaults manually.")

    # Compile so the Blueprint is in a valid state before saving
    try:
        unreal.BlueprintEditorLibrary.compile_blueprint(new_bp)
    except Exception as ex:
        _warn(f"  BlueprintEditorLibrary.compile_blueprint: {ex} (non-fatal)")

    saved = unreal.EditorAssetLibrary.save_asset(dst, only_if_is_dirty=False)
    if saved:
        _log(f"OK  {dst}")
    else:
        _warn(f"save_asset returned False for {dst}")

    return saved


def clone_all(
    src_folder: str = "/Game/Widgets/Commons/Parameters",
    dst_folder: str = "/Game/Mods/MyMod/Parameters",
    recursive:  bool = False,
) -> None:
    """
    Clone every cooked parameter asset in *src_folder* to *dst_folder*.

    Example:
        cp.clone_all(
            src_folder="/Game/Widgets/Commons/Parameters",
            dst_folder="/Game/Mods/MyMod/Parameters",
        )
    """
    ar     = unreal.AssetRegistryHelpers.get_asset_registry()
    assets = ar.get_assets_by_path(src_folder, recursive=recursive)

    if not assets:
        _warn(f"No assets found in {src_folder}")
        return

    ok = fail = 0
    for ad in assets:
        name     = str(ad.asset_name)
        src_path = f"{src_folder}/{name}"
        dst_path = f"{dst_folder}/{name}"
        if clone_one(src_path, dst_path):
            ok += 1
        else:
            fail += 1

    _log(f"Done — {ok} cloned, {fail} failed  ({src_folder} → {dst_folder})")

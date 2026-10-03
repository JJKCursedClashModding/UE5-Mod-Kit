"""
fix_widget_bindings.py
======================
Batch repair + pre-cook validation for the BindWidget problem.

Background
----------
Widget Blueprints whose C++ parent declares Instanced UWidget* properties
WITHOUT meta=(BindWidget) fail to recompile after BlueprintUncooker rebuilds
them ("Tried to create a property X ... but another object already exists").
The cook saves the broken package anyway, and the game dies at load with:

    WidgetTree.TopWidget: Serial size mismatch: Expected 10, Actual 7

The uncooker now patches Source/**/*.h automatically on every uncook, but
already-uncooked assets (and assets uncooked before the plugin rebuild) still
need the repair. This script applies it in bulk and gates the cook.

Usage (UE Python console):
    import importlib, fix_widget_bindings as fw
    importlib.reload(fw)

    # Repair one asset (patches headers on disk, transient stamp for now):
    fw.fix_one("/Game/Widgets/VisualLobby/WBP_VisualLobbyCharacterSelect")

    # Repair every Widget Blueprint under a folder:
    fw.fix_folder("/Game/Widgets/VisualLobby")

    # Repair ALL widgets in the project at once (recursive, WidgetBlueprints
    # only — textures/materials are skipped without loading). One line, then
    # rebuild once if anything was patched:
    fw.fix_all_widgets()

    # Dry-run check before cooking — returns False when a cook would be corrupt:
    fw.validate(["/Game/Widgets/VisualLobby/WBP_VisualLobbyCharacterSelect"])

After any "PATCHED" result you MUST rebuild before recooking:
    .\\build.ps1            (editor closed)
    # or Ctrl+Alt+F11 inside the editor, then recook
"""

from __future__ import annotations

import os

import unreal


def _log(msg: str) -> None:
    unreal.log(f"[FixWidgetBindings] {msg}")


def _err(msg: str) -> None:
    unreal.log_error(f"[FixWidgetBindings] {msg}")


def _warn(msg: str) -> None:
    unreal.log_warning(f"[FixWidgetBindings] {msg}")


def _have_api() -> bool:
    try:
        lib = unreal.BlueprintUncookerLibrary
    except AttributeError:
        return False
    return hasattr(lib, "ensure_bind_widget_headers") and hasattr(lib, "validate_widget_bindings")


def fix_one(asset_path: str) -> str:
    """Repair BindWidget headers for one Widget Blueprint. Returns status string."""
    if not _have_api():
        _err("unreal.BlueprintUncookerLibrary.ensure_bind_widget_headers not found — "
             "rebuild the project (build.ps1) with the updated BlueprintUncooker plugin first.")
        return "ERROR: BlueprintUncooker API missing (rebuild required)"
    status = unreal.BlueprintUncookerLibrary.ensure_bind_widget_headers(asset_path)
    if status.startswith("ERROR"):
        _err(f"{asset_path} — {status}")
    elif "HeadersPatched" in status and "HeadersPatched:0" not in status:
        _warn(f"{asset_path} — {status}")
    else:
        _log(f"{asset_path} — {status}")
    return status


def validate(asset_paths: list) -> bool:
    """
    Dry-run check for *asset_paths*. Returns True when every asset is clean.
    Prints the offending Class::Property list for anything that would cook corrupt.
    """
    if not _have_api():
        _err("unreal.BlueprintUncookerLibrary.validate_widget_bindings not found — "
             "rebuild the project (build.ps1) first.")
        return False
    ok = True
    for path in asset_paths:
        status = unreal.BlueprintUncookerLibrary.validate_widget_bindings(path)
        if status.startswith("OK"):
            _log(f"{path} — clean")
        else:
            ok = False
            _err(f"{path} — {status}")
    return ok


def _needs_rebuild(status: str) -> bool:
    """True when a status string means the cook must wait for a rebuild."""
    import re as _re
    m_p = _re.search(r"HeadersPatched:(\d+)", status)
    m_s = _re.search(r"AlreadyOnDisk:(\d+)", status)
    return (int(m_p.group(1)) if m_p else 0) > 0 or (int(m_s.group(1)) if m_s else 0) > 0


def find_widget_blueprints(root: str = "/Game/Widgets") -> list:
    """
    Return package paths (/Game/.../Name, no extension) for every Widget
    Blueprint under *root*.

    Registry first (class-filtered, no per-asset loads). Note: in UE5
    AssetData.asset_class is a TopLevelAssetPath struct, NOT a plain name —
    callers must test containment ("WidgetBlueprint" in str(...)), never
    equality, or every asset is silently excluded.

    Disk fallback: when the registry comes back empty (e.g. right after editor
    startup before background discovery finishes), walk Content for
    WBP_*.uasset files and derive package paths. ensure() still validates
    each candidate, so non-widgets are skipped safely.
    """
    found: list = []
    try:
        ar = unreal.AssetRegistryHelpers.get_asset_registry()
        try:
            ar.scan_paths_synchronous([root])
        except Exception as ex:
            _log(f"registry rescan skipped: {ex}")
        try:
            assets = ar.get_assets_by_path(root, recursive=True)
        except Exception as ex:
            _log(f"asset query failed for {root}: {ex}")
            assets = []
        for ad in assets or []:
            try:
                cls = str(getattr(ad, "asset_class", "") or "")
            except Exception:
                cls = ""
            if cls and "WidgetBlueprint" not in cls:
                continue
            # Empty/missing class info: keep as candidate; ensure() validates.
            try:
                found.append(str(ad.package_name))
            except Exception:
                continue
    except Exception as ex:
        _log(f"registry search failed: {ex}")
    if found:
        return sorted(set(found))
    # ── Disk fallback: WBP_*.uasset walk ──────────────────────────────────
    try:
        content_dir = str(unreal.Paths.project_content_dir())
    except Exception as ex:
        _err(f"disk fallback unavailable (no content dir): {ex}")
        return []
    rel_root = root[len("/Game/"):].replace("/", os.sep) if root.startswith("/Game/") else ""
    disk_root = os.path.join(content_dir, rel_root) if rel_root else content_dir
    disk_found: list = []
    for dirpath, _dirnames, filenames in os.walk(disk_root):
        for fn in filenames:
            if not fn.endswith(".uasset") or not fn.startswith("WBP_"):
                continue
            try:
                rel = os.path.relpath(os.path.join(dirpath, fn), content_dir)
            except Exception:
                continue
            disk_found.append("/Game/" + rel[:-len(".uasset")].replace(os.sep, "/"))
    if disk_found:
        _log(f"registry empty — disk fallback found {len(disk_found)} WBP_*.uasset file(s) under {root}")
    return sorted(set(disk_found))


def fix_folder(content_dir: str) -> None:
    """
    Repair every Widget Blueprint directly under *content_dir*.

    Example:
        fix_folder("/Game/Widgets/VisualLobby")
    """
    if not _have_api():
        _err("BlueprintUncooker API missing — rebuild first (build.ps1).")
        return
    ar = unreal.AssetRegistryHelpers.get_asset_registry()
    assets = ar.get_assets_by_path(content_dir, recursive=False)
    if not assets:
        _warn(f"No assets found in: {content_dir}")
        return
    fixed = clean = failed = 0
    for ad in assets:
        pkg = f"{content_dir}/{ad.asset_name}"
        obj = unreal.load_asset(pkg)
        if obj is None:
            continue
        if not isinstance(obj, (unreal.WidgetBlueprint, unreal.Blueprint)):
            continue
        # Only Widget Blueprints can hit the BindWidget collision.
        if not isinstance(obj, unreal.WidgetBlueprint):
            continue
        status = fix_one(pkg)
        if status.startswith("ERROR"):
            failed += 1
        elif _needs_rebuild(status):
            fixed += 1
        else:
            clean += 1
    _log(f"Done — {fixed} patched, {clean} already clean, {failed} failed ({content_dir})")
    if fixed:
        _warn("Headers were patched — REBUILD (build.ps1 / Ctrl+Alt+F11) before recooking.")


def fix_all_widgets(root: str = "/Game/Widgets") -> None:
    """
    Repair every Widget Blueprint under *root*, recursively.

    This is the mass fix: one call covers all widget screens (VisualLobby,
    FreeBattle, CharacterSelect, Shop, Story, …). Textures, materials and
    other non-Blueprint assets are skipped via the registry class filter
    without loading them. Already-clean assets report clean; only genuine
    variable-widget collisions patch headers.

    After any "patched" result: REBUILD (close editor → .\\build.ps1),
    then cook. Steady state is silent — rerunning this later should report
    everything already clean.

    Example:
        fix_all_widgets()                      # whole /Game/Widgets tree
        fix_all_widgets("/Game/Widgets/Shop")  # one subtree
    """
    if not _have_api():
        _err("BlueprintUncooker API missing — rebuild first (build.ps1).")
        return
    import unreal as _u
    pkgs = find_widget_blueprints(root)
    if not pkgs:
        _warn(f"No Widget Blueprints found under: {root}")
        return
    _log(f"Checking {len(pkgs)} Widget Blueprint(s) under {root} …")
    fixed = clean = failed = 0
    with _u.ScopedSlowTask(max(len(pkgs), 1), "Repairing BindWidget headers…") as task:
        task.make_dialog(True)
        for pkg in sorted(pkgs):
            if task.should_cancel():
                _warn("Cancelled by user.")
                break
            task.enter_progress_frame(1, pkg.rsplit("/", 1)[-1])
            try:
                status = fix_one(pkg)
            except Exception as ex:
                _err(f"{pkg} — {ex}")
                failed += 1
                continue
            if "not a Widget Blueprint" in status:
                # Disk-fallback candidate that isn't a Widget Blueprint
                # (e.g. a misnamed texture) — correctly skipped, not a failure.
                clean += 1
            elif status.startswith("ERROR"):
                failed += 1
            elif _needs_rebuild(status):
                fixed += 1
            else:
                clean += 1
    _log(f"Done — {fixed} patched, {clean} already clean, {failed} failed ({root})")
    if fixed:
        _warn("Headers were patched — REBUILD (close editor → .\\build.ps1) before recooking.")


def dump_tree(asset_path: str, _depth: int = 0, _widget=None, _seen: set | None = None) -> None:
    """
    Print the Designer widget hierarchy for a Widget Blueprint.

    Use this to tell static slots from runtime-spawned ones:
      - Children listed here are STATIC Designer children — safe to add/remove.
      - Slots filled at runtime (UListView / UTileView / GameWidgetScrollListView
        like CharacterList) do NOT appear as icon children — their entries are
        spawned from an entry widget class + data array. More slots there means
        more DATA rows, not more Designer children.

    Example:
        dump_tree("/Game/Widgets/VisualLobby/WBP_VisualLobbyCharacterSelect")
    """
    if _depth == 0:
        wbp = unreal.load_asset(asset_path)
        if wbp is None:
            _err(f"Cannot load: {asset_path}")
            return
        try:
            tree = wbp.get_editor_property("widget_tree")
        except Exception as ex:
            _err(f"No widget_tree on {asset_path}: {ex}")
            return
        try:
            root = tree.get_editor_property("root_widget")
        except Exception as ex:
            _err(f"No root_widget: {ex}")
            return
        _log(f"Tree for {asset_path} (root: {root.get_name()} [{root.get_class().get_name()}])")
        dump_tree(asset_path, _depth=1, _widget=root, _seen=set())
        return

    if _widget is None:
        return
    if _seen is None:
        _seen = set()
    ident = _widget.get_name()
    if ident in _seen:
        _log(f"{'  ' * _depth}(cycle) {ident}")
        return
    _seen.add(ident)

    try:
        is_var = _widget.get_editor_property("b_is_variable")
    except Exception:
        is_var = "?"
    _log(f"{'  ' * _depth}- {ident} [{_widget.get_class().get_name()}] variable={is_var}")

    children: list = []
    for accessor in ("get_all_children",):
        try:
            fn = getattr(_widget, accessor, None)
            if callable(fn):
                children = list(fn()) or []
                break
        except Exception:
            continue
    for child in children:
        dump_tree(asset_path, _depth=_depth + 1, _widget=child, _seen=_seen)

"""
stub_wbp_commons.py
===================
Unreal Editor Python script.

Creates placeholder Widget Blueprint stubs for the three character-capture
common widgets used by the game:

    /Game/Widgets/Commons/WBP_CharacterCaptureEnemy
    /Game/Widgets/Commons/WBP_CharacterCapturePlayer
    /Game/Widgets/Commons/WBP_CharacterCaptureSimple

If any of the assets already exist on disk the existing .uasset file is
removed first so create_asset can write a fresh stub in its place.

Usage — JJK ModKit menu → Asset Tools → Stub Character-Capture WBPs
     or UE Python console:
         import importlib, stub_wbp_commons
         importlib.reload(stub_wbp_commons)
         stub_wbp_commons.run()
"""

import os
import unreal


# ─── Targets ───────────────────────────────────────────────────────────────────

_WBP_TARGETS: list[tuple[str, str]] = [
    ("/Game/Widgets/Commons", "WBP_CharacterCaptureEnemy"),
    ("/Game/Widgets/Commons", "WBP_CharacterCapturePlayer"),
    ("/Game/Widgets/Commons", "WBP_CharacterCaptureSimple"),
]


# ─── Helpers ───────────────────────────────────────────────────────────────────

def _get_content_dir() -> str:
    """Return the absolute path to the project Content directory, no trailing slash."""
    raw = unreal.Paths.convert_relative_path_to_full(unreal.Paths.project_content_dir())
    return raw.replace('\\', '/').rstrip('/')


# ─── Main ──────────────────────────────────────────────────────────────────────

def run() -> None:
    """
    Create Widget Blueprint stubs for the three character-capture WBPs:

        WBP_CharacterCaptureEnemy
        WBP_CharacterCapturePlayer
        WBP_CharacterCaptureSimple

    All stubs are placed under  /Game/Widgets/Commons/  with
    UserWidget as the parent class.  Any existing on-disk .uasset at each
    target path is removed first so create_asset always writes a clean file.
    """
    content_dir = _get_content_dir()
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

    ok = fail = 0

    with unreal.ScopedSlowTask(len(_WBP_TARGETS), 'Creating character-capture WBP stubs…') as slow:
        slow.make_dialog(True)

        for package_path, asset_name in _WBP_TARGETS:
            if slow.should_cancel():
                unreal.log_warning('[StubWBPCommons] Cancelled by user.')
                break

            slow.enter_progress_frame(1, asset_name)
            engine_path = f'{package_path}/{asset_name}'
            unreal.log(f'[StubWBPCommons] Processing {engine_path}')

            # ── Remove existing .uasset on disk (if any) ───────────────────────
            rel_package = package_path[len('/Game'):].lstrip('/')
            disk_out    = f'{content_dir}/{rel_package}/{asset_name}.uasset'

            if os.path.exists(disk_out):
                try:
                    os.remove(disk_out)
                    unreal.log(f'[StubWBPCommons]   Removed stale file: {disk_out}')
                except OSError as exc:
                    unreal.log_warning(
                        f'[StubWBPCommons]   Cannot remove "{disk_out}": {exc}'
                    )
                    fail += 1
                    continue

            # ── Create the stub Widget Blueprint ───────────────────────────────
            factory = unreal.WidgetBlueprintFactory()
            factory.set_editor_property('parent_class', unreal.UserWidget)

            stub = asset_tools.create_asset(
                asset_name   = asset_name,
                package_path = package_path,
                asset_class  = unreal.WidgetBlueprint,
                factory      = factory,
            )

            if stub is None:
                unreal.log_error(
                    f'[StubWBPCommons]   create_asset returned None for {engine_path}'
                )
                fail += 1
                continue

            unreal.EditorAssetLibrary.save_asset(engine_path, only_if_is_dirty=False)
            unreal.log(f'[StubWBPCommons]   ✓ {engine_path}')
            ok += 1

    unreal.log(
        f'[StubWBPCommons] ━━━ Complete ━━━  '
        f'created: {ok}, failed: {fail}'
    )

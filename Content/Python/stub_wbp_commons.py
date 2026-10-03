"""
stub_wbp_commons.py
===================
Unreal Editor Python script.

Creates placeholder Widget Blueprint stubs for the three character-capture
common widgets used by the game:

    /Game/Widgets/Commons/WBP_CharacterCaptureEnemy
    /Game/Widgets/Commons/WBP_CharacterCapturePlayer
    /Game/Widgets/Commons/WBP_CharacterCaptureSimple

Approach (v4 — direct uncook per target, no duplication step):
  Cooked imports ship _C classes only, so there is nothing loadable to
  duplicate from — and duplicate_asset output proved cold-parse hostile
  (fresh cooker/headless scans die on it while the uncooked source parses
  clean). Instead each target is produced by uncooking the surviving sibling
  WBP_CharacterCapture STRAIGHT into the target path. Every stub is then an
  independent, first-generation uncook product (proven cold-safe class),
  with a correctly-named skeleton, compiled and saved by the uncooker
  itself. No shared-subobject or duplication-provenance risk by construction.
The stubs exist only so dependent cooks resolve the import; they are never
staged (not in CorePackages), so the game keeps using the stock originals
at runtime.

NOTE: uncooking may auto-patch capture-widget C++ headers (variable matches).
If it reports patched headers, REBUILD (close editor → .\\build.ps1) before
the next cook. Save all work before running — uncooking runs the compiler.

Usage — JJK ModKit menu → Asset Tools → Stub Character-Capture WBPs
     or UE Python console:
         import importlib, stub_wbp_commons
         importlib.reload(stub_wbp_commons)
         stub_wbp_commons.run()
"""
from __future__ import annotations

import unreal


# ─── Targets ───────────────────────────────────────────────────────────────────

# Cooked _C-only source asset (reconstructed from bytecode, not duplicated).
_TEMPLATE_SOURCE = "/Game/Widgets/Commons/WBP_CharacterCapture"
_WBP_TARGETS: list[tuple[str, str]] = [
    ("/Game/Widgets/Commons", "WBP_CharacterCaptureEnemy"),
    ("/Game/Widgets/Commons", "WBP_CharacterCapturePlayer"),
    ("/Game/Widgets/Commons", "WBP_CharacterCaptureSimple"),
]


# ─── Main ──────────────────────────────────────────────────────────────────────

def run() -> None:
    """
    Uncook the surviving sibling directly into each of the three target
    paths (overwriting whatever is there — the uncooker evicts stale
    in-memory packages and saves a fresh compiled pair each time).
    """
    try:
        _uncook = unreal.BlueprintUncookerLibrary.uncook_blueprint_asset
    except AttributeError:
        unreal.log_error(
            "[StubWBPCommons] BlueprintUncooker API missing — "
            "rebuild (build.ps1) with the updated plugin first."
        )
        return

    ok = fail = 0
    patched_headers = False

    with unreal.ScopedSlowTask(len(_WBP_TARGETS), 'Creating character-capture WBP stubs…') as slow:
        slow.make_dialog(True)

        for package_path, asset_name in _WBP_TARGETS:
            if slow.should_cancel():
                unreal.log_warning('[StubWBPCommons] Cancelled by user.')
                break

            slow.enter_progress_frame(1, asset_name)
            engine_path = f'{package_path}/{asset_name}'
            # 2026-09-30: the game-original capture WBPs are installed in
            # the project and cook-safe — NEVER overwrite them with stubs.
            # (Uncook/duplicate products proved cold-parse hostile: cooker
            # dies with Array assertion 763 while June-shaped files parse.)
            try:
                if unreal.EditorAssetLibrary.does_asset_exist(engine_path):
                    unreal.log_warning(
                        f'[StubWBPCommons] SKIP {engine_path} — asset already '
                        f'exists (game original installed). Refusing to overwrite.'
                    )
                    continue
            except Exception:
                pass
            unreal.log(f'[StubWBPCommons] Uncooking {_TEMPLATE_SOURCE} → {engine_path} …')

            try:
                status = _uncook(_TEMPLATE_SOURCE, engine_path)
            except Exception as exc:
                unreal.log_error(f'[StubWBPCommons]   uncook raised for {engine_path}: {exc}')
                fail += 1
                continue

            unreal.log(f'[StubWBPCommons]   result: {status}')
            if isinstance(status, str) and status.startswith("ERROR"):
                fail += 1
                continue
            if (isinstance(status, str) and "HeadersPatched:" in status
                    and "HeadersPatched:0" not in status):
                patched_headers = True
            ok += 1

    if patched_headers:
        unreal.log_warning(
            "[StubWBPCommons] C++ headers were auto-patched during uncook — "
            "REBUILD (close editor → .\\build.ps1) before cooking with these stubs."
        )
    unreal.log(
        f'[StubWBPCommons] ━━━ Complete ━━━  '
        f'created: {ok}, failed: {fail}'
    )

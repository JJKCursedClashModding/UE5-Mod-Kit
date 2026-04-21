"""
settings_dialog.py — JujutsuKaisenCC ModKit Settings
=====================================================
Opens the native UE Project Settings panel to the JJK Mod Kit page.

Settings are stored in Config/DefaultGame.ini under
[/Script/JJKModKit.JJKModKitSettings] via a UDeveloperSettings class and
appear in Edit → Project Settings → Plugins → JJK Mod Kit.

Called via:
    import settings_dialog; settings_dialog.show()

Or indirectly through mod_tools:
    mod_tools.open_settings_dialog()
"""

from __future__ import annotations


def show() -> None:
    """
    Open the JJK Mod Kit section of the native Project Settings panel.

    Delegates to UJJKModKitLibrary.OpenJJKModKitSettings() (C++), which calls
    ISettingsModule::ShowViewer("Project", "Plugins", "JJKModKitSettings").

    Recompile the JJKModKit plugin if this reports the function is missing.
    """
    try:
        import unreal
    except ImportError:
        print(
            "[JJK ModKit] settings_dialog.show() must be called from inside "
            "the Unreal Editor."
        )
        return

    lib = getattr(unreal, "JJKModKitLibrary", None)
    if lib is None:
        unreal.log_error(
            "[JJK ModKit] UJJKModKitLibrary not found — "
            "please recompile the JJKModKit plugin and restart the editor."
        )
        return

    fn = getattr(lib, "open_jjk_mod_kit_settings", None)
    if fn is None:
        unreal.log_error(
            "[JJK ModKit] JJKModKitLibrary.open_jjk_mod_kit_settings() not found — "
            "please recompile the JJKModKit plugin."
        )
        return

    fn()

"""
init_unreal.py
==============
Executed automatically by the UE Editor Python plugin on every startup.
Adds a 'JJK ModKit' dropdown to the main menu bar containing
mod-utility commands for the JujutsuKaisen Cursed Clash project.
"""
from __future__ import annotations   # allows X | Y union hints on Python 3.9 (UE5.1)

import unreal


def _register_jjkcc_menu():
    menus = unreal.ToolMenus.get()

    # The main level-editor menu bar
    main_menu = menus.find_menu("LevelEditor.MainMenu")
    if not main_menu:
        unreal.log_warning("[JJK Mod Kit] LevelEditor.MainMenu not found — skipping menu registration.")
        return

    # Add our top-level dropdown (idempotent: harmless if already exists).
    # A named section must be added first; passing section_name="" would
    # register an empty section that renders as a blank menu in the bar.
    main_menu.add_section("JujutsuKaisenSection", "")
    jjk_menu = main_menu.add_sub_menu(
        owner       = main_menu.get_name(),
        section_name= "JujutsuKaisenSection",
        name        = "JujutsuKaisen",
        label       = "JJK Mod Kit",
        tool_tip    = "JujutsuKaisen Cursed Clash mod utilities",
    )

    # ── Section: Setup ─────────────────────────────────────────────────────
    jjk_menu.add_section("Setup", "Setup")

    entry_import = unreal.ToolMenuEntry(
        name            = "ImportGameAssets",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_import.set_label("Import Game Assets")
    entry_import.set_tool_tip(
        "Run the full game-asset import pipeline:\n\n"
        "  1. Convert pak files to legacy format  (retoc)\n"
        "  2. Create AnimBlueprint stubs from extracted content\n"
        "  3. Delete ABP_* / *_ABP files from the Data folder\n"
        "  4. Delete 3 character-capture WBPs from Data/.../Widgets/Commons\n"
        "  5. Move the extracted content into the project Content/ folder\n\n"
        "⚠  Uses ~50 GB of disk space and takes a long time.\n"
        "A confirmation dialog is shown before anything is changed."
    )
    entry_import.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, import_game_assets; "
            "importlib.reload(import_game_assets); "
            "import_game_assets.run()"
        ),
    )
    jjk_menu.add_menu_entry("Setup", entry_import)

    # ── Section: Asset Tools ────────────────────────────────────────────────
    jjk_menu.add_section("AssetTools", "Asset Tools")

    entry_stub = unreal.ToolMenuEntry(
        name            = "StubABPFromFolder",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_stub.set_label("Stub ABP From Folder")
    entry_stub.set_tool_tip(
        "Pick a folder and create placeholder AnimBlueprint stubs for all\n"
        "ABP_* assets inside it. Use this after importing game assets to\n"
        "prevent editor crashes on startup."
    )
    entry_stub.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, stub_abp_from_folder; "
            "importlib.reload(stub_abp_from_folder); "
            "stub_abp_from_folder.pick_and_run()"
        ),
    )
    jjk_menu.add_menu_entry("AssetTools", entry_stub)

    entry_stub_wbp = unreal.ToolMenuEntry(
        name            = "StubCharacterCaptureWBPs",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_stub_wbp.set_label("Stub Character-Capture WBPs")
    entry_stub_wbp.set_tool_tip(
        "Create placeholder Widget Blueprint stubs for the three\n"
        "character-capture common widgets:\n\n"
        "  • WBP_CharacterCaptureEnemy\n"
        "  • WBP_CharacterCapturePlayer\n"
        "  • WBP_CharacterCaptureSimple\n\n"
        "Each stub is a minimal UserWidget placed at\n"
        "/Game/Widgets/Commons/ — use this after importing game assets\n"
        "to prevent editor crashes caused by missing widget references."
    )
    entry_stub_wbp.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, stub_wbp_commons; "
            "importlib.reload(stub_wbp_commons); "
            "stub_wbp_commons.run()"
        ),
    )
    jjk_menu.add_menu_entry("AssetTools", entry_stub_wbp)

    entry_replace_mats = unreal.ToolMenuEntry(
        name            = "ReplaceCommonMaterials",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_replace_mats.set_label("Replace Common Materials")
    entry_replace_mats.set_tool_tip(
        "Replace matching materials in /Game/Commons/Materials/ with\n"
        "MaterialInstanceConstants parented to the ModKit master materials.\n\n"
        "Matching rules (first match wins, case-insensitive):\n"
        "  • Name contains 'Outline'     → M_CH_CelOutline_Masked\n"
        "  • Name contains 'Face'        → M_CH_CelFace_Opaque\n"
        "  • Name contains 'Translucent' → M_CH_Cel_Translucent\n"
        "  • Name contains 'Opaque'      → M_CH_Cel_Opaque\n"
        "  • No match                    → left untouched\n\n"
        "Each replaced asset is first renamed to ORIGINAL_<name> so the\n"
        "original is preserved. Already-tagged assets are skipped."
    )
    entry_replace_mats.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, replace_common_materials; "
            "importlib.reload(replace_common_materials); "
            "replace_common_materials.run()"
        ),
    )
    jjk_menu.add_menu_entry("AssetTools", entry_replace_mats)

    entry2 = unreal.ToolMenuEntry(
        name            = "RecreateMontages",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry2.set_label("Recreate Montages")
    entry2.set_tool_tip(
        "Scan Content/ and rebuild all AM_* AnimMontage assets so they work\n"
        "correctly in the editor. Run this after importing game-extracted animations."
    )
    entry2.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, recreate_montages; "
            "importlib.reload(recreate_montages); "
            "recreate_montages.run()"
        ),
    )
    jjk_menu.add_menu_entry("AssetTools", entry2)

    entry_uncook_main = unreal.ToolMenuEntry(
        name            = "UncookSelectedAssets",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_uncook_main.set_label("Uncook Selected Asset(s)")
    entry_uncook_main.set_tool_tip(
        "Create editable copies of the currently selected cooked assets.\n\n"
        "  • Blueprintable data objects  →  Blueprint subclass\n"
        "    (open Class Defaults to edit — e.g. scene-capture params)\n"
        "  • Texture2D / TextureCube     →  TGA export + re-import\n"
        "  • Material                    →  MaterialInstanceConstant\n"
        "  • SkeletalMesh / Skeleton     →  FBX export\n\n"
        "Output lands in  /Game/Mods/Uncooked/<original path>."
    )
    entry_uncook_main.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, uncook_assets; "
            "importlib.reload(uncook_assets); "
            "uncook_assets.uncook_selected()"
        ),
    )
    jjk_menu.add_menu_entry("AssetTools", entry_uncook_main)

    entry_delete_original = unreal.ToolMenuEntry(
        name            = "DeleteAllOriginalAssets",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_delete_original.set_label("Delete All ORIGINAL_ Assets")
    entry_delete_original.set_tool_tip(
        "Find every asset in the project whose name starts with 'ORIGINAL_'\n"
        "and permanently delete them all.\n\n"
        "A confirmation dialog is shown before any deletions take place."
    )
    entry_delete_original.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, mod_tools; "
            "importlib.reload(mod_tools); "
            "mod_tools.delete_all_original_assets()"
        ),
    )
    jjk_menu.add_menu_entry("AssetTools", entry_delete_original)

    entry_restore_original = unreal.ToolMenuEntry(
        name            = "RestoreAllOriginalAssets",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_restore_original.set_label("Restore All ORIGINAL_ Assets")
    entry_restore_original.set_tool_tip(
        "Find every asset whose name starts with 'ORIGINAL_' and rename it\n"
        "by stripping the prefix (e.g. ORIGINAL_Foo → Foo).\n\n"
        "If an asset with the target name already exists it is deleted first,\n"
        "then the rename proceeds.\n\n"
        "A confirmation dialog is shown before any changes take place."
    )
    entry_restore_original.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, mod_tools; "
            "importlib.reload(mod_tools); "
            "mod_tools.restore_all_original_assets()"
        ),
    )
    jjk_menu.add_menu_entry("AssetTools", entry_restore_original)

    # ── Section: Mod Management ─────────────────────────────────────────────
    jjk_menu.add_section("ModManagement", "Mod Management")

    entry_new_mod = unreal.ToolMenuEntry(
        name            = "NewMod",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_new_mod.set_label("New Mod")
    entry_new_mod.set_tool_tip(
        "Create a new mod folder under Content/Mods/.\n\n"
        "A dialog will let you fill in the mod's title, description,\n"
        "version, and priority.  The folder and manifest.json are\n"
        "created automatically once you confirm."
    )
    entry_new_mod.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, mod_tools; "
            "importlib.reload(mod_tools); "
            "mod_tools.open_new_mod_dialog()"
        ),
    )
    jjk_menu.add_menu_entry("ModManagement", entry_new_mod)

    entry_edit_manifest = unreal.ToolMenuEntry(
        name            = "EditModManifest",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_edit_manifest.set_label("Edit Mods")
    entry_edit_manifest.set_tool_tip(
        "Edit the manifest.json for an existing mod.\n\n"
        "Opens a picker so you can choose which mod to edit, then\n"
        "shows the same form used when creating a new mod."
    )
    entry_edit_manifest.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, mod_tools; "
            "importlib.reload(mod_tools); "
            "mod_tools.open_edit_manifest_dialog()"
        ),
    )
    jjk_menu.add_menu_entry("ModManagement", entry_edit_manifest)

    # ── Section: Mod Cooking ────────────────────────────────────────────────
    jjk_menu.add_section("ModCooking", "Mod Cooking")

    entry_cook_all = unreal.ToolMenuEntry(
        name            = "CookAllMods",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_cook_all.set_label("Cook & Export All Mods")
    entry_cook_all.set_tool_tip(
        "Cook all mods under Content/Mods/ and copy the results to your\n"
        "configured Mods Path. Set the output folder via JJK Mod Kit → Settings…"
    )
    entry_cook_all.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, mod_tools; "
            "importlib.reload(mod_tools); "
            "mod_tools.cook_and_stage_all_mods_async()"
        ),
    )
    jjk_menu.add_menu_entry("ModCooking", entry_cook_all)

    entry_settings = unreal.ToolMenuEntry(
        name            = "ModKitSettings",
        type            = unreal.MultiBlockType.MENU_ENTRY,
        insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
    )
    entry_settings.set_label("Settings")
    entry_settings.set_tool_tip(
        "Open the Mod Kit config file to set your Mods output folder and\n"
        "other preferences. Changes take effect on the next cook."
    )
    entry_settings.set_string_command(
        type        = unreal.ToolMenuStringCommandType.PYTHON,
        custom_type = unreal.Name(""),
        string      = (
            "import importlib, mod_tools; "
            "importlib.reload(mod_tools); "
            "mod_tools.open_settings_dialog()"
        ),
    )
    jjk_menu.add_menu_entry("ModCooking", entry_settings)

    menus.refresh_all_widgets()
    unreal.log("[JJK Mod Kit] Menu registered — 'JJK Mod Kit' dropdown available in the main menu bar.")


# ─── Folder right-click — script-object approach ──────────────────────────────
#
# Problem: GetSelectedFolderPaths() returns empty by the time a string command
# fires because the Content Browser selection is cleared when the menu closes.
#
# Solution: use a ToolMenuEntryScript.  get_label() is called at MENU-DRAW time
# (while the folder is still selected → GetSelectedFolderPaths() works).
# We capture the path into a module-level list so execute() can read it after
# the menu has closed and the selection is gone.
#
# _jjk_captured_folder[0] — mutable list so methods can write without `global`.

_jjk_captured_folder    = [None]   # used by Recreate Montages entry
_jjk_mod_export_folder  = [None]   # used by Cook & Export Mod entry
_jjk_manifest_edit_ue_path = [None]  # used by Edit Mod Manifest entry


def _parse_direct_mod_folder(folder_path: str | None) -> str | None:
    """
    Return the mod name if *folder_path* is a direct child of /Game/Mods/,
    i.e. exactly  /Game/Mods/<ModName>  with no further nesting.

    UE internal paths may arrive as  '/Game/Mods/MyMod'  or (with the
    virtual /All mount-point)  '/All/Game/Mods/MyMod'.  Both are handled.

    Returns the ModName string, or None if the path is not a valid direct
    mod subfolder.
    """
    if not folder_path:
        return None
    path = folder_path.rstrip("/")
    # Strip optional /All prefix used by some UE5 CB implementations
    if path.startswith("/All/"):
        path = path[4:]   # /All/Game/... → /Game/...
    # Expect exactly  /Game/Mods/<ModName>
    # split('/') on '/Game/Mods/MyMod' → ['', 'Game', 'Mods', 'MyMod']
    parts = path.split("/")
    if (
        len(parts) == 4
        and parts[0] == ""
        and parts[1] == "Game"
        and parts[2] == "Mods"
        and parts[3]
    ):
        return parts[3]
    return None


def _jjk_capture_folder_from_context(context):
    """
    Called from get_label() at MENU-DRAW time.
    Passes the live FToolMenuContext to the C++ bridge which calls
    Context.FindContext<UContentBrowserDataMenuContext_FolderMenu>()
    and returns the internal path(s) of the right-clicked folder.

    Returns the first path as a string, or None.
    """
    bridge = getattr(unreal, 'MontageBridgeLibrary', None)
    if bridge is None:
        return None
    fn = getattr(bridge, 'get_folder_paths_from_tool_menu_context', None)
    if fn is None:
        return None
    try:
        paths = fn(context)
        if paths:
            return str(paths[0]).rstrip('/')
    except Exception as e:
        unreal.log_warning(f'[JJK Mod Kit] get_folder_paths_from_tool_menu_context error: {e}')
    return None


try:
    @unreal.uclass()
    class _JJKFolderCookExportModEntry(unreal.ToolMenuEntryScript):
        """
        Folder context-menu entry: "Cook & Export Mod [<name>]"

        Visible ONLY when the right-clicked folder is a direct child of
        /Game/Mods/ (i.e. exactly one level deep: /Game/Mods/<ModName>).
        Deeper subfolders and unrelated folders do NOT show this entry.

        is_visible() and get_label() are both called at menu-DRAW time while
        the folder context is still live.  We capture the mod name from the
        context in is_visible() and carry it into execute() via
        _jjk_mod_export_folder.
        """

        @unreal.ufunction(override=True)
        def is_visible(self, context: unreal.ToolMenuContext) -> bool:
            raw = _jjk_capture_folder_from_context(context)
            mod_name = _parse_direct_mod_folder(raw)
            # Store now so get_label / execute can use without re-calling bridge
            _jjk_mod_export_folder[0] = mod_name
            return mod_name is not None

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            mod_name = _jjk_mod_export_folder[0]
            if not mod_name:
                # is_visible returned False but get_label was still called — refresh
                raw = _jjk_capture_folder_from_context(context)
                mod_name = _parse_direct_mod_folder(raw)
                _jjk_mod_export_folder[0] = mod_name
            return f"Cook & Export Mod  [{mod_name}]" if mod_name else "Cook & Export Mod"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            mod_name = _jjk_mod_export_folder[0] or "<mod>"
            return (
                f"Cook and export '{mod_name}' to your configured Mods Path.\n\n"
                "Only available on direct subfolders of Content/Mods/.\n"
                "Configure the output folder via JJK Mod Kit → Settings…"
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            import importlib, mod_tools
            importlib.reload(mod_tools)

            mod_name = _jjk_mod_export_folder[0]
            _jjk_mod_export_folder[0] = None   # reset for next right-click

            if mod_name:
                mod_tools.cook_and_stage_mod(mod_name)
            else:
                unreal.log_warning(
                    "[JJK Mod Kit] Cook & Export Mod: folder was not recognised "
                    "as a direct /Game/Mods/* subfolder — aborting."
                )

    _jjk_mod_export_script_obj = _JJKFolderCookExportModEntry()
    _JJK_MOD_EXPORT_SCRIPT_OK  = True
    unreal.log("[JJK Mod Kit] Cook & Export Mod ToolMenuEntryScript registered.")

except Exception as _mod_export_script_err:
    unreal.log_warning(
        f"[JJK Mod Kit] Cook & Export Mod ToolMenuEntryScript unavailable "
        f"({_mod_export_script_err}); folder right-click entry will be skipped."
    )
    _jjk_mod_export_script_obj = None
    _JJK_MOD_EXPORT_SCRIPT_OK  = False


try:
    @unreal.uclass()
    class _JJKAssetRecreateMontagesEntry(unreal.ToolMenuEntryScript):
        """
        ToolMenuEntryScript for Content Browser asset right-click.

        is_visible() is called at menu-DRAW time.  We check whether any of
        the currently selected assets is an AnimMontage or AnimComposite and
        only show the entry when at least one such asset is selected.
        """

        @unreal.ufunction(override=True)
        def is_visible(self, context: unreal.ToolMenuContext) -> bool:
            try:
                selected = unreal.EditorUtilityLibrary.get_selected_assets()
            except Exception:
                return False
            return any(
                isinstance(a, (unreal.AnimMontage, unreal.AnimComposite))
                for a in selected
            )

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            return "Recreate Montage(s)"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            return (
                "Rebuild the selected AnimMontage / AnimComposite asset(s) in-place.\n\n"
                "Replaces game-extracted montages with clean, editor-compatible versions\n"
                "while keeping all animation data (slots, notifies, blend times, etc.).\n\n"
                "Non-montage assets in the selection are skipped."
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            import importlib, recreate_montages
            importlib.reload(recreate_montages)
            recreate_montages.run_on_selected_assets()

    _jjk_asset_recreate_script_obj = _JJKAssetRecreateMontagesEntry()
    _JJK_ASSET_RECREATE_SCRIPT_OK  = True
    unreal.log("[JJK Mod Kit] Recreate Montage(s) ToolMenuEntryScript registered.")

except Exception as _asset_recreate_script_err:
    unreal.log_warning(
        f"[JJK Mod Kit] Recreate Montage(s) ToolMenuEntryScript unavailable "
        f"({_asset_recreate_script_err}); asset right-click entry will be skipped."
    )
    _jjk_asset_recreate_script_obj = None
    _JJK_ASSET_RECREATE_SCRIPT_OK  = False


# ─── Uncook entries — one ToolMenuEntryScript per asset type ─────────────────
#
#  • _JJKUncookDataObjectEntry  → Blueprintable UObject (data params, etc.)
#  • _JJKUncookTextureEntry     → Texture / Texture2D / TextureCube
#  • _JJKUncookMaterialEntry    → Material / MaterialInstance
#  • _JJKUncookMeshEntry        → SkeletalMesh / Skeleton
#
# Each entry is visible ONLY for its own asset type so the JJK Mod Kit section
# in the right-click menu never shows entries that don't apply to the selection.

# ── 1. Blueprintable data objects (GameWidgetParameterBase, etc.) ─────────────
try:
    @unreal.uclass()
    class _JJKUncookDataObjectEntry(unreal.ToolMenuEntryScript):
        """
        Visible only when every selected asset is a plain Blueprintable UObject
        (i.e. NOT a Blueprint/BPGC, Texture, Material, Mesh, or animation).
        Creates a Blueprint subclass so the Class Defaults are fully editable.
        """

        _MATCH = (unreal.Object,)
        _SKIP  = (
            unreal.Blueprint, unreal.BlueprintGeneratedClass,
            unreal.Texture,
            unreal.Material, unreal.MaterialInterface,
            unreal.SkeletalMesh, unreal.Skeleton, unreal.StaticMesh,
            unreal.AnimationAsset, unreal.AnimMontage, unreal.AnimComposite,
            unreal.SoundBase, unreal.SoundWave,
        )

        @unreal.ufunction(override=True)
        def is_visible(self, context: unreal.ToolMenuContext) -> bool:
            try:
                selected = unreal.EditorUtilityLibrary.get_selected_assets()
            except Exception:
                return False
            return bool(selected) and any(
                isinstance(a, unreal.Object) and not isinstance(a, _JJKUncookDataObjectEntry._SKIP)
                for a in selected
            )

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            return "Create Blueprint Copy"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            return (
                "Create an editable Blueprint subclass of this data object.\n\n"
                "Because these classes inherit UObject (not UDataAsset), a Blueprint\n"
                "subclass is the only editable form — open it and use the Class\n"
                "Defaults tab to read and change all EditAnywhere properties\n"
                "(e.g. ParameterMap, CameraParameter, LightParameter).\n\n"
                "Output: /Game/Mods/Uncooked/<original path>"
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            import importlib, uncook_assets
            importlib.reload(uncook_assets)
            selected = unreal.EditorUtilityLibrary.get_selected_assets()
            for a in selected:
                if isinstance(a, unreal.Object) and not isinstance(a, _JJKUncookDataObjectEntry._SKIP):
                    src = uncook_assets._asset_path_from_object(a)
                    uncook_assets.uncook_blueprintable_object(
                        a, uncook_assets._default_dst(src)
                    )

    _jjk_uncook_dataobj_script = _JJKUncookDataObjectEntry()
    _JJK_UNCOOK_DATAOBJ_OK     = True
    unreal.log("[JJK Mod Kit] 'Create Blueprint Copy' ToolMenuEntryScript registered.")
except Exception as _e:
    unreal.log_warning(f"[JJK Mod Kit] 'Create Blueprint Copy' script unavailable ({_e}).")
    _jjk_uncook_dataobj_script = None
    _JJK_UNCOOK_DATAOBJ_OK     = False


# ── 2. Textures ───────────────────────────────────────────────────────────────
try:
    @unreal.uclass()
    class _JJKUncookTextureEntry(unreal.ToolMenuEntryScript):
        """Visible only when the selection contains at least one Texture asset."""

        @unreal.ufunction(override=True)
        def is_visible(self, context: unreal.ToolMenuContext) -> bool:
            try:
                selected = unreal.EditorUtilityLibrary.get_selected_assets()
            except Exception:
                return False
            return any(isinstance(a, unreal.Texture) for a in selected)

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            return "Uncook Texture (TGA)"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            return (
                "Export the cooked texture to a TGA file, then re-import it\n"
                "as an editable asset in your mod folder.\n\n"
                "The TGA is left in  Saved/UncookedTextures/  so you can open\n"
                "and edit it in Photoshop, GIMP, etc.\n\n"
                "Output: /Game/Mods/Uncooked/<original path>"
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            import importlib, uncook_assets
            importlib.reload(uncook_assets)
            selected = unreal.EditorUtilityLibrary.get_selected_assets()
            for a in selected:
                if isinstance(a, unreal.Texture):
                    src = uncook_assets._asset_path_from_object(a)
                    uncook_assets.uncook_texture(a, uncook_assets._default_dst(src))

    _jjk_uncook_tex_script = _JJKUncookTextureEntry()
    _JJK_UNCOOK_TEX_OK     = True
    unreal.log("[JJK Mod Kit] 'Uncook Texture (TGA)' ToolMenuEntryScript registered.")
except Exception as _e:
    unreal.log_warning(f"[JJK Mod Kit] 'Uncook Texture' script unavailable ({_e}).")
    _jjk_uncook_tex_script = None
    _JJK_UNCOOK_TEX_OK     = False


# ── 3. Materials ──────────────────────────────────────────────────────────────
try:
    @unreal.uclass()
    class _JJKUncookMaterialEntry(unreal.ToolMenuEntryScript):
        """Visible only when the selection contains at least one Material or MaterialInstance."""

        @unreal.ufunction(override=True)
        def is_visible(self, context: unreal.ToolMenuContext) -> bool:
            try:
                selected = unreal.EditorUtilityLibrary.get_selected_assets()
            except Exception:
                return False
            return any(isinstance(a, unreal.MaterialInterface) for a in selected)

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            return "Uncook Material"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            return (
                "Duplicate the cooked Material to a real editable Material asset.\n\n"
                "The copy is placed in a sibling Uncooked/ subfolder beside the\n"
                "source asset, e.g.:\n"
                "  /Game/A/B/M_Foo  →  /Game/A/B/Uncooked/M_Foo\n\n"
                "Open the result in the Material Editor to inspect and tweak settings."
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            import importlib, uncook_assets
            importlib.reload(uncook_assets)
            selected = unreal.EditorUtilityLibrary.get_selected_assets()
            for a in selected:
                if isinstance(a, unreal.MaterialInstance):
                    src = uncook_assets._asset_path_from_object(a)
                    uncook_assets.uncook_material_instance(a, uncook_assets._relative_dst(src))
                elif isinstance(a, unreal.Material):
                    src = uncook_assets._asset_path_from_object(a)
                    uncook_assets.uncook_material(a, uncook_assets._relative_dst(src))

    _jjk_uncook_mat_script = _JJKUncookMaterialEntry()
    _JJK_UNCOOK_MAT_OK     = True
    unreal.log("[JJK Mod Kit] 'Uncook Material' ToolMenuEntryScript registered.")
except Exception as _e:
    unreal.log_warning(f"[JJK Mod Kit] 'Uncook Material' script unavailable ({_e}).")
    _jjk_uncook_mat_script = None
    _JJK_UNCOOK_MAT_OK     = False


# ── 4. Skeletal Meshes / Skeletons ────────────────────────────────────────────
try:
    @unreal.uclass()
    class _JJKUncookMeshEntry(unreal.ToolMenuEntryScript):
        """Visible only when the selection contains at least one SkeletalMesh or Skeleton."""

        @unreal.ufunction(override=True)
        def is_visible(self, context: unreal.ToolMenuContext) -> bool:
            try:
                selected = unreal.EditorUtilityLibrary.get_selected_assets()
            except Exception:
                return False
            return any(isinstance(a, (unreal.SkeletalMesh, unreal.Skeleton)) for a in selected)

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            return "Uncook Mesh (FBX)"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            return (
                "Export the cooked SkeletalMesh / Skeleton to FBX (no dialog),\n"
                "then re-import it as a UE asset beside the source:\n"
                "  /Game/A/B/SK_Foo  →  /Game/A/B/Uncooked/SK_Foo\n\n"
                "The FBX is kept in  Saved/UncookedMeshes/  for DCC editing.\n"
                "Open it in Blender / Maya, then re-import at the asset path."
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            import importlib, uncook_assets
            importlib.reload(uncook_assets)
            selected = unreal.EditorUtilityLibrary.get_selected_assets()
            for a in selected:
                if isinstance(a, unreal.SkeletalMesh):
                    src = uncook_assets._asset_path_from_object(a)
                    uncook_assets.uncook_skeletal_mesh(a, uncook_assets._relative_dst(src))
                elif isinstance(a, unreal.Skeleton):
                    src = uncook_assets._asset_path_from_object(a)
                    uncook_assets.uncook_skeleton(a, uncook_assets._relative_dst(src))

    _jjk_uncook_mesh_script = _JJKUncookMeshEntry()
    _JJK_UNCOOK_MESH_OK     = True
    unreal.log("[JJK Mod Kit] 'Uncook Mesh (FBX)' ToolMenuEntryScript registered.")
except Exception as _e:
    unreal.log_warning(f"[JJK Mod Kit] 'Uncook Mesh (FBX)' script unavailable ({_e}).")
    _jjk_uncook_mesh_script = None
    _JJK_UNCOOK_MESH_OK     = False


# ── 5. Toggle cooked asset name ('ORIGINAL_' prefix) ─────────────────────────
_ORIGINAL_TAG = "ORIGINAL_"

def _toggle_original_tag_on_assets(assets: list) -> None:
    """
    For each asset in *assets*, toggle a 'ORIGINAL_' prefix on its name.

    If the asset name already starts with 'ORIGINAL_' the tag is stripped;
    otherwise it is prepended.  The asset is renamed in-place via
    EditorAssetLibrary so no content is duplicated.
    """
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    for asset in assets:
        old_path  = asset.get_path_name()              # e.g. /Game/Foo/Bar.Bar
        pkg_path  = old_path.split(".")[0]             # /Game/Foo/Bar
        folder    = "/".join(pkg_path.split("/")[:-1]) # /Game/Foo
        old_name  = pkg_path.split("/")[-1]            # Bar

        if old_name.startswith(_ORIGINAL_TAG):
            new_name = old_name[len(_ORIGINAL_TAG):]
        else:
            new_name = _ORIGINAL_TAG + old_name

        new_path = f"{folder}/{new_name}"

        ok = unreal.EditorAssetLibrary.rename_asset(pkg_path, new_path)
        if ok:
            unreal.log(f"[JJK Mod Kit] Renamed  {pkg_path}  →  {new_path}")
        else:
            unreal.log_warning(
                f"[JJK Mod Kit] Toggle cooked asset name: rename failed for  {pkg_path}  → {new_path}"
            )


try:
    @unreal.uclass()
    class _JJKToggleCookedNameEntry(unreal.ToolMenuEntryScript):
        """
        Asset context-menu entry: 'Toggle cooked asset name'

        Prepends or removes the 'ORIGINAL_' tag at the start of the asset
        filename.  Visible for any non-empty asset selection.

        get_label() returns a context-sensitive label:
          • "Add ORIGINAL_ tag"    — when the first selected asset has no tag
          • "Remove ORIGINAL_ tag" — when the first selected asset has the tag
        """

        @unreal.ufunction(override=True)
        def is_visible(self, context: unreal.ToolMenuContext) -> bool:
            try:
                selected = unreal.EditorUtilityLibrary.get_selected_assets()
            except Exception:
                return False
            return bool(selected)

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            try:
                selected = unreal.EditorUtilityLibrary.get_selected_assets()
            except Exception:
                return "Toggle cooked asset name"
            if selected:
                first_name = selected[0].get_path_name().split(".")[0].split("/")[-1]
                if first_name.startswith(_ORIGINAL_TAG):
                    return "Remove ORIGINAL_ tag"
            return "Add ORIGINAL_ tag"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            return (
                "Toggle the 'ORIGINAL_' prefix on the selected asset name(s).\n\n"
                "Adding the tag marks an asset as a cooked original so it can be\n"
                "distinguished from edited / uncooked copies.  Removing it restores\n"
                "the plain filename.\n\n"
                "The asset is renamed in-place — no duplicate is created."
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            selected = unreal.EditorUtilityLibrary.get_selected_assets()
            if selected:
                _toggle_original_tag_on_assets(selected)

    _jjk_toggle_cooked_name_script = _JJKToggleCookedNameEntry()
    _JJK_TOGGLE_COOKED_NAME_OK     = True
    unreal.log("[JJK Mod Kit] 'Toggle cooked asset name' ToolMenuEntryScript registered.")
except Exception as _e:
    unreal.log_warning(f"[JJK Mod Kit] 'Toggle cooked asset name' script unavailable ({_e}).")
    _jjk_toggle_cooked_name_script = None
    _JJK_TOGGLE_COOKED_NAME_OK     = False


try:
    @unreal.uclass()
    class _JJKFolderRecreateMontagesEntry(unreal.ToolMenuEntryScript):
        """
        ToolMenuEntryScript for Content Browser folder right-click.

        get_label() fires at menu-DRAW time (folder still selected in CB).
        We call GetSelectedFolderPaths() here, store the path, then use it
        in execute() — which fires AFTER the menu closes and the CB selection
        may already be gone.
        """

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            # Called at MENU-DRAW time — the right-clicked folder is still
            # in the FToolMenuContext.  Pass the live context to the C++ bridge
            # which calls FindContext<UContentBrowserDataMenuContext_FolderMenu>()
            # and extracts GetInternalPath() from SelectedItems.
            _jjk_captured_folder[0] = _jjk_capture_folder_from_context(context)
            return "Recreate Montages in Folder"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            return (
                "Rebuild all AM_* AnimMontage assets inside the selected folder.\n\n"
                "Replaces game-extracted montages with clean, editor-compatible versions\n"
                "while keeping all animation data."
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            import importlib, recreate_montages
            importlib.reload(recreate_montages)

            folder = _jjk_captured_folder[0]
            _jjk_captured_folder[0] = None   # reset for next right-click

            if folder:
                unreal.log(f'[RecreateMontages] Context-menu folder (captured at draw): {folder}')
                recreate_montages.run(search_root=folder)
            else:
                unreal.log_warning(
                    '[JJK Mod Kit] Folder path was not captured at draw time — '
                    'opening folder-picker dialog.'
                )
                recreate_montages.run_on_selected_folder()

    _jjk_folder_script_obj = _JJKFolderRecreateMontagesEntry()
    _JJK_FOLDER_SCRIPT_OK  = True
    unreal.log("[JJK Mod Kit] ToolMenuEntryScript registered for folder context menu.")

except Exception as _folder_script_err:
    unreal.log_warning(
        f"[JJK Mod Kit] ToolMenuEntryScript unavailable ({_folder_script_err}); "
        "folder right-click will fall back to folder-picker dialog."
    )
    _jjk_folder_script_obj = None
    _JJK_FOLDER_SCRIPT_OK  = False


# ─── Edit Mod Manifest — folder right-click ───────────────────────────────────
#
# Visible only for direct /Game/Mods/<ModName> subfolders (same criterion as
# Cook & Export Mod).  Captures the UE content path at menu-DRAW time so that
# execute() can pass it to open_edit_manifest_dialog() after the menu closes.

try:
    @unreal.uclass()
    class _JJKEditManifestEntry(unreal.ToolMenuEntryScript):
        """
        Folder context-menu entry: "Edit Mod Manifest…"

        Visible ONLY for direct  /Game/Mods/<ModName>  subfolders.
        Captures the UE path in is_visible() / get_label() (menu-draw time)
        and passes it to open_edit_manifest_dialog() in execute().
        """

        @unreal.ufunction(override=True)
        def is_visible(self, context: unreal.ToolMenuContext) -> bool:
            raw = _jjk_capture_folder_from_context(context)
            mod_name = _parse_direct_mod_folder(raw)
            # Normalise to  /Game/Mods/<ModName>  so open_edit_manifest_dialog
            # can convert it to a filesystem path without the /All/ prefix.
            if mod_name and raw:
                # Strip /All prefix if present so we store a clean /Game/… path
                clean = raw
                if clean.startswith("/All/"):
                    clean = clean[4:]
                _jjk_manifest_edit_ue_path[0] = clean
            else:
                _jjk_manifest_edit_ue_path[0] = None
            return mod_name is not None

        @unreal.ufunction(override=True)
        def get_label(self, context: unreal.ToolMenuContext) -> str:
            # Re-capture in case is_visible wasn't called first
            if _jjk_manifest_edit_ue_path[0] is None:
                raw = _jjk_capture_folder_from_context(context)
                if raw:
                    clean = raw
                    if clean.startswith("/All/"):
                        clean = clean[4:]
                    _jjk_manifest_edit_ue_path[0] = clean
            return "Edit Mod Manifest"

        @unreal.ufunction(override=True)
        def get_tool_tip(self, context: unreal.ToolMenuContext) -> str:
            ue_path = _jjk_manifest_edit_ue_path[0] or "/Game/Mods/<mod>"
            mod_name = ue_path.rstrip("/").split("/")[-1]
            return (
                f"Edit the manifest.json for  '{mod_name}'.\n\n"
                "Opens the same form used when creating a new mod so you can\n"
                "update the title, description, version, and priority.\n\n"
                "Only available on direct subfolders of Content/Mods/."
            )

        @unreal.ufunction(override=True)
        def execute(self, context: unreal.ToolMenuContext) -> None:
            import importlib, mod_tools
            importlib.reload(mod_tools)

            ue_path = _jjk_manifest_edit_ue_path[0]
            _jjk_manifest_edit_ue_path[0] = None   # reset for next right-click

            if ue_path:
                mod_tools.open_edit_manifest_dialog(ue_path)
            else:
                unreal.log_warning(
                    "[JJK Mod Kit] Edit Mod Manifest: folder path was not captured "
                    "— falling back to mod picker."
                )
                mod_tools.open_edit_manifest_dialog()

    _jjk_edit_manifest_script_obj = _JJKEditManifestEntry()
    _JJK_EDIT_MANIFEST_SCRIPT_OK  = True
    unreal.log("[JJK Mod Kit] 'Edit Mod Manifest' ToolMenuEntryScript registered.")

except Exception as _edit_manifest_err:
    unreal.log_warning(
        f"[JJK Mod Kit] 'Edit Mod Manifest' ToolMenuEntryScript unavailable "
        f"({_edit_manifest_err}); folder right-click entry will be skipped."
    )
    _jjk_edit_manifest_script_obj = None
    _JJK_EDIT_MANIFEST_SCRIPT_OK  = False


def _register_content_browser_context_menus():
    """
    Add 'JJK Mod Kit' sections to the Content Browser right-click menus:

      • ContentBrowser.FolderContextMenu
            "Cook & Export Mod [<name>]"  — only for direct /Game/Mods/* folders
            "Recreate Montages in Folder"
            Both use ToolMenuEntryScript so the folder path is captured at
            menu-draw time (before the CB clears the selection).

      • ContentBrowser.AssetContextMenu
            "Recreate Montage(s)"   — AnimMontage / AnimComposite only
            "Uncook Asset(s)…"      — Textures, Materials, Meshes, data UObjects
    """
    menus = unreal.ToolMenus.get()

    # ── Folder right-click ────────────────────────────────────────────────────
    folder_menu = menus.find_menu("ContentBrowser.FolderContextMenu")
    if folder_menu:
        folder_menu.add_section("JJKModKitFolder", "JJK Mod Kit")

        # ── Cook & Export Mod (only visible for /Game/Mods/* direct children) ─
        if _JJK_MOD_EXPORT_SCRIPT_OK:
            entry_cook_mod = unreal.ToolMenuEntry(
                name            = "JJKCookExportMod",
                type            = unreal.MultiBlockType.MENU_ENTRY,
                insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
            )
            entry_cook_mod.script_object = _jjk_mod_export_script_obj
            folder_menu.add_menu_entry("JJKModKitFolder", entry_cook_mod)
            unreal.log("[JJK Mod Kit] Registered 'Cook & Export Mod' in ContentBrowser.FolderContextMenu.")
        else:
            unreal.log_warning(
                "[JJK Mod Kit] Cook & Export Mod entry skipped "
                "(ToolMenuEntryScript not available)."
            )

        # ── Edit Mod Manifest… (only visible for /Game/Mods/* direct children) ─
        if _JJK_EDIT_MANIFEST_SCRIPT_OK:
            entry_edit_manifest_ctx = unreal.ToolMenuEntry(
                name            = "JJKEditModManifest",
                type            = unreal.MultiBlockType.MENU_ENTRY,
                insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
            )
            entry_edit_manifest_ctx.script_object = _jjk_edit_manifest_script_obj
            folder_menu.add_menu_entry("JJKModKitFolder", entry_edit_manifest_ctx)
            unreal.log("[JJK Mod Kit] Registered 'Edit Mod Manifest' in ContentBrowser.FolderContextMenu.")
        else:
            unreal.log_warning(
                "[JJK Mod Kit] Edit Mod Manifest entry skipped "
                "(ToolMenuEntryScript not available)."
            )

        # ── Recreate Montages in Folder ───────────────────────────────────────
        entry_folder = unreal.ToolMenuEntry(
            name            = "JJKRecreateMontagesInFolder",
            type            = unreal.MultiBlockType.MENU_ENTRY,
            insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
        )

        if _JJK_FOLDER_SCRIPT_OK:
            # Label, tooltip, and action all come from the script object.
            # Do NOT call set_label()/set_tool_tip() — assigning script_object
            # makes UE ignore those values.
            entry_folder.script_object = _jjk_folder_script_obj
        else:
            # Fallback: string command with folder-picker dialog
            entry_folder.set_label("Recreate Montages in Folder")
            entry_folder.set_tool_tip(
                "Rebuild all AM_* AnimMontage assets inside the selected folder.\n\n"
                "A folder-picker dialog will open to confirm the target path."
            )
            entry_folder.set_string_command(
                type        = unreal.ToolMenuStringCommandType.PYTHON,
                custom_type = unreal.Name(""),
                string      = (
                    "import importlib, recreate_montages; "
                    "importlib.reload(recreate_montages); "
                    "recreate_montages.run_on_selected_folder()"
                ),
            )

        folder_menu.add_menu_entry("JJKModKitFolder", entry_folder)
        unreal.log("[JJK Mod Kit] Registered 'Recreate Montages in Folder' in ContentBrowser.FolderContextMenu.")
    else:
        unreal.log_warning(
            "[JJK Mod Kit] ContentBrowser.FolderContextMenu not found — "
            "folder right-click entry not registered."
        )

    # ── Asset right-click ─────────────────────────────────────────────────────
    asset_menu = menus.find_menu("ContentBrowser.AssetContextMenu")
    if asset_menu:
        asset_menu.add_section("JJKModKitAsset", "JJK Mod Kit")

        # ── Recreate Montage(s) ───────────────────────────────────────────────
        if _JJK_ASSET_RECREATE_SCRIPT_OK:
            entry_asset = unreal.ToolMenuEntry(
                name            = "JJKRecreateMontageAssets",
                type            = unreal.MultiBlockType.MENU_ENTRY,
                insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
            )
            entry_asset.script_object = _jjk_asset_recreate_script_obj
            asset_menu.add_menu_entry("JJKModKitAsset", entry_asset)
            unreal.log("[JJK Mod Kit] Registered 'Recreate Montage(s)' in ContentBrowser.AssetContextMenu.")
        else:
            unreal.log_warning(
                "[JJK Mod Kit] Recreate Montage(s) ToolMenuEntryScript unavailable — "
                "asset right-click entry will be skipped."
            )

        # ── Create Blueprint Copy… (plain Blueprintable UObjects) ─────────────
        if _JJK_UNCOOK_DATAOBJ_OK:
            e = unreal.ToolMenuEntry(
                name            = "JJKUncookDataObject",
                type            = unreal.MultiBlockType.MENU_ENTRY,
                insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
            )
            e.script_object = _jjk_uncook_dataobj_script
            asset_menu.add_menu_entry("JJKModKitAsset", e)
            unreal.log("[JJK Mod Kit] Registered 'Create Blueprint Copy' in ContentBrowser.AssetContextMenu.")

        # ── Export Texture (TGA)… ─────────────────────────────────────────────
        if _JJK_UNCOOK_TEX_OK:
            e = unreal.ToolMenuEntry(
                name            = "JJKUncookTexture",
                type            = unreal.MultiBlockType.MENU_ENTRY,
                insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
            )
            e.script_object = _jjk_uncook_tex_script
            asset_menu.add_menu_entry("JJKModKitAsset", e)
            unreal.log("[JJK Mod Kit] Registered 'Uncook Texture (TGA)' in ContentBrowser.AssetContextMenu.")

        # ── Uncook Material… ──────────────────────────────────────────────────
        if _JJK_UNCOOK_MAT_OK:
            e = unreal.ToolMenuEntry(
                name            = "JJKUncookMaterial",
                type            = unreal.MultiBlockType.MENU_ENTRY,
                insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
            )
            e.script_object = _jjk_uncook_mat_script
            asset_menu.add_menu_entry("JJKModKitAsset", e)
            unreal.log("[JJK Mod Kit] Registered 'Uncook Material' in ContentBrowser.AssetContextMenu.")

        # ── Uncook Mesh (FBX)… ────────────────────────────────────────────────
        if _JJK_UNCOOK_MESH_OK:
            e = unreal.ToolMenuEntry(
                name            = "JJKUncookMesh",
                type            = unreal.MultiBlockType.MENU_ENTRY,
                insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
            )
            e.script_object = _jjk_uncook_mesh_script
            asset_menu.add_menu_entry("JJKModKitAsset", e)
            unreal.log("[JJK Mod Kit] Registered 'Uncook Mesh (FBX)' in ContentBrowser.AssetContextMenu.")

        # ── Toggle cooked asset name ('ORIGINAL_' prefix) ─────────────────────
        if _JJK_TOGGLE_COOKED_NAME_OK:
            e = unreal.ToolMenuEntry(
                name            = "JJKToggleCookedAssetName",
                type            = unreal.MultiBlockType.MENU_ENTRY,
                insert_position = unreal.ToolMenuInsert("", unreal.ToolMenuInsertType.DEFAULT),
            )
            e.script_object = _jjk_toggle_cooked_name_script
            asset_menu.add_menu_entry("JJKModKitAsset", e)
            unreal.log("[JJK Mod Kit] Registered 'Toggle cooked asset name' in ContentBrowser.AssetContextMenu.")
        else:
            unreal.log_warning(
                "[JJK Mod Kit] 'Toggle cooked asset name' entry skipped "
                "(ToolMenuEntryScript not available)."
            )
    else:
        unreal.log_warning(
            "[JJK Mod Kit] ContentBrowser.AssetContextMenu not found — "
            "asset right-click entry not registered."
        )

    menus.refresh_all_widgets()


_register_jjkcc_menu()
_register_content_browser_context_menus()

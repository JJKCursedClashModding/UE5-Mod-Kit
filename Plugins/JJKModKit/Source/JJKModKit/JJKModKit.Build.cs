using UnrealBuildTool;

public class JJKModKit : ModuleRules
{
    public JJKModKit(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Public (transitively available to modules that depend on this one)
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",             // UAnimMontage, UAnimSequenceBase, FAnimNotifyEvent, etc.
            "DeveloperSettings",  // UDeveloperSettings — used by UJJKModKitSettings
        });

        // Private (used only inside this module)
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "UnrealEd",          // FAssetToolsModule, UFbxImportUI, UFbxSkeletalMeshImportData, UExporter
            "ContentBrowser",    // IContentBrowserSingleton::GetSelectedFolders()
            "ContentBrowserData",// UContentBrowserDataMenuContext_FolderMenu, FContentBrowserItem
            "ToolMenus",         // FToolMenuContext — used as UFUNCTION parameter
            "TargetPlatform",    // ITargetPlatformModule, ITargetPlatformManagerModule — used by JJKModCooker
            "Settings",          // ISettingsModule::ShowViewer — open Project Settings panel
            "AssetTools",        // IAssetTools::ImportAssetTasks — used by UncookLibrary
            "Slate",             // SWindow, SButton, SEditableTextBox, SSpinBox — mod manifest dialog
            "SlateCore",         // FSlateApplication::AddModalWindow, core widget types
            "InputCore",         // FKey, keyboard input support for Slate widgets
        });
    }
}

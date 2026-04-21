using UnrealBuildTool;

public class BlueprintUncooker : ModuleRules
{
	public BlueprintUncooker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"UnrealEd",
			"BlueprintGraph",
			"KismetCompiler",
			"Kismet",
			"ContentBrowser",
			"ContentBrowserData",
			"Slate",
			"SlateCore",
			"InputCore",
			"EditorStyle",
			"GraphEditor",
			"AssetTools",
			"AssetRegistry",
			"ToolMenus",
			"ScriptDisassembler",
			"KismetWidgets",
			"Projects",
			"UMG",       // UWidgetBlueprintGeneratedClass, UWidgetTree, FDelegateRuntimeBinding
			"UMGEditor", // UWidgetBlueprint, FDelegateEditorBinding
		});
	}
}

using UnrealBuildTool;

// STUB: Minimal CriWare Runtime module — replace with licensed CriWare UE Plugin from https://game.criware.jp/
public class CriWareRuntime : ModuleRules {
	public CriWareRuntime(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
		});
	}
}

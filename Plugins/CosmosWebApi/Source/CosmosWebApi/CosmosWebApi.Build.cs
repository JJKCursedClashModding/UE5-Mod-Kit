using UnrealBuildTool;

// STUB: Bandai Namco's proprietary online backend — no public SDK available.
public class CosmosWebApi : ModuleRules {
	public CosmosWebApi(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
		});
	}
}

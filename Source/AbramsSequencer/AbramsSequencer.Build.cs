using UnrealBuildTool;

public class AbramsSequencer : ModuleRules {
    public AbramsSequencer(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Abrams",
            "AbramsDataTable",
            "Core",
            "CoreUObject",
            "CriWareRuntime",
            "Engine",
            "Framework",
            "MovieScene",
            "MovieSceneTracks",
            "Niagara",
            "Slate",
            "SlateCore",
        });
    }
}

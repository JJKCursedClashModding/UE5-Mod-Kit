using UnrealBuildTool;

public class Abrams : ModuleRules {
    public Abrams(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AbramsDataTable",
            "Core",
            "CoreUObject",
            "CosmosWebApi",
            "CriWareRuntime",
            "Engine",
            "Framework",
            "GameplayCameras",
            "InputCore",
            "Niagara",
            "NiagaraUIRenderer",
            "OnlineSubsystemUtils",
            "Paper2D",
            "ProceduralMeshComponent",
            "Slate",
            "SlateCore",
            "UMG",
        });
    }
}

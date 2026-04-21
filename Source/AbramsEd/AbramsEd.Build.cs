using UnrealBuildTool;

public class AbramsEd : ModuleRules
{
    public AbramsEd(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd",
            "Abrams", "AbramsDataTable", "Framework"
        });
    }
}

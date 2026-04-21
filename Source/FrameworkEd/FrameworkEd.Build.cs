using UnrealBuildTool;

public class FrameworkEd : ModuleRules
{
    public FrameworkEd(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd",
            "Abrams", "AbramsDataTable", "Framework"
        });
    }
}

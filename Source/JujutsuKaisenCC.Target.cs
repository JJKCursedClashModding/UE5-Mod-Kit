using UnrealBuildTool;

public class JujutsuKaisenCCTarget : TargetRules {
	public JujutsuKaisenCCTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.AddRange(new string[] {
			"Abrams",
			"AbramsDataTable",
			"AbramsSequencer",
			"Framework",
		});
	}
}

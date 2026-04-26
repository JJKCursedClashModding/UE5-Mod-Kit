using UnrealBuildTool;

public class JujutsuKaisenCCEditorTarget : TargetRules {
	public JujutsuKaisenCCEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.AddRange(new string[] {
			"Abrams",
			"AbramsDataTable",
			"AbramsEd",
			"AbramsSequencer",
			"Framework",
			"FrameworkEd",
		});
	}
}

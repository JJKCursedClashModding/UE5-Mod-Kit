using UnrealBuildTool;

public class JujutsuKaisenCCEditorTarget : TargetRules {
	public JujutsuKaisenCCEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
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

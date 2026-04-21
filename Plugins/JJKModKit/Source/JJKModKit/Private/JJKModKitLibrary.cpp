#include "JJKModKitLibrary.h"

#if WITH_EDITOR
#include "ISettingsModule.h"    // ISettingsModule::ShowViewer
#endif

// ---------------------------------------------------------------------------
// OpenJJKModKitSettings
// ---------------------------------------------------------------------------
void UJJKModKitLibrary::OpenJJKModKitSettings()
{
#if WITH_EDITOR
    if (ISettingsModule* SettingsModule =
            FModuleManager::GetModulePtr<ISettingsModule>(TEXT("Settings")))
    {
        // Container  = "Project"          (Edit → Project Settings)
        // Category   = "Plugins"          (left-panel group)
        // Section    = "JJKModKitSettings" (auto-derived from UJJKModKitSettings class name)
        SettingsModule->ShowViewer(
            TEXT("Project"),
            TEXT("Plugins"),
            TEXT("JJKModKitSettings")
        );
    }
    else
    {
        UE_LOG(LogTemp, Warning,
            TEXT("[JJK Mod Kit] OpenJJKModKitSettings: Settings module not available."));
    }
#endif
}

#include "JJKModKitLibrary.h"

#if WITH_EDITOR
#include "ISettingsModule.h"             // ISettingsModule::ShowViewer
#include "Modules/ModuleManager.h"
#include "DesktopPlatformModule.h"       // FDesktopPlatformModule
#include "IDesktopPlatform.h"            // IDesktopPlatform::OpenFileDialog
#include "Framework/Application/SlateApplication.h"
#include "EditorDirectories.h"
#include "Misc/Paths.h"
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

// ---------------------------------------------------------------------------
// OpenFilePicker
// ---------------------------------------------------------------------------
FString UJJKModKitLibrary::OpenFilePicker(
    const FString& DialogTitle,
    const FString& DefaultDirectory,
    const FString& FileTypeFilter)
{
#if WITH_EDITOR
    IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
    if (!DesktopPlatform)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("[JJK Mod Kit] OpenFilePicker: DesktopPlatform module not available."));
        return FString();
    }

    FString StartDir = DefaultDirectory;
    FString DefaultFile;
    StartDir.TrimStartAndEndInline();
    if (!StartDir.IsEmpty() && FPaths::FileExists(StartDir))
    {
        DefaultFile = FPaths::GetCleanFilename(StartDir);
        StartDir = FPaths::GetPath(StartDir);
    }
    if (StartDir.IsEmpty() || !FPaths::DirectoryExists(StartDir))
    {
        StartDir = FEditorDirectories::Get().GetLastDirectory(ELastDirectory::GENERIC_OPEN);
    }

    FString Filter = FileTypeFilter;
    Filter.TrimStartAndEndInline();
    if (Filter.IsEmpty())
    {
        Filter = TEXT("All Files (*.*)|*.*");
    }

    const FString Title = DialogTitle.IsEmpty()
        ? TEXT("Select File")
        : DialogTitle;

void* ParentWindowHandle = const_cast<void*>(FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr));

    TArray<FString> OutFiles;
    const bool bOpened = DesktopPlatform->OpenFileDialog(
        ParentWindowHandle,
        Title,
        StartDir,
        DefaultFile,
        Filter,
        EFileDialogFlags::None,
        OutFiles
    );

    if (!bOpened || OutFiles.Num() == 0)
    {
        return FString();
    }

    FString Picked = OutFiles[0];
    // UE 5.1 can rewrite the selection as a path relative to Engine/Binaries/Win64.
    // Prefer the folder the dialog actually started in when that happens.
    if (FPaths::IsRelative(Picked))
    {
        const FString FromStartDir = FPaths::Combine(StartDir, FPaths::GetCleanFilename(Picked));
        if (FPaths::FileExists(FromStartDir))
        {
            Picked = FromStartDir;
        }
    }
    Picked = FPaths::ConvertRelativePathToFull(Picked);
    FPaths::NormalizeFilename(Picked);

    FEditorDirectories::Get().SetLastDirectory(
        ELastDirectory::GENERIC_OPEN, FPaths::GetPath(Picked));
    return Picked;
#else
    return FString();
#endif
}

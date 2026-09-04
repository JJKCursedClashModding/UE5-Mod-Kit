#include "JJKModKitSettings.h"

#include "Misc/Paths.h"
#if WITH_EDITOR
#include "UObject/UnrealType.h"
#endif

namespace
{
    FString MakeAbsoluteExternalPath(const FString& InPath)
    {
        FString Path = InPath;
        Path.TrimStartAndEndInline();
        if (Path.IsEmpty() || !FPaths::IsRelative(Path))
        {
            return Path;
        }
        return FPaths::ConvertRelativePathToFull(Path);
    }
}

UJJKModKitSettings::UJJKModKitSettings()
{
    // Default to the standard Steam install path for the game executable.
    // The Content/Mods folder is derived automatically as:
    //   <exe folder>/../../Content/Mods
    GameExePath.FilePath = TEXT(
        "C:\\Program Files (x86)\\Steam\\steamapps\\common\\"
        "Jujutsu Kaisen CC\\Jujutsu Kaisen CC\\Binaries\\Win64\\Jujutsu Kaisen CC.exe"
    );
    bKeepTempBuildFolders = false;
}

void UJJKModKitSettings::CanonicalizeStoredPaths()
{
    GameExePath.FilePath = MakeAbsoluteExternalPath(GameExePath.FilePath);
    UeEditorCmdPath = MakeAbsoluteExternalPath(UeEditorCmdPath);
}

void UJJKModKitSettings::PostInitProperties()
{
    Super::PostInitProperties();
    CanonicalizeStoredPaths();
}

#if WITH_EDITOR
void UJJKModKitSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    const FName MemberName = PropertyChangedEvent.GetMemberPropertyName();
    if (MemberName == GET_MEMBER_NAME_CHECKED(UJJKModKitSettings, GameExePath)
        || MemberName == GET_MEMBER_NAME_CHECKED(UJJKModKitSettings, UeEditorCmdPath)
        || PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(FFilePath, FilePath))
    {
        CanonicalizeStoredPaths();
    }
}
#endif

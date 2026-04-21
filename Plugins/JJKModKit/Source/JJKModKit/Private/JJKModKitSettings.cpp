#include "JJKModKitSettings.h"

UJJKModKitSettings::UJJKModKitSettings()
{
    // Default to the standard Steam install path for the game executable.
    // The Content/Mods folder is derived automatically as:
    //   <exe folder>/../../Content/Mods
    GameExePath.FilePath = TEXT(
        "C:\\Program Files (x86)\\Steam\\steamapps\\common\\"
        "Jujutsu Kaisen CC\\Jujutsu Kaisen CC\\Binaries\\Win64\\Jujutsu Kaisen CC.exe"
    );
}

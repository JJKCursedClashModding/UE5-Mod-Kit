#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/EngineTypes.h"
#include "JJKModKitSettings.generated.h"

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="JJK Mod Kit"))
class JJKMODKIT_API UJJKModKitSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UJJKModKitSettings();

    //~ UDeveloperSettings interface
    virtual FName GetContainerName() const override { return TEXT("Project"); }
    virtual FName GetCategoryName()  const override { return TEXT("Plugins"); }
    //~ (GetSectionName defaults to class name minus 'U' = "JJKModKitSettings")

    // ── Cooking ────────────────────────────────────────────────────────────────

    /**
     * Path to the game executable (Jujutsu Kaisen CC.exe).
     * The Content/Mods folder is derived automatically relative to this exe:
     *
     *   <exe folder>/../../Content/Mods
     *   (i.e.  Binaries/Win64 → Binaries → GameRoot → Content/Mods)
     *
     * Click the '…' button to browse for the exe.
     *
     * Default:
     *   C:\Program Files (x86)\Steam\steamapps\common\Jujutsu Kaisen CC\Jujutsu Kaisen CC\Binaries\Win64\Jujutsu Kaisen CC.exe
     */
    UPROPERTY(Config, EditAnywhere, Category="Cooking",
              meta=(DisplayName="Game Exe Path",
                    ToolTip="Path to Jujutsu Kaisen CC.exe.\nThe mods output folder is derived automatically as:\n  <exe folder>/../../Content/Mods\nClick '...' to browse.",
                    FilePathFilter="Jujutsu Kaisen CC Executable|Jujutsu Kaisen CC.exe"))
    FFilePath GameExePath;

    /**
     * Full path to UnrealEditor-Cmd.exe used for cooking.
     * Leave blank to auto-detect from standard Epic Games install locations
     * (UE 5.1 / 5.2 / 5.3 under C:/Program Files/Epic Games/).
     *
     * Example:
     *   C:\Program Files\Epic Games\UE_5.1\Engine\Binaries\Win64\UnrealEditor-Cmd.exe
     */
    UPROPERTY(Config, EditAnywhere, Category="Cooking",
              meta=(DisplayName="UnrealEditor-Cmd Path (optional)", ToolTip="Full path to UnrealEditor-Cmd.exe. Leave blank to auto-detect from standard Epic Games install paths."))
    FString UeEditorCmdPath;
};

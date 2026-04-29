#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/EngineTypes.h"
#include "JJKModKitSettings.generated.h"


/**
 * One entry in the "Core Packages to Cook" list.
 *
 * Maps a mod folder name to a list of UE package paths that live inside
 * DirectoriesToNeverCook directories and therefore need the special
 * single-package cook path to be included in that mod's output.
 *
 * Add packages via right-click → JJK Mod Kit → Add to Core Packages to Cook…
 */
USTRUCT(BlueprintType)
struct FModCorePackages
{
    GENERATED_BODY()

    /**
     * Name of the mod folder under Content/Mods/ (e.g. "MyMod").
     * Must match exactly the folder name on disk inside Content/Mods/.
     */
    UPROPERTY(Config, EditAnywhere, Category="Core Packages to Cook",
              meta=(DisplayName="Mod Folder Name"))
    FString ModName;

    /**
     * UE package paths of game assets to force-cook for this mod.
     * These assets normally live in directories listed under
     * DirectoriesToNeverCook, so they are skipped by the standard cook.
     *
     * Format : /Game/<path>/<AssetName>  — no file extension.
     * Example: /Game/Characters/CP_010/AM_SomeAttack_01
     *
     * Add entries by right-clicking an asset in the Content Browser and
     * choosing  JJK Mod Kit → Add to Core Packages to Cook…
     */
    UPROPERTY(Config, EditAnywhere, Category="Core Packages to Cook",
              meta=(DisplayName="Assets to Cook"))
    TArray<FString> PackagePaths;
};


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

    /**
     * Keep temporary cook workspaces created under Saved/CoreCookTemp/.
     * When disabled, temp build folders are deleted automatically after each
     * cook job completes.
     */
    UPROPERTY(Config, EditAnywhere, Category="Cooking",
              meta=(DisplayName="Keep Temp Build Folders",
                    ToolTip="When enabled, temporary cook workspaces under Saved/CoreCookTemp are preserved for debugging.\nWhen disabled, they are deleted automatically after cook jobs finish."))
    bool bKeepTempBuildFolders = false;

    // ── Core Packages to Cook ──────────────────────────────────────────────────

    /**
     * Per-mod lists of individual game assets that live inside
     * DirectoriesToNeverCook directories and should be force-cooked and staged.
     *
     * Each entry maps a mod folder name (under Content/Mods/) to a list of UE
     * package paths.  When you run  JJK Mod Kit → Cook Modded Game Assets, each
     * package is cooked in isolation (bypassing the NeverCook restriction) and
     * then copied to:
     *
     *   <game mods path>/<mod folder>/assets/<relative path under /Game>
     *
     * The easiest way to populate this list is to right-click an asset in the
     * Content Browser and choose  JJK Mod Kit → Add to Core Packages to Cook…
     */
    UPROPERTY(Config, EditAnywhere, Category="Core Packages to Cook",
              meta=(DisplayName="Core Packages to Cook",
                    ToolTip="Per-mod lists of game assets from DirectoriesToNeverCook to force-cook.\nRight-click any asset → JJK Mod Kit → Add to Core Packages to Cook…"))
    TArray<FModCorePackages> CorePackagesToCook;

};

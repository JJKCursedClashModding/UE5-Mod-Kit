#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JJKModKitLibrary.generated.h"

/**
 * JJK Mod Kit — Editor Utility Library
 *
 * Provides editor-facing helpers for the JJK Mod Kit that are distinct from
 * the animation/montage bridge.  Exposes functions to Python via the standard
 * BlueprintCallable pathway.
 *
 * Python usage:
 *   unreal.JJKModKitLibrary.open_jjk_mod_kit_settings()
 */
UCLASS()
class JJKMODKIT_API UJJKModKitLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Open the native Project Settings panel scrolled to the JJK Mod Kit page.
     * Equivalent to: Edit → Project Settings → Plugins → JJK Mod Kit.
     *
     * Settings are stored in Config/DefaultGame.ini under
     * [/Script/JJKModKit.JJKModKitSettings] and are read at cook/export time
     * by mod_tools.py via the UJJKModKitSettings CDO.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Settings")
    static void OpenJJKModKitSettings();

    /**
     * Open a native OS file picker and return the selected path.
     *
     * Unlike UE 5.1's stock FFilePath picker, this always returns an absolute
     * path (including files on another drive). Cancel returns an empty string.
     *
     * DefaultDirectory may be a folder or an existing file (the file's folder
     * is used as the starting directory). FileTypeFilter uses UE's pipe format:
     *   "Executable (*.exe)|*.exe|Pak (*.pak)|*.pak|All files (*.*)|*.*"
     *
     * Python:
     *   path = unreal.JJKModKitLibrary.open_file_picker(title, start, filter)
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Dialogs")
    static FString OpenFilePicker(
        const FString& DialogTitle,
        const FString& DefaultDirectory,
        const FString& FileTypeFilter
    );
};

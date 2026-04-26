#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ModKitDialogLibrary.generated.h"

// ─────────────────────────────────────────────────────────────────────────────
// EModPickerAction
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Indicates which button the user pressed in ShowModPickerDialog /
 * ShowModPickerDialogAdd.
 *
 * Python: unreal.ModPickerAction.EDIT / DELETE / ADD / CANCELLED
 */
UENUM(BlueprintType)
enum class EModPickerAction : uint8
{
    Cancelled   UMETA(DisplayName = "Cancelled"),
    Edit        UMETA(DisplayName = "Edit"),
    Delete      UMETA(DisplayName = "Delete"),
    Add         UMETA(DisplayName = "Add"),
};


// ─────────────────────────────────────────────────────────────────────────────
// FModManifestData
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Data collected by ShowModManifestDialog.
 *
 * bConfirmed is false when the user cancelled (all other fields should be ignored).
 *
 * Python usage:
 *   init = unreal.ModManifestData()
 *   init.title       = "My Mod"
 *   init.description = "Does cool stuff"
 *   init.version     = "v1"
 *   init.priority    = 0
 *
 *   result = unreal.ModKitDialogLibrary.show_mod_manifest_dialog(init, True)
 *   if result.confirmed:          # UE Python strips the 'b' prefix → "confirmed"
 *       title = str(result.title)
 */
USTRUCT(BlueprintType)
struct JJKMODKIT_API FModManifestData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "JJK Mod Kit")
    FString Title;

    UPROPERTY(BlueprintReadWrite, Category = "JJK Mod Kit")
    FString Description;

    UPROPERTY(BlueprintReadWrite, Category = "JJK Mod Kit")
    FString Version = TEXT("v1");

    UPROPERTY(BlueprintReadWrite, Category = "JJK Mod Kit")
    int32 Priority = 0;

    /** True if the user clicked Create / Save; false if they cancelled or closed the window. */
    UPROPERTY(BlueprintReadWrite, Category = "JJK Mod Kit")
    bool bConfirmed = false;
};


// ─────────────────────────────────────────────────────────────────────────────
// UModKitDialogLibrary
// ─────────────────────────────────────────────────────────────────────────────

/**
 * JJK Mod Kit — Mod Manifest Dialog Library
 *
 * Shows native Slate modal dialogs for creating or editing mod manifests.
 * All dialogs block until the user confirms or cancels, then return to Python.
 *
 * Python usage (after plugin recompile):
 *
 *   # ── Create / edit manifest ──────────────────────────────────────────────
 *   result = unreal.ModKitDialogLibrary.show_mod_manifest_dialog(
 *       unreal.ModManifestData(), True   # True = "New Mod" mode
 *   )
 *   if result.confirmed:          # UE Python strips the 'b' prefix → "confirmed"
 *       do_stuff(result.title, result.description, result.version, result.priority)
 *
 *   # ── Mod picker (edit or delete) ─────────────────────────────────────────
 *   action, chosen = unreal.ModKitDialogLibrary.show_mod_picker_dialog(["ModA", "ModB"])
 *   if action == unreal.ModPickerAction.EDIT:
 *       edit_mod(chosen)
 *   elif action == unreal.ModPickerAction.DELETE:
 *       delete_mod(chosen)   # deletion is performed by the caller (Python)
 */
UCLASS()
class JJKMODKIT_API UModKitDialogLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Open a native Slate modal dialog to create or edit a mod manifest.
     *
     * The dialog contains fields for Title, Description, Version, and Priority.
     * In "New Mod" mode a live folder-name preview is shown below the Title field.
     *
     * Blocks until the user confirms or cancels.
     *
     * @param InitialData  Pre-populate the form from this struct.
     *                     For a new mod, pass a default-constructed FModManifestData.
     * @param bIsNew       true  → "New Mod"   mode ("Create Mod" button, folder preview)
     *                     false → "Edit"       mode ("Save" button, no folder preview)
     * @return             Filled-in data.  Always check bConfirmed before using the values.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Dialogs")
    static FModManifestData ShowModManifestDialog(
        const FModManifestData& InitialData,
        bool bIsNew
    );

    /**
     * Show a listbox dialog so the user can pick one mod from ModNames.
     *
     * The dialog has three buttons:
     *   Delete — shows a confirmation prompt, then returns EModPickerAction::Delete
     *   Edit   — returns EModPickerAction::Edit  (the caller should open the edit form)
     *   Cancel — returns EModPickerAction::Cancelled
     *
     * Actual file deletion is left to the caller (Python).
     *
     * @param ModNames   Mod folder names to display.
     * @param OutChosen  Set to the selected name for Edit and Delete actions.
     * @return           EModPickerAction indicating what the user chose.
     *
     * Python: action, chosen = unreal.ModKitDialogLibrary.show_mod_picker_dialog(names)
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Dialogs")
    static EModPickerAction ShowModPickerDialog(
        const TArray<FString>& ModNames,
        FString& OutChosen
    );

    /**
     * Show a listbox dialog in "Add" mode — two buttons: Add and Cancel.
     * No Delete button.  Used when selecting the target mod for an operation
     * such as "Add to Core Packages to Cook".
     *
     * Double-clicking a row is equivalent to pressing Add.
     *
     * @param ModNames   Mod folder names to display.
     * @param OutChosen  Set to the selected name when the user clicks Add.
     * @return           EModPickerAction::Add if confirmed, Cancelled otherwise.
     *
     * Python: action, chosen = unreal.ModKitDialogLibrary.show_mod_picker_dialog_add(names)
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Dialogs")
    static EModPickerAction ShowModPickerDialogAdd(
        const TArray<FString>& ModNames,
        FString& OutChosen
    );
};

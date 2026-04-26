#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ToolMenuContext.h"          // FToolMenuContext — USTRUCT(BlueprintType)
#include "MontageBridgeLibrary.generated.h"

class UAnimMontage;

/**
 * JJK Mod Kit — Montage Bridge Library
 *
 * Exposes AnimMontage properties that carry no Blueprint / Python specifiers
 * in UE 5.1 to the Python scripting layer via a BlueprintCallable static
 * function.
 *
 * The four properties copied by CopyMontageData() are inaccessible from
 * Python's get_editor_property() / set_editor_property() because:
 *
 *   SlotAnimTracks    — UPROPERTY() with no specifiers → not exposed to BP/Python
 *   CompositeSections — UPROPERTY() with no specifiers → not exposed to BP/Python
 *   Notifies          — UPROPERTY(BlueprintReadOnly) but CPF_Protected at runtime
 *   AnimNotifyTracks  — UPROPERTY() with no specifiers → not exposed to BP/Python
 *
 * Usage from Python (after compiling and enabling the JJKModKit plugin):
 *
 *   unreal.MontageBridgeLibrary.copy_montage_data(source_montage, dest_montage)
 *
 * Call this BEFORE deleting the source asset from the asset registry so that
 * the source UObject remains valid in memory.
 */
UCLASS()
class JJKMODKIT_API UMontageBridgeLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Copy all data from Source to Dest that is inaccessible from Python in
     * UE 5.1.  Specifically copies:
     *   - SlotAnimTracks    (slot name → FAnimSegment array → AnimSequence refs)
     *   - CompositeSections (section names, start times, next-section links)
     *   - Notifies          (FAnimNotifyEvent array — timing, duration, class refs)
     *   - AnimNotifyTracks  (track label rows shown in the Montage editor timeline)
     *
     * After copying, RefreshCacheData() is called on Dest to rebuild internal
     * section/segment lookup tables, and MarkPackageDirty() ensures the editor
     * saves the new data.
     *
     * @param Source  Original (possibly cooked / game-extracted) AnimMontage.
     *                Must be valid and still loaded in memory.
     * @param Dest    Freshly created, schema-correct replacement AnimMontage.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Montage")
    static void CopyMontageData(UAnimMontage* Source, UAnimMontage* Dest);

    /**
     * Log the trigger time of every notify in Montage to the Output Log.
     * Call this after rename_asset + save_asset in Python to verify that
     * the rename/PostLoad cycle does not corrupt notify timing.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Montage")
    static void LogNotifyTimes(UAnimMontage* Montage);

    /**
     * Return the folder paths currently selected in the active Content Browser
     * (navigation/folder-tree selection).
     *
     * Calls IContentBrowserSingleton::GetSelectedFolders().
     * NOTE: This reflects LEFT-CLICK navigation selection, not the right-clicked
     * folder in a context menu.  Use GetFolderPathsFromMenuContext() instead
     * when called from a ToolMenuEntryScript.
     *
     * Returns an empty array when no folder is selected or the module is not loaded.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Editor")
    static TArray<FString> GetSelectedFolderPaths();

    /**
     * Extract the internal Content Browser folder path(s) from a live
     * FToolMenuContext, as received by ToolMenuEntryScript::Execute() /
     * ToolMenuEntryScript::GetLabel() when the user right-clicks a folder.
     *
     * WHY THIS IS NEEDED:
     *   • IContentBrowserSingleton::GetSelectedFolders() returns the navigation
     *     selection (left-click), which is empty after the context menu closes.
     *   • UContentBrowserDataMenuContext_FolderMenu::SelectedItems holds the
     *     right-clicked folder(s), but FContentBrowserItem::GetInternalPath()
     *     is NOT a UFUNCTION so it cannot be called from Python directly.
     *   • FToolMenuContext::FindContext<T>() is NOT a UFUNCTION either, so Python
     *     cannot reach the context object on its own.
     *
     * This bridge calls Context.FindContext<UContentBrowserDataMenuContext_FolderMenu>()
     * in C++ and returns the internal paths (e.g. "/Game/Characters/CP_010").
     *
     * Typical use from Python (inside ToolMenuEntryScript.get_label() or .execute()):
     *
     *   paths = unreal.MontageBridgeLibrary.get_folder_paths_from_tool_menu_context(context)
     *   if paths:
     *       _jjk_captured_folder[0] = str(paths[0]).rstrip('/')
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Editor")
    static TArray<FString> GetFolderPathsFromToolMenuContext(const FToolMenuContext& Context);

    /**
     * Dump a comprehensive debug snapshot of Montage to the Output Log:
     *   - SequenceLength  (actual playback length)
     *   - AnimDataModel   (PlayLength, FrameRate, NumberOfFrames, NumberOfKeys)
     *   - SlotAnimTracks  (per-segment AnimSequence ref, StartPos, AnimStart/End)
     *   - Every notify    (name, GetTime, LinkValue, TriggerTimeOffset, GetTriggerTime)
     *
     * Use this to check whether opening the montage in the editor causes
     * the engine to recalculate / corrupt any of these values.
     *
     * @param Montage  The montage to inspect.  Pass nullptr to do nothing.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Debug")
    static void DumpMontageDebugInfo(UAnimMontage* Montage);

    /**
     * Force the Project Settings "JJK Mod Kit" panel to reflect the latest
     * values in Config/DefaultGame.ini immediately, without restarting the editor.
     *
     * Steps:
     *   1. Reads Config/DefaultGame.ini from disk (bypassing the in-memory
     *      merged config cache) and applies the parsed values directly to the CDO.
     *   2. Broadcasts a property-change event for CorePackagesToCook.
     *   3. Asks the PropertyEditor module to refresh details views.
     *
     * Called from Python after add_to_core_packages() / remove_from_core_packages()
     * so that the panel is live-updated without a restart.
     *
     * Python: unreal.MontageBridgeLibrary.refresh_mod_kit_settings()
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Editor")
    static void RefreshModKitSettings();
};

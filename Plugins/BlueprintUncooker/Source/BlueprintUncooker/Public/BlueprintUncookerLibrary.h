#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintUncookerLibrary.generated.h"

/**
 * Python-callable static library for the Blueprint Uncooker.
 *
 * All UFUNCTION(BlueprintCallable) statics here are automatically
 * available from Unreal's Python plugin as:
 *
 *   import unreal
 *   result = unreal.BlueprintUncookerLibrary.uncook_blueprint_asset(
 *       '/Game/Characters/GameCharacter_BP',
 *       '/Game/Characters/Uncooked/GameCharacter_BP'
 *   )
 */
UCLASS()
class BLUEPRINTUNCOOKER_API UBlueprintUncookerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Decompile and reconstruct a Blueprint asset from its cooked bytecode.
	 *
	 * @param SourceAssetPath  Content-browser path of the cooked Blueprint or
	 *                         its generated class, e.g.
	 *                         "/Game/Characters/GameCharacter_BP"
	 * @param OutputPath       Where to save the new asset, e.g.
	 *                         "/Game/Characters/Uncooked/GameCharacter_BP"
	 *                         If empty, defaults to
	 *                         <SourcePackagePath>/Uncooked/<AssetName>
	 * @return                 Human-readable status string describing the result.
	 */
	UFUNCTION(BlueprintCallable, Category = "BlueprintUncooker",
		meta = (CallInEditor = "true"))
	static FString UncookBlueprintAsset(
		const FString& SourceAssetPath,
		const FString& OutputPath = TEXT(""));

	/**
	 * Uncook as child class: the reconstructed Blueprint's parent IS the
	 * original cooked BPGC, so all casts still succeed at runtime.
	 *
	 * @param SourceAssetPath  Cooked Blueprint or generated class path.
	 * @param OutputPath       Output path (optional).
	 * @return                 Status string.
	 */
	UFUNCTION(BlueprintCallable, Category = "BlueprintUncooker",
		meta = (CallInEditor = "true"))
	static FString UncookBlueprintAsChildClass(
		const FString& SourceAssetPath,
		const FString& OutputPath = TEXT(""));

	/**
	 * Uncook every Blueprint in a given content directory (non-recursive).
	 *
	 * @param ContentDir       e.g. "/Game/Characters"
	 * @param OutputParentDir  Parent dir for Uncooked/ sub-folders.
	 *                         If empty, uses ContentDir/Uncooked/.
	 * @return                 Summary string: "X/Y succeeded."
	 */
	UFUNCTION(BlueprintCallable, Category = "BlueprintUncooker",
		meta = (CallInEditor = "true"))
	static FString UncookAllBlueprintsInDirectory(
		const FString& ContentDir,
		const FString& OutputParentDir = TEXT(""));

	/**
	 * Uncook a Blueprint from an absolute filesystem path outside the project.
	 * The asset is loaded via a temporary UE package mount point — the file
	 * never needs to be copied into Content/.
	 *
	 * @param AbsoluteAssetPath   Full path to the cooked .uasset file,
	 *                            e.g. "C:/JJK/Content/Characters/CP_030_00_BP.uasset"
	 * @param OutputPackagePath   UE package path for the output blueprint,
	 *                            e.g. "/Game/Uncooked/Characters/CP_030_00_BP"
	 * @param MountPointName      Temporary mount point prefix (must start/end with '/').
	 *                            Leave empty to use "/ExternalCooked/".
	 * @param ExternalContentDir  Root Content/ directory for deriving package names.
	 *                            Leave empty to auto-detect by searching for a "Content"
	 *                            ancestor in AbsoluteAssetPath.
	 * @return                    Status string; starts with "ERROR:" on failure.
	 */
	UFUNCTION(BlueprintCallable, Category = "BlueprintUncooker",
		meta = (CallInEditor = "true"))
	static FString UncookExternalBlueprint(
		const FString& AbsoluteAssetPath,
		const FString& OutputPackagePath,
		const FString& MountPointName      = TEXT(""),
		const FString& ExternalContentDir  = TEXT(""));

	/**
	 * Walk an external cooked Content/ folder recursively and uncook every
	 * Blueprint asset whose filename matches JJK CC naming patterns:
	 *   Prefix: ABP_*, BP_*, WBP_*
	 *   Suffix: *_BP, *_ABP
	 * The relative directory structure is preserved under OutputBase.
	 *
	 * @param ExternalContentDir  Absolute path to the cooked Content/ root.
	 *                            E.g. "C:/JJK/Content"
	 * @param OutputBase          UE package path prefix (default "/Game/Uncooked").
	 * @param MountPointName      Temporary mount point name.
	 * @param bDryRun             If true, log what would be processed without saving.
	 * @return                    Summary string "N/M succeeded." or error.
	 */
	UFUNCTION(BlueprintCallable, Category = "BlueprintUncooker",
		meta = (CallInEditor = "true"))
	static FString UncookExternalFolder(
		const FString& ExternalContentDir,
		const FString& OutputBase      = TEXT("/Game/Uncooked"),
		const FString& MountPointName  = TEXT(""),
		bool bDryRun                   = false);

private:
	/** Shared implementation: resolves source, builds, compiles, saves. */
	static FString UncookImpl(
		const FString& SourceAssetPath,
		const FString& OutputPath,
		bool bChildClass);

	/** Auto-derive output path from source if not specified. */
	static FString DeriveOutputPath(
		const FString& SourceAssetPath,
		const FString& UserOutputPath);
};

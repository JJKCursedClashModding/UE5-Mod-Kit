#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UncookLibrary.generated.h"

class USkeletalMesh;
class USkeleton;
class UTexture;
class UMaterialInterface;

/**
 * JJK Mod Kit — Uncook Library
 *
 * Provides C++-level asset uncooking that sets ALL FBX import/export options,
 * including uint32 bitfield UPROPERTYs that are invisible to Python in UE 5.1
 * because they lack BlueprintReadWrite.
 *
 * In UE 5.1 Python, these properties on UFbxSkeletalMeshImportData silently
 * fail to assign because they are bitfields without BlueprintReadWrite:
 *
 *   bImportMorphTargets          (EditAnywhere only)
 *   bPreserveSmoothingGroups     (EditAnywhere only)
 *   bImportMeshesInBoneHierarchy (EditAnywhere only)
 *   bUseT0AsRefPose              (EditAnywhere only)
 *
 * This library sets them in C++ where full UPROPERTY access is always available.
 *
 * Usage from Python (after compiling the JJKModKit plugin):
 *
 *   import unreal
 *   ok = unreal.UncookLibrary.uncook_mesh(
 *       source_skeletal_mesh,
 *       "/Game/Characters/Meshes/Uncooked/SK_Char",  # destination package path
 *       "",   # FBX save dir — empty = <Project>/Saved/UncookedMeshes/
 *   )
 */
UCLASS()
class JJKMODKIT_API UUncookLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /**
     * Export SourceMesh to FBX (fully silent, no options dialog) and
     * immediately re-import it as a new SkeletalMesh asset at DestinationPath.
     *
     * All import settings are configured in C++ so every bitfield option is
     * properly applied:
     *   bImportMorphTargets          = true
     *   bPreserveSmoothingGroups     = true
     *   bImportMeshesInBoneHierarchy = true
     *   bUseT0AsRefPose              = false
     *   bConvertScene                = true
     *   bForceFrontXAxis             = false
     *   bImportMaterials             = false
     *   bImportTextures              = false
     *   bImportAnimations            = false
     *   Skeleton                     = reused from SourceMesh (keeps anim compat)
     *
     * @param SourceMesh       Cooked SkeletalMesh to uncook.  Must be non-null.
     * @param DestinationPath  Target package path, e.g.
     *                         "/Game/Characters/Meshes/Uncooked/SK_Char"
     * @param FbxSaveDir       Absolute filesystem path where the intermediate
     *                         FBX is written.  Pass an empty string to use the
     *                         default:  <Project>/Saved/UncookedMeshes/
     * @return  true  if the new asset exists at DestinationPath after import.
     *          false if export or import failed (check Output Log for details).
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Uncook",
              meta = (AutoCreateRefTerm = "FbxSaveDir"))
    static bool UncookMesh(
        USkeletalMesh*  SourceMesh,
        const FString&  DestinationPath,
        const FString&  FbxSaveDir
    );

    /**
     * Duplicate the cooked Texture to DestinationPath, preserving every
     * setting (SRGB, CompressionSettings, Filter, MipGenSettings, AddressX/Y,
     * LODBias, LODGroup, bFlipGreenChannel, etc.) that Python cannot reliably
     * set from outside C++ due to missing BlueprintReadWrite specifiers.
     *
     * Uses IAssetTools::DuplicateAsset so no intermediate file is needed;
     * all source data (pixel data + settings) are carried over atomically.
     *
     * @param SourceTexture   Cooked Texture2D / TextureCube / etc. to clone.
     * @param DestinationPath Target package path, e.g.
     *                        "/Game/Characters/Textures/Uncooked/T_Skin"
     * @param TempSaveDir     If DuplicateAsset fails, this function falls back
     *                        to TGA export + reimport; the TGA lands here.
     *                        Pass "" to use  <Project>/Saved/UncookedTextures/
     * @return true if the asset exists at DestinationPath after the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Uncook",
              meta = (AutoCreateRefTerm = "TempSaveDir"))
    static bool UncookTexture(
        UTexture*       SourceTexture,
        const FString&  DestinationPath,
        const FString&  TempSaveDir
    );

    /**
     * Duplicate the cooked Material (or the root Material of a
     * MaterialInstance chain) to DestinationPath, creating a fully editable
     * Material asset with all properties intact.
     *
     * MaterialInstance inputs are resolved to their root Material before
     * duplicating so the result is always a real Material, not an instance.
     *
     * @param SourceMaterial  Any UMaterialInterface — Material or instance.
     * @param DestinationPath Target package path.
     * @return true on success.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Uncook")
    static bool UncookMaterial(
        UMaterialInterface* SourceMaterial,
        const FString&      DestinationPath
    );

    /**
     * Create an editable Blueprint subclass of SourceObject's C++ class at
     * DestinationPath, then copy ALL UPROPERTY values — including EditAnywhere-
     * only bitfields that Python cannot write — from SourceObject to the new
     * Blueprint's Class Default Object.
     *
     * Properties skipped: Transient, DuplicateTransient, SkipSerialization.
     * Everything else (EditAnywhere, BlueprintReadWrite, config, etc.) is
     * copied via direct UPROPERTY field iteration, bypassing all Python
     * reflection limits.
     *
     * @param SourceObject    The cooked data object to replicate
     *                        (e.g. a GameWidgetParameterBase archetype).
     * @param DestinationPath Target package path for the new Blueprint.
     * @return true if the Blueprint was created and saved successfully.
     */
    UFUNCTION(BlueprintCallable, Category = "JJK Mod Kit|Uncook")
    static bool UncookBlueprintableObject(
        UObject*        SourceObject,
        const FString&  DestinationPath
    );

private:
    /** Save Asset's package to disk and notify the Asset Registry. */
    static bool SaveUncookedAsset(UObject* Asset, const FString& PackagePath);
};

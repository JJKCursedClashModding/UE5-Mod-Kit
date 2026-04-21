#include "UncookLibrary.h"

// Core engine
#include "Engine/SkeletalMesh.h"
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Animation/Skeleton.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "Misc/Paths.h"
#include "Misc/PackageName.h"
#include "HAL/FileManager.h"
#include "UObject/SavePackage.h"

// Export
#include "Exporters/Exporter.h"          // UExporter::RunAssetExportTask
#include "AssetExportTask.h"             // UAssetExportTask
#include "Exporters/FbxExportOption.h"   // UFbxExportOption — suppresses dialog in automated mode

// Import
#include "AssetImportTask.h"
#include "Factories/FbxImportUI.h"
#include "Factories/FbxSkeletalMeshImportData.h"

// Asset tools (duplicate, import pipeline)
#include "AssetToolsModule.h"
#include "IAssetTools.h"

// Asset registry (post-op notifications + existence checks)
#include "AssetRegistry/AssetRegistryModule.h"

// Blueprint creation + compilation
#include "Kismet2/KismetEditorUtilities.h"

DEFINE_LOG_CATEGORY_STATIC(LogJJKUncook, Log, All);

// ─────────────────────────────────────────────────────────────────────────────
// Internal helpers
// ─────────────────────────────────────────────────────────────────────────────

static IAssetTools& GetAssetTools()
{
    return FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools")).Get();
}

/**
 * Save Asset's owning package to <DestPackagePath>.uasset and tell the Asset
 * Registry about it so the Content Browser updates immediately.
 */
bool UUncookLibrary::SaveUncookedAsset(UObject* Asset, const FString& PackagePath)
{
    if (!Asset)
    {
        UE_LOG(LogJJKUncook, Error, TEXT("SaveUncookedAsset: Asset is null."));
        return false;
    }

    UPackage* Package = Asset->GetPackage();
    if (!Package)
    {
        UE_LOG(LogJJKUncook, Error, TEXT("SaveUncookedAsset: Asset has no package."));
        return false;
    }

    Package->MarkPackageDirty();

    FString PackageFilename;
    if (!FPackageName::TryConvertLongPackageNameToFilename(
            PackagePath, PackageFilename, FPackageName::GetAssetPackageExtension()))
    {
        UE_LOG(LogJJKUncook, Error,
            TEXT("SaveUncookedAsset: Cannot map package path to filename: %s"), *PackagePath);
        return false;
    }

    FSavePackageArgs SaveArgs;
    SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
    const bool bSaved = UPackage::SavePackage(Package, Asset, *PackageFilename, SaveArgs);

    if (bSaved)
    {
        // Notify the asset registry so the Content Browser refreshes
        FAssetRegistryModule& ARModule =
            FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
        ARModule.Get().ScanFilesSynchronous({PackageFilename});

        UE_LOG(LogJJKUncook, Log, TEXT("SaveUncookedAsset: saved → %s"), *PackageFilename);
    }
    else
    {
        UE_LOG(LogJJKUncook, Warning,
            TEXT("SaveUncookedAsset: UPackage::SavePackage returned false for %s"), *PackagePath);
    }
    return bSaved;
}

// ─────────────────────────────────────────────────────────────────────────────
// UncookMesh — SkeletalMesh → DuplicateAsset (primary) → FBX fallback
// ─────────────────────────────────────────────────────────────────────────────

bool UUncookLibrary::UncookMesh(
    USkeletalMesh*  SourceMesh,
    const FString&  DestinationPath,
    const FString&  FbxSaveDir)
{
    if (!SourceMesh)
    {
        UE_LOG(LogJJKUncook, Error, TEXT("UncookMesh: SourceMesh is null."));
        return false;
    }
    if (DestinationPath.IsEmpty())
    {
        UE_LOG(LogJJKUncook, Error, TEXT("UncookMesh: DestinationPath is empty."));
        return false;
    }

    const FString DestFolder = FPackageName::GetLongPackagePath(DestinationPath);
    const FString DestName   = FPackageName::GetShortName(DestinationPath);

    // ── Primary path: DuplicateAsset ─────────────────────────────────────────
    // Atomically clones all mesh data (geometry, LODs, skeleton binding,
    // physics asset, morph targets, materials, …) without an intermediate file.
    // This is the preferred path because cooked SkeletalMesh assets may have
    // their geometry in compressed platform data that the FBX exporter cannot
    // access, producing a skeleton-only FBX with no mesh geometry.
    {
        UObject* Dup = GetAssetTools().DuplicateAsset(DestName, DestFolder, SourceMesh);
        if (Dup)
        {
            if (SaveUncookedAsset(Dup, DestinationPath))
            {
                UE_LOG(LogJJKUncook, Log,
                    TEXT("UncookMesh: ✓ SkeletalMesh duplicated → %s"), *DestinationPath);
                return true;
            }
        }
        UE_LOG(LogJJKUncook, Warning,
            TEXT("UncookMesh: DuplicateAsset failed for %s — falling back to FBX export."),
            *SourceMesh->GetName());
    }

    // ── Fallback: FBX export + re-import ─────────────────────────────────────
    // Used when DuplicateAsset is unavailable.  Note: for heavily cooked assets
    // the FBX may only contain the skeleton hierarchy (no geometry) if the raw
    // vertex data is not present in editor memory.
    //
    // UFbxExportOption MUST be set on ExportTask->Options so that the FBX
    // exporter respects bAutomated=true and suppresses its own dialog — without
    // it the dialog appears even when bPrompt=false.

    FString SaveDir = FbxSaveDir.IsEmpty()
        ? FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("UncookedMeshes"))
        : FbxSaveDir;
    FPaths::NormalizeDirectoryName(SaveDir);
    IFileManager::Get().MakeDirectory(*SaveDir, /*Tree=*/true);

    const FString FbxPath = FPaths::Combine(SaveDir, SourceMesh->GetName() + TEXT(".fbx"));

    {
        UFbxExportOption* FbxOpts = NewObject<UFbxExportOption>();
        FbxOpts->Collision              = false;
        FbxOpts->VertexColor            = true;
        FbxOpts->LevelOfDetail          = false;
        FbxOpts->bExportMorphTargets    = true;   // carry morph targets into the FBX

        UAssetExportTask* ExportTask = NewObject<UAssetExportTask>();
        ExportTask->Object            = SourceMesh;
        ExportTask->Filename          = FbxPath;
        ExportTask->bSelected         = false;
        ExportTask->bReplaceIdentical = true;
        ExportTask->bPrompt           = false;
        ExportTask->bAutomated        = true;
        ExportTask->Options           = FbxOpts;  // required to suppress FBX dialog

        if (!UExporter::RunAssetExportTask(ExportTask) || !IFileManager::Get().FileExists(*FbxPath))
        {
            UE_LOG(LogJJKUncook, Error,
                TEXT("UncookMesh: FBX export also failed — %s not found."), *FbxPath);
            return false;
        }
        UE_LOG(LogJJKUncook, Log, TEXT("UncookMesh: exported FBX → %s"), *FbxPath);
    }

    // ── FBX import UI — every bitfield set in C++ ─────────────────────────────
    // Python cannot write bImportMorphTargets / bPreserveSmoothingGroups /
    // bImportMeshesInBoneHierarchy / bUseT0AsRefPose because those are
    // uint32 bitfields WITHOUT BlueprintReadWrite on UFbxSkeletalMeshImportData.

    UFbxImportUI* ImportUI = NewObject<UFbxImportUI>();
    ImportUI->bImportMesh                      = true;
    ImportUI->bImportAsSkeletal                = true;
    ImportUI->bImportMaterials                 = false;
    ImportUI->bImportTextures                  = false;
    ImportUI->bImportAnimations                = false;
    ImportUI->bAutomatedImportShouldDetectType = false;
    ImportUI->MeshTypeToImport                 = FBXIT_SkeletalMesh;

    if (USkeleton* Skel = SourceMesh->GetSkeleton())
    {
        ImportUI->Skeleton = Skel;
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookMesh: reusing skeleton %s"), *Skel->GetPathName());
    }

    UFbxSkeletalMeshImportData* SkData = ImportUI->SkeletalMeshImportData;
    check(SkData);
    SkData->bImportMorphTargets          = true;
    SkData->bImportMeshesInBoneHierarchy = true;
    SkData->bPreserveSmoothingGroups     = true;
    SkData->bUseT0AsRefPose              = false;
    SkData->bConvertScene                = true;
    SkData->bForceFrontXAxis             = false;

    UAssetImportTask* ImportTask = NewObject<UAssetImportTask>();
    ImportTask->Filename         = FbxPath;
    ImportTask->DestinationPath  = DestFolder;
    ImportTask->DestinationName  = DestName;
    ImportTask->bReplaceExisting = true;
    ImportTask->bAutomated       = true;
    ImportTask->bSave            = true;
    ImportTask->Options          = ImportUI;

    TArray<UAssetImportTask*> Tasks = { ImportTask };
    GetAssetTools().ImportAssetTasks(Tasks);

    const bool bSuccess = ImportTask->ImportedObjectPaths.Num() > 0;
    if (bSuccess)
    {
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookMesh: ✓ SkeletalMesh (FBX path) → %s"), *DestinationPath);
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookMesh:   FBX kept at %s"), *FbxPath);
    }
    else
    {
        UE_LOG(LogJJKUncook, Warning,
            TEXT("UncookMesh: FBX import also returned no objects for %s.  "
                 "The mesh may have geometry only in cooked platform data."), *DestinationPath);
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookMesh:   FBX kept for manual import: %s"), *FbxPath);
    }
    return bSuccess;
}

// ─────────────────────────────────────────────────────────────────────────────
// UncookTexture — Texture → DuplicateAsset (preserves all settings atomically)
// ─────────────────────────────────────────────────────────────────────────────

bool UUncookLibrary::UncookTexture(
    UTexture*       SourceTexture,
    const FString&  DestinationPath,
    const FString&  TempSaveDir)
{
    if (!SourceTexture)
    {
        UE_LOG(LogJJKUncook, Error, TEXT("UncookTexture: SourceTexture is null."));
        return false;
    }

    const FString DestFolder = FPackageName::GetLongPackagePath(DestinationPath);
    const FString DestName   = FPackageName::GetShortName(DestinationPath);

    // ── Primary path: DuplicateAsset ─────────────────────────────────────────
    // Atomically copies pixel data + every setting (SRGB, CompressionSettings,
    // Filter, MipGenSettings, AddressX/Y, LODGroup, bFlipGreenChannel, …).
    // Works because editor assets store their source data in memory even for
    // game-extracted textures.
    {
        UObject* Dup = GetAssetTools().DuplicateAsset(DestName, DestFolder, SourceTexture);
        if (Dup)
        {
            if (SaveUncookedAsset(Dup, DestinationPath))
            {
                UE_LOG(LogJJKUncook, Log,
                    TEXT("UncookTexture: ✓ Texture duplicated → %s"), *DestinationPath);
                return true;
            }
        }
        UE_LOG(LogJJKUncook, Warning,
            TEXT("UncookTexture: DuplicateAsset failed for %s — falling back to TGA export."),
            *SourceTexture->GetName());
    }

    // ── Fallback: TGA export + reimport + property copy ──────────────────────
    FString SaveDir = TempSaveDir.IsEmpty()
        ? FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("UncookedTextures"))
        : TempSaveDir;
    FPaths::NormalizeDirectoryName(SaveDir);
    IFileManager::Get().MakeDirectory(*SaveDir, /*Tree=*/true);

    const FString TgaPath = FPaths::Combine(SaveDir, SourceTexture->GetName() + TEXT(".tga"));

    UAssetExportTask* ExportTask = NewObject<UAssetExportTask>();
    ExportTask->Object            = SourceTexture;
    ExportTask->Filename          = TgaPath;
    ExportTask->bReplaceIdentical = true;
    ExportTask->bPrompt           = false;
    ExportTask->bAutomated        = true;

    if (!UExporter::RunAssetExportTask(ExportTask) || !IFileManager::Get().FileExists(*TgaPath))
    {
        UE_LOG(LogJJKUncook, Error,
            TEXT("UncookTexture: TGA export also failed — %s not found."), *TgaPath);
        return false;
    }
    UE_LOG(LogJJKUncook, Log, TEXT("UncookTexture: exported TGA → %s"), *TgaPath);

    UAssetImportTask* ImportTask = NewObject<UAssetImportTask>();
    ImportTask->Filename         = TgaPath;
    ImportTask->DestinationPath  = DestFolder;
    ImportTask->DestinationName  = DestName;
    ImportTask->bReplaceExisting = true;
    ImportTask->bAutomated       = true;
    ImportTask->bSave            = false;   // save after property copy

    TArray<UAssetImportTask*> Tasks = { ImportTask };
    GetAssetTools().ImportAssetTasks(Tasks);

    if (ImportTask->ImportedObjectPaths.IsEmpty())
    {
        UE_LOG(LogJJKUncook, Error,
            TEXT("UncookTexture: reimport returned no objects for %s"), *DestinationPath);
        return false;
    }

    // Load the newly created texture and copy all non-pixel settings from source
    UTexture* NewTexture = Cast<UTexture>(
        StaticLoadObject(UTexture::StaticClass(), nullptr, *DestinationPath));
    if (!NewTexture)
    {
        UE_LOG(LogJJKUncook, Warning,
            TEXT("UncookTexture: imported but could not load %s — settings not copied."),
            *DestinationPath);
        return true;
    }

    // Copy every UPROPERTY that is NOT the raw pixel / platform data.
    // In C++ we iterate ALL properties regardless of BlueprintReadWrite status.
    static const TSet<FName> SkipProps = {
        TEXT("Source"),            // FTextureSource — raw pixel data (already imported)
        TEXT("PlatformData"),      // FTexturePlatformData* — cooked platform mips
        TEXT("PrivatePlatformData"),
        TEXT("ImportedSize"),
        TEXT("AssetImportData"),
    };

    UClass* TexClass = SourceTexture->GetClass();
    int32   Copied   = 0;
    for (TFieldIterator<FProperty> It(TexClass, EFieldIteratorFlags::IncludeSuper); It; ++It)
    {
        FProperty* Prop = *It;
        if (Prop->HasAnyPropertyFlags(CPF_Transient | CPF_DuplicateTransient | CPF_SkipSerialization))
            continue;
        if (SkipProps.Contains(Prop->GetFName()))
            continue;
        if (!NewTexture->GetClass()->IsChildOf(TexClass))
            continue;   // destination is a narrower class — skip parent-only props

        const void* SrcVal = Prop->ContainerPtrToValuePtr<const void>(SourceTexture);
        void*       DstVal = Prop->ContainerPtrToValuePtr<void>(NewTexture);
        Prop->CopyCompleteValue(DstVal, SrcVal);
        ++Copied;
    }
    UE_LOG(LogJJKUncook, Log,
        TEXT("UncookTexture: copied %d texture settings from source."), Copied);

    NewTexture->UpdateResource();
    NewTexture->PostEditChange();

    const bool bSaved = SaveUncookedAsset(NewTexture, DestinationPath);
    if (bSaved)
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookTexture: ✓ Texture → %s  (TGA at %s)"), *DestinationPath, *TgaPath);
    return bSaved;
}

// ─────────────────────────────────────────────────────────────────────────────
// UncookMaterial — Material/MaterialInstance → duplicate root Material in C++
// ─────────────────────────────────────────────────────────────────────────────

bool UUncookLibrary::UncookMaterial(
    UMaterialInterface* SourceMaterial,
    const FString&      DestinationPath)
{
    if (!SourceMaterial)
    {
        UE_LOG(LogJJKUncook, Error, TEXT("UncookMaterial: SourceMaterial is null."));
        return false;
    }

    // ── Resolve MaterialInstance chain → root Material ────────────────────────
    UMaterialInterface* Current = SourceMaterial;
    while (UMaterialInstance* MI = Cast<UMaterialInstance>(Current))
    {
        if (!MI->Parent)
        {
            UE_LOG(LogJJKUncook, Warning,
                TEXT("UncookMaterial: MaterialInstance %s has null Parent — using it as-is."),
                *MI->GetName());
            break;
        }
        Current = MI->Parent;
    }
    UMaterial* RootMaterial = Cast<UMaterial>(Current);
    if (!RootMaterial)
    {
        UE_LOG(LogJJKUncook, Error,
            TEXT("UncookMaterial: Could not resolve root Material from %s."),
            *SourceMaterial->GetName());
        return false;
    }

    if (RootMaterial != SourceMaterial)
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookMaterial: resolved MI chain → %s"), *RootMaterial->GetName());

    // ── Duplicate the root Material (carries all node properties) ────────────
    const FString DestFolder = FPackageName::GetLongPackagePath(DestinationPath);
    const FString DestName   = FPackageName::GetShortName(DestinationPath);

    UObject* Dup = GetAssetTools().DuplicateAsset(DestName, DestFolder, RootMaterial);
    if (!Dup)
    {
        UE_LOG(LogJJKUncook, Error,
            TEXT("UncookMaterial: DuplicateAsset failed for %s → %s"),
            *RootMaterial->GetName(), *DestinationPath);
        return false;
    }

    const bool bSaved = SaveUncookedAsset(Dup, DestinationPath);
    if (bSaved)
    {
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookMaterial: ✓ Material duplicated → %s"), *DestinationPath);
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookMaterial:   Source root = %s"), *RootMaterial->GetPathName());
    }
    return bSaved;
}

// ─────────────────────────────────────────────────────────────────────────────
// UncookBlueprintableObject — any UObject → Blueprint subclass with ALL props
// ─────────────────────────────────────────────────────────────────────────────

bool UUncookLibrary::UncookBlueprintableObject(
    UObject*        SourceObject,
    const FString&  DestinationPath)
{
    if (!SourceObject)
    {
        UE_LOG(LogJJKUncook, Error, TEXT("UncookBlueprintableObject: SourceObject is null."));
        return false;
    }

    UClass* SourceClass = SourceObject->GetClass();

    // Note: we attempt Blueprint creation regardless of the Blueprintable flag —
    // if the class is truly non-blueprintable, FKismetEditorUtilities::CreateBlueprint
    // will return nullptr and we bail out cleanly below.
    const FString DestName = FPackageName::GetShortName(DestinationPath);

    // ── 1. Create the Blueprint package ──────────────────────────────────────
    UPackage* Package = CreatePackage(*DestinationPath);
    if (!Package)
    {
        UE_LOG(LogJJKUncook, Error,
            TEXT("UncookBlueprintableObject: CreatePackage failed for %s"), *DestinationPath);
        return false;
    }
    Package->SetPackageFlags(PKG_NewlyCreated);

    // ── 2. Create the Blueprint object ────────────────────────────────────────
    UBlueprint* NewBP = FKismetEditorUtilities::CreateBlueprint(
        SourceClass,
        Package,
        *DestName,
        BPTYPE_Normal,
        UBlueprint::StaticClass(),
        UBlueprintGeneratedClass::StaticClass()
    );
    if (!NewBP)
    {
        UE_LOG(LogJJKUncook, Error,
            TEXT("UncookBlueprintableObject: CreateBlueprint failed for class %s at %s"),
            *SourceClass->GetName(), *DestinationPath);
        return false;
    }

    // ── 3. Copy ALL properties from SourceObject → new Blueprint CDO ─────────
    //
    // Iterates every UPROPERTY on the class hierarchy, including:
    //   • EditAnywhere-only bitfields (invisible to Python in UE 5.1)
    //   • config, VisibleAnywhere, etc.
    // Skips only: Transient, DuplicateTransient, SkipSerialization.
    //
    // This is the core advantage of C++ over Python for "parameter" assets:
    // Python can only write BlueprintReadWrite properties; here we copy all.

    if (UBlueprintGeneratedClass* GenClass = Cast<UBlueprintGeneratedClass>(NewBP->GeneratedClass))
    {
        UObject* DestCDO = GenClass->GetDefaultObject(/*bCreateIfNeeded=*/true);
        if (DestCDO)
        {
            int32 Copied  = 0;
            int32 Skipped = 0;

            for (TFieldIterator<FProperty> It(SourceClass, EFieldIteratorFlags::IncludeSuper);
                 It; ++It)
            {
                FProperty* Prop = *It;

                // Skip properties that must not be copied between unrelated objects
                if (Prop->HasAnyPropertyFlags(
                        CPF_Transient | CPF_DuplicateTransient | CPF_SkipSerialization))
                {
                    ++Skipped;
                    continue;
                }

                // Ensure both source and dest have the property (they share the same
                // class hierarchy since NewBP subclasses SourceClass)
                if (!DestCDO->GetClass()->IsChildOf(SourceClass))
                {
                    ++Skipped;
                    continue;
                }

                const void* SrcVal = Prop->ContainerPtrToValuePtr<const void>(SourceObject);
                void*       DstVal = Prop->ContainerPtrToValuePtr<void>(DestCDO);
                Prop->CopyCompleteValue(DstVal, SrcVal);
                ++Copied;
            }

            UE_LOG(LogJJKUncook, Log,
                TEXT("UncookBlueprintableObject: copied %d properties (%d skipped) → CDO of %s"),
                Copied, Skipped, *DestinationPath);

            DestCDO->PostEditChange();
        }
    }
    else
    {
        UE_LOG(LogJJKUncook, Warning,
            TEXT("UncookBlueprintableObject: GeneratedClass not available yet — "
                 "properties not copied. Open Blueprint → Class Defaults to set them."));
    }

    // ── 4. Compile the Blueprint so GeneratedClass is fully up to date ────────
    FKismetEditorUtilities::CompileBlueprint(NewBP);

    // ── 5. Save ───────────────────────────────────────────────────────────────
    const bool bSaved = SaveUncookedAsset(NewBP, DestinationPath);
    if (bSaved)
        UE_LOG(LogJJKUncook, Log,
            TEXT("UncookBlueprintableObject: ✓ Blueprint → %s  (parent class: %s)"),
            *DestinationPath, *SourceClass->GetName());
    return bSaved;
}

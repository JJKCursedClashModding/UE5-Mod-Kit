#include "BlueprintUncookerModule.h"
#include "BytecodeReader.h"
#include "GraphBuilder.h"
#include "GraphValidator.h"

#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"

#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"

#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"

#include "Styling/AppStyle.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#include "Misc/ScopedSlowTask.h"
#include "UObject/SavePackage.h"
#include "UObject/LinkerLoad.h"          // FLinkerLoad::Preload — force-serialise deferred Blueprint CDOs
#include "Engine/DynamicBlueprintBinding.h"
#include "PackageTools.h"
#include "FileHelpers.h"

// Widget Blueprint support
#include "Blueprint/WidgetBlueprintGeneratedClass.h"

IMPLEMENT_MODULE(FBlueprintUncookerModule, BlueprintUncooker)
DEFINE_LOG_CATEGORY(LogBlueprintUncooker);

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static void ShowNotification(const FString& Message, bool bSuccess)
{
	FNotificationInfo Info(FText::FromString(Message));
	Info.ExpireDuration = 5.f;
	Info.bFireAndForget = true;
	Info.Image = FAppStyle::GetBrush(bSuccess ? TEXT("NotificationList.SuccessImage")
	                                           : TEXT("NotificationList.FailImage"));
	FSlateNotificationManager::Get().AddNotification(Info);
}

// ---------------------------------------------------------------------------
// Module lifecycle
// ---------------------------------------------------------------------------

void FBlueprintUncookerModule::StartupModule()
{
	FContentBrowserModule& CBM =
		FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	TArray<FContentBrowserMenuExtender_SelectedAssets>& Extenders =
		CBM.GetAllAssetViewContextMenuExtenders();

	Extenders.Add(FContentBrowserMenuExtender_SelectedAssets::CreateRaw(
		this, &FBlueprintUncookerModule::ExtendContentBrowserMenu));

	ContentBrowserExtenderHandle = Extenders.Last().GetHandle();
}

void FBlueprintUncookerModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
	{
		FContentBrowserModule& CBM =
			FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");

		TArray<FContentBrowserMenuExtender_SelectedAssets>& Extenders =
			CBM.GetAllAssetViewContextMenuExtenders();

		Extenders.RemoveAll([this](const FContentBrowserMenuExtender_SelectedAssets& E)
		{
			return E.GetHandle() == ContentBrowserExtenderHandle;
		});
	}

	LiveUncookedBPs.Empty();
}

// ---------------------------------------------------------------------------
// Content Browser menu extension
// ---------------------------------------------------------------------------

TSharedRef<FExtender> FBlueprintUncookerModule::ExtendContentBrowserMenu(
	const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	// Check if any selected asset is Blueprint-related
	bool bAnyBlueprint = false;
	for (const FAssetData& Asset : SelectedAssets)
	{
		const FString ClassPath = Asset.AssetClassPath.ToString();
		if (ClassPath.Contains(TEXT("Blueprint")) || ClassPath.EndsWith(TEXT("_C")))
		{
			bAnyBlueprint = true;
			break;
		}
		// Also check when the UObject is already loaded
		if (UObject* Obj = Asset.FastGetAsset(false))
		{
			if (Obj->IsA<UBlueprint>() || Obj->IsA<UBlueprintGeneratedClass>())
			{
				bAnyBlueprint = true;
				break;
			}
		}
	}

	if (!bAnyBlueprint)
	{
		return Extender;
	}

	Extender->AddMenuExtension(
		"GetAssetActions",
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateLambda([this, SelectedAssets](FMenuBuilder& MenuBuilder)
		{
			MenuBuilder.AddMenuEntry(
				FText::FromString(TEXT("Uncook Blueprint")),
				FText::FromString(TEXT("Reconstruct an editable Blueprint from cooked bytecode.")),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.Blueprint"),
				FUIAction(FExecuteAction::CreateRaw(
					this, &FBlueprintUncookerModule::ExecuteUncookBlueprint, SelectedAssets))
			);

			MenuBuilder.AddMenuEntry(
				FText::FromString(TEXT("Uncook as Child Class (PIE Test)")),
				FText::FromString(TEXT("Create a child Blueprint whose parent is the cooked class. Casts succeed via inheritance.")),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.Blueprint"),
				FUIAction(FExecuteAction::CreateRaw(
					this, &FBlueprintUncookerModule::ExecuteLiveUncook, SelectedAssets))
			);
		})
	);

	return Extender;
}

// ---------------------------------------------------------------------------
// BPGC resolution helper
// ---------------------------------------------------------------------------

UBlueprintGeneratedClass* FBlueprintUncookerModule::ResolveGeneratedClass(const FAssetData& Asset)
{
	UObject* Obj = Asset.GetAsset();
	if (!Obj) return nullptr;

	// Try direct cast
	if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(Obj))
	{
		return BPGC;
	}

	// Try via UBlueprint
	if (UBlueprint* BP = Cast<UBlueprint>(Obj))
	{
		if (UBlueprintGeneratedClass* BPGC =
			Cast<UBlueprintGeneratedClass>(BP->GeneratedClass))
		{
			return BPGC;
		}
		if (UBlueprintGeneratedClass* BPGC =
			Cast<UBlueprintGeneratedClass>(BP->SkeletonGeneratedClass))
		{
			return BPGC;
		}
	}

	// Try class reference stored with _C suffix
	if (UClass* AsClass = Cast<UClass>(Obj))
	{
		if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(AsClass))
		{
			return BPGC;
		}
	}

	return nullptr;
}

// ---------------------------------------------------------------------------
// Mode A: Standard uncook
// ---------------------------------------------------------------------------

void FBlueprintUncookerModule::ExecuteUncookBlueprint(TArray<FAssetData> SelectedAssets)
{
	FScopedSlowTask Progress(
		(float)SelectedAssets.Num(),
		FText::FromString(TEXT("Uncoooking Blueprints...")));
	Progress.MakeDialog(true);

	int32 Successes = 0;

	for (const FAssetData& Asset : SelectedAssets)
	{
		if (Progress.ShouldCancel()) break;
		Progress.EnterProgressFrame(1.f, FText::FromString(Asset.AssetName.ToString()));

		UBlueprintGeneratedClass* BPGC = ResolveGeneratedClass(Asset);
		if (!BPGC)
		{
			UE_LOG(LogBlueprintUncooker, Warning, TEXT("Could not resolve BPGC for %s"),
				*Asset.AssetName.ToString());
			continue;
		}

		// Determine output path
		FString OriginalPackagePath = Asset.PackagePath.ToString();
		FString OriginalName = Asset.AssetName.ToString();

		// Strip _C suffix if present
		if (OriginalName.EndsWith(TEXT("_C")))
		{
			OriginalName.LeftChopInline(2);
		}

		FString OutputPackagePath = OriginalPackagePath / TEXT("Uncooked") / OriginalName;

		// Clean up any prior version
		if (UPackage* OldPkg = FindPackage(nullptr, *OutputPackagePath))
		{
			TArray<UObject*> OldObjs;
			GetObjectsWithOuter(OldPkg, OldObjs);
			for (UObject* OldObj : OldObjs)
			{
				OldObj->MarkAsGarbage();
			}
			CollectGarbage(GARBAGE_COLLECTION_KEEPFLAGS);
		}

		// Create output package
		UPackage* NewPackage = CreatePackage(*OutputPackagePath);
		NewPackage->FullyLoad();

		// Phase 1: Decompile
		UE_LOG(LogBlueprintUncooker, Log, TEXT("Decompiling %s..."), *BPGC->GetName());
		TArray<FDecompiledFunction> Decompiled = FBytecodeReader::DecompileClass(BPGC);

		if (Decompiled.Num() == 0)
		{
			UE_LOG(LogBlueprintUncooker, Warning,
				TEXT("No functions decompiled from %s"), *BPGC->GetName());
		}

		// Phase 2: Build Blueprint
		// Widget Blueprints need their own builder (handles the widget tree /
		// Designer tab in addition to the event graph).
		UBlueprint* NewBP = nullptr;
		if (Cast<UWidgetBlueprintGeneratedClass>(BPGC) != nullptr)
		{
			UE_LOG(LogBlueprintUncooker, Log,
				TEXT("Detected Widget Blueprint — using BuildWidgetBlueprint() for %s"),
				*BPGC->GetName());
			NewBP = FGraphBuilder::BuildWidgetBlueprint(BPGC, NewPackage, OriginalName, Decompiled);
		}
		else
		{
			NewBP = FGraphBuilder::BuildBlueprint(BPGC, NewPackage, OriginalName, Decompiled);
		}

		if (!NewBP)
		{
			ShowNotification(
				FString::Printf(TEXT("Failed to build Blueprint for %s"), *OriginalName),
				false);
			continue;
		}

		// Phase 3: Compile
		FKismetEditorUtilities::CompileBlueprint(
			NewBP, EBlueprintCompileOptions::SkipGarbageCollection);

		// Phase 4: Copy CDO defaults
		// ── Why GetDefaultObject(true) + RF_NeedLoad preload is required ──────
		// Blueprint CDO serialization is DEFERRED by the linker (see
		// FLinkerLoad::CreateExport).  The CDO object may be non-null but still
		// carry RF_NeedLoad — its property data has NOT yet been read from disk.
		// All maps/arrays therefore appear empty until Linker->Preload(CDO) is
		// called.  GetDefaultObject(false) returns the unloaded shell silently;
		// GetDefaultObject(true) also does NOT force the load when the object
		// already exists.  We must call Preload() explicitly.
		//
		// ── Why IncludeSuper is required ─────────────────────────────────────
		// For blueprints whose interesting properties (e.g. TMap members) are
		// declared on a C++ *parent* class (not on the BPGC itself),
		// ExcludeSuper produces an empty iterator and nothing is ever copied.
		// IncludeSuper walks the full chain up to UObject.
		{
			UBlueprintGeneratedClass* NewGenClass =
				Cast<UBlueprintGeneratedClass>(NewBP->GeneratedClass);

			if (NewGenClass)
			{
				// Force-create CDOs (bCreateIfNeeded = true)
				UObject* OrigCDO = BPGC->GetDefaultObject(/*bCreateIfNeeded=*/true);
				UObject* NewCDO  = NewGenClass->GetDefaultObject(/*bCreateIfNeeded=*/true);

				// Force-preload the source CDO if its data is still pending
				if (OrigCDO && OrigCDO->HasAnyFlags(RF_NeedLoad))
				{
					UE_LOG(LogBlueprintUncooker, Log,
						TEXT("Phase 4: OrigCDO has RF_NeedLoad — force-preloading for '%s'"),
						*BPGC->GetName());
					if (FLinkerLoad* Linker = OrigCDO->GetLinker())
					{
						Linker->Preload(OrigCDO);
					}
					else
					{
						UE_LOG(LogBlueprintUncooker, Warning,
							TEXT("Phase 4: OrigCDO RF_NeedLoad but no linker for '%s' — map values may be empty"),
							*BPGC->GetName());
					}
				}

				UE_LOG(LogBlueprintUncooker, Log,
					TEXT("Phase 4: OrigCDO='%s' RF_NeedLoad=%d  NewCDO='%s'"),
					OrigCDO ? *OrigCDO->GetPathName() : TEXT("NULL"),
					OrigCDO ? (int32)OrigCDO->HasAnyFlags(RF_NeedLoad) : -1,
					NewCDO  ? *NewCDO->GetPathName()  : TEXT("NULL"));

				if (OrigCDO && NewCDO)
				{
					int32 PropsCopied = 0;

					// IncludeSuper: also walks properties declared on C++ parent classes
					for (TFieldIterator<FProperty> PropIt(BPGC, EFieldIteratorFlags::IncludeSuper);
						PropIt; ++PropIt)
					{
						FProperty* OrigProp = *PropIt;
						FProperty* NewProp  = NewGenClass->FindPropertyByName(OrigProp->GetFName());
						if (!NewProp) continue;

						// Skip component object properties — handled via SCS
						if (FObjectPropertyBase* ObjProp = CastField<FObjectPropertyBase>(OrigProp))
						{
							if (ObjProp->PropertyClass &&
								ObjProp->PropertyClass->IsChildOf(UActorComponent::StaticClass()))
							{
								continue;
							}
						}

						void* Src = OrigProp->ContainerPtrToValuePtr<void>(OrigCDO);
						void* Dst = NewProp->ContainerPtrToValuePtr<void>(NewCDO);

						// Log map sizes (key diagnostic for deferred-load issues)
						if (FMapProperty* MapProp = CastField<FMapProperty>(OrigProp))
						{
							FScriptMapHelper SrcMap(MapProp, Src);
							UE_LOG(LogBlueprintUncooker, Log,
								TEXT("Phase 4: Map '%s' — %d src entries"),
								*MapProp->GetName(), SrcMap.Num());
						}

						OrigProp->CopyCompleteValue(Dst, Src);
						++PropsCopied;
					}

					UE_LOG(LogBlueprintUncooker, Log,
						TEXT("Phase 4: CDO copy complete — %d propert(ies) copied for '%s'"),
						PropsCopied, *BPGC->GetName());
				}
				else
				{
					UE_LOG(LogBlueprintUncooker, Warning,
						TEXT("Phase 4: CDO copy skipped — OrigCDO=%s NewCDO=%s"),
						OrigCDO ? TEXT("valid") : TEXT("NULL"),
						NewCDO  ? TEXT("valid") : TEXT("NULL"));
				}
			}
		}

		// Phase 4b: DynamicBindingObjects + ComponentClassOverrides
		{
			UBlueprintGeneratedClass* NewGenClass =
				Cast<UBlueprintGeneratedClass>(NewBP->GeneratedClass);
			if (NewGenClass)
			{
				for (UDynamicBlueprintBinding* Binding : BPGC->DynamicBindingObjects)
				{
					if (!Binding) continue;
					UDynamicBlueprintBinding* NewBinding =
						DuplicateObject<UDynamicBlueprintBinding>(Binding, NewGenClass);
					if (NewBinding)
						NewGenClass->DynamicBindingObjects.Add(NewBinding);
				}
				NewGenClass->ComponentClassOverrides = BPGC->ComponentClassOverrides;
				UE_LOG(LogBlueprintUncooker, Log,
					TEXT("Phase 4b: copied %d DynamicBinding(s) + %d ClassOverride(s) for '%s'"),
					BPGC->DynamicBindingObjects.Num(),
					BPGC->ComponentClassOverrides.Num(),
					*BPGC->GetName());
			}
		}

		// Notify asset registry
		IAssetRegistry& AssetRegistry =
			FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
		AssetRegistry.AssetCreated(NewBP);

		// Save the package
		FString Filename;
		if (FPackageName::TryConvertLongPackageNameToFilename(
			OutputPackagePath, Filename, FPackageName::GetAssetPackageExtension()))
		{
			FSavePackageArgs SaveArgs;
			SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
			SaveArgs.Error = GError;
			SaveArgs.SaveFlags = SAVE_NoError;
			UPackage::SavePackage(NewPackage, NewBP, *Filename, SaveArgs);
		}

		// Dump for debugging
		FGraphValidator::DumpBlueprint(NewBP);

		UE_LOG(LogBlueprintUncooker, Log,
			TEXT("Successfully uncooked %s → %s"), *BPGC->GetName(), *OutputPackagePath);
		++Successes;
	}

	ShowNotification(
		FString::Printf(TEXT("Uncook complete: %d/%d succeeded"), Successes, SelectedAssets.Num()),
		Successes > 0);
}

// ---------------------------------------------------------------------------
// Mode B: Live / child-class uncook
// ---------------------------------------------------------------------------

void FBlueprintUncookerModule::ExecuteLiveUncook(TArray<FAssetData> SelectedAssets)
{
	for (const FAssetData& Asset : SelectedAssets)
	{
		UBlueprintGeneratedClass* BPGC = ResolveGeneratedClass(Asset);
		if (!BPGC) continue;

		FString OriginalPackagePath = Asset.PackagePath.ToString();
		FString OriginalName = Asset.AssetName.ToString();
		if (OriginalName.EndsWith(TEXT("_C"))) OriginalName.LeftChopInline(2);

		FString ChildName = OriginalName + TEXT("_Uncook");
		FString OutputPath = OriginalPackagePath / TEXT("Uncooked") / ChildName;

		UPackage* NewPackage = CreatePackage(*OutputPath);

		TArray<FDecompiledFunction> Decompiled = FBytecodeReader::DecompileClass(BPGC);

		UBlueprint* ChildBP = FGraphBuilder::BuildChildBlueprint(
			BPGC, NewPackage, ChildName, Decompiled);

		if (!ChildBP) continue;

		FKismetEditorUtilities::CompileBlueprint(
			ChildBP, EBlueprintCompileOptions::SkipGarbageCollection);

		LiveUncookedBPs.Add(ChildBP);

		IAssetRegistry& AssetRegistry =
			FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
		AssetRegistry.AssetCreated(ChildBP);

		UE_LOG(LogBlueprintUncooker, Log,
			TEXT("Live-uncooked child BP: %s. Set your GameMode to use this class, then PIE."),
			*ChildName);

		ShowNotification(
			FString::Printf(TEXT("Child class '%s' created. Set GameMode and PIE."), *ChildName),
			true);
	}
}

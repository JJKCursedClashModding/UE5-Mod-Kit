#include "BlueprintUncookerLibrary.h"

#include "BytecodeReader.h"
#include "GraphBuilder.h"
#include "GraphValidator.h"

#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Components/ActorComponent.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"       // UWidgetBlueprintGeneratedClass, IsA detection
#include "Extensions/WidgetBlueprintGeneratedClassExtension.h" // UWidgetBlueprintGeneratedClassExtension — for Extensions[] duplication

#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"

#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"

#include "Misc/PackageName.h"
#include "UObject/SavePackage.h"
#include "HAL/FileManager.h"
#include "UObject/LinkerLoad.h"          // FLinkerLoad::Preload — force-serialise deferred Blueprint CDOs
#include "Engine/DynamicBlueprintBinding.h"

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static UBlueprintGeneratedClass* ResolveClassFromPath(const FString& AssetPath)
{
	// Normalise: strip _C suffix to get the bare package/asset path
	FString Cleaned = AssetPath;
	if (Cleaned.EndsWith(TEXT("_C")))
	{
		Cleaned.LeftChopInline(2);
	}

	// The correct UObject path for the generated class is:
	//   /Game/Path/AssetName.AssetName_C
	// NOT /Game/Path/AssetName_C  (that's a package path, not object path)
	FString AssetName = FPackageName::GetLongPackageAssetName(Cleaned);
	FString ClassObjectPath = Cleaned + TEXT(".") + AssetName + TEXT("_C");

	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] ResolveClassFromPath: trying '%s'"), *ClassObjectPath);

	// ── 1. Force-load the package first (ALWAYS — avoids ghost/header-only objects) ──
	//   StaticFindObject alone can return a shell with no Children/functions if
	//   the class was only header-scanned by the asset registry at startup.
	//   LoadPackage tolerates broken imports; FullyLoad resolves deferred exports.
	FString PackageName = Cleaned; // already a package-name shaped string
	// Strip sub-object portion if present (e.g. /Game/Foo/Bar.SomeOuter)
	int32 DotIdx = INDEX_NONE;
	PackageName.FindChar(TEXT('.'), DotIdx);
	if (DotIdx != INDEX_NONE)
	{
		PackageName = PackageName.Left(DotIdx);
	}

	UPackage* Pkg = LoadPackage(nullptr, *PackageName, LOAD_None);
	if (Pkg)
	{
		// FullyLoad resolves any deferred-loaded exports (functions, properties)
		Pkg->FullyLoad();

		// After full load, find the BPGC by its correct object path
		if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(
			StaticFindObject(UBlueprintGeneratedClass::StaticClass(), nullptr, *ClassObjectPath)))
		{
			UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Found after LoadPackage+FullyLoad: %s"), *ClassObjectPath);
			return BPGC;
		}

		// Scan all top-level objects in the package for a BPGC
		TArray<UObject*> PkgObjs;
		GetObjectsWithOuter(Pkg, PkgObjs, /*bIncludeNestedObjects=*/false);
		for (UObject* Obj : PkgObjs)
		{
			if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(Obj))
			{
				UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Found by package scan after FullyLoad: %s"), *BPGC->GetPathName());
				return BPGC;
			}
		}

		// Also check UBlueprint objects in the package (editor / non-cooked assets)
		for (UObject* Obj : PkgObjs)
		{
			if (UBlueprint* BP = Cast<UBlueprint>(Obj))
			{
				if (UBlueprintGeneratedClass* BPGC =
					Cast<UBlueprintGeneratedClass>(BP->GeneratedClass))
				{
					UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Found via UBlueprint->GeneratedClass in package: %s"),
						*BPGC->GetPathName());
					return BPGC;
				}
			}
		}
	}

	// ── 2. StaticFindObject fallback (in case LoadPackage failed but it was in memory) ─
	if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(
		StaticFindObject(UBlueprintGeneratedClass::StaticClass(), nullptr, *ClassObjectPath)))
	{
		UE_LOG(LogTemp, Warning, TEXT("[BPUncooker] Found via StaticFindObject fallback (may be ghost-loaded, 0 funcs possible): %s"), *ClassObjectPath);
		return BPGC;
	}

	// ── 3. StaticLoadObject with correct dot-separated path ─────────────────
	if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(
		StaticLoadObject(UBlueprintGeneratedClass::StaticClass(), nullptr,
			*ClassObjectPath, nullptr, LOAD_NoWarn | LOAD_NoRedirects)))
	{
		UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Found via StaticLoadObject(BPGC): %s"), *ClassObjectPath);
		return BPGC;
	}

	// ── 4. Try as UBlueprint (non-cooked editor asset) ───────────────────────
	UBlueprint* BP = Cast<UBlueprint>(
		StaticLoadObject(UBlueprint::StaticClass(), nullptr,
			*Cleaned, nullptr, LOAD_NoWarn | LOAD_NoRedirects));
	if (BP)
	{
		if (UBlueprintGeneratedClass* BPGC =
			Cast<UBlueprintGeneratedClass>(BP->GeneratedClass))
		{
			UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Found via UBlueprint->GeneratedClass: %s"),
				*BPGC->GetPathName());
			return BPGC;
		}
		if (UBlueprintGeneratedClass* BPGC =
			Cast<UBlueprintGeneratedClass>(BP->SkeletonGeneratedClass))
		{
			UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Found via UBlueprint->SkeletonGeneratedClass: %s"),
				*BPGC->GetPathName());
			return BPGC;
		}
	}

	// ── 5. LoadClass fallback ────────────────────────────────────────────────
	if (UClass* Cls = LoadClass<UObject>(nullptr, *ClassObjectPath, nullptr, LOAD_NoWarn))
	{
		if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(Cls))
		{
			UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Found via LoadClass: %s"), *BPGC->GetPathName());
			return BPGC;
		}
	}

	UE_LOG(LogTemp, Warning,
		TEXT("[BPUncooker] ResolveClassFromPath: ALL methods failed for '%s' (tried class path '%s')"),
		*AssetPath, *ClassObjectPath);
	return nullptr;
}

// ---------------------------------------------------------------------------

FString UBlueprintUncookerLibrary::DeriveOutputPath(
	const FString& SourceAssetPath,
	const FString& UserOutputPath)
{
	if (!UserOutputPath.IsEmpty())
	{
		return UserOutputPath;
	}

	FString PackagePath = FPackageName::GetLongPackagePath(SourceAssetPath);
	FString AssetName   = FPackageName::GetLongPackageAssetName(SourceAssetPath);

	// Strip _C suffix from derived name
	if (AssetName.EndsWith(TEXT("_C")))
	{
		AssetName.LeftChopInline(2);
	}

	return PackagePath / TEXT("Uncooked") / AssetName;
}

// ---------------------------------------------------------------------------
// Core implementation
// ---------------------------------------------------------------------------

FString UBlueprintUncookerLibrary::UncookImpl(
	const FString& SourceAssetPath,
	const FString& OutputPath,
	bool bChildClass)
{
	// ── Step 1: Resolve source ──────────────────────────────────────────────
	UBlueprintGeneratedClass* BPGC = ResolveClassFromPath(SourceAssetPath);
	if (!BPGC)
	{
		return FString::Printf(
			TEXT("ERROR: Could not resolve UBlueprintGeneratedClass from '%s'"),
			*SourceAssetPath);
	}

	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Resolved class: %s"), *BPGC->GetPathName());

	// Cache a typed Widget Blueprint pointer early so we can use it in step 7b
	// (after compile) without re-casting every time.
	UWidgetBlueprintGeneratedClass* OrigWBPGC = Cast<UWidgetBlueprintGeneratedClass>(BPGC);

	// ── Step 2: Derive output path ──────────────────────────────────────────
	FString ResolvedOutput = DeriveOutputPath(SourceAssetPath, OutputPath);
	FString AssetName = FPackageName::GetLongPackageAssetName(ResolvedOutput);

	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Output path: %s"), *ResolvedOutput);

	// ── Step 3: Clean old package ───────────────────────────────────────────
	if (UPackage* OldPkg = FindPackage(nullptr, *ResolvedOutput))
	{
		TArray<UObject*> OldObjs;
		GetObjectsWithOuter(OldPkg, OldObjs);
		for (UObject* Obj : OldObjs) { Obj->MarkAsGarbage(); }
		CollectGarbage(GARBAGE_COLLECTION_KEEPFLAGS);
	}

	// ── Step 4: Create package ──────────────────────────────────────────────
	UPackage* NewPackage = CreatePackage(*ResolvedOutput);
	if (!NewPackage)
	{
		return FString::Printf(
			TEXT("ERROR: Failed to create package '%s'"), *ResolvedOutput);
	}
	NewPackage->FullyLoad();

	// ── Step 4b: Evict any surviving Blueprint from a previous run ──────────
	// FKismetEditorUtilities::CreateBlueprint asserts that no UBlueprint exists
	// at AssetName in the target package (Kismet2.cpp line 421).
	// Even after the GC in step 3, the old UBlueprint may still be alive if it
	// is referenced by the asset registry, an open editor window, or another
	// system.  Explicitly rename it to the transient package so the assertion
	// passes and the object is eligible for collection on the next GC cycle.
	{
		if (UBlueprint* ExistingBP = FindObject<UBlueprint>(NewPackage, *AssetName))
		{
			const FName TrashName = MakeUniqueObjectName(
				GetTransientPackage(), ExistingBP->GetClass(),
				FName(*(FString(TEXT("TRASHED_")) + AssetName)));

			ExistingBP->Rename(
				*TrashName.ToString(),
				GetTransientPackage(),
				REN_DontCreateRedirectors | REN_NonTransactional | REN_ForceNoResetLoaders);
			ExistingBP->MarkAsGarbage();

			UE_LOG(LogTemp, Log,
				TEXT("[BPUncooker] Evicted stale Blueprint '%s' → transient package (will be GC'd next cycle)"),
				*AssetName);
		}
	}

	// ── Step 5: Decompile ───────────────────────────────────────────────────
	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Decompiling bytecode..."));
	TArray<FDecompiledFunction> Decompiled = FBytecodeReader::DecompileClass(BPGC);
	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Decompiled %d functions."), Decompiled.Num());

	// ── Step 6: Build Blueprint ─────────────────────────────────────────────
	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Building Blueprint graph..."));
	UBlueprint* NewBP = nullptr;
	if (bChildClass)
	{
		NewBP = FGraphBuilder::BuildChildBlueprint(BPGC, NewPackage, AssetName, Decompiled);
	}
	else if (Cast<UWidgetBlueprintGeneratedClass>(BPGC) != nullptr)
	{
		// Widget Blueprint: reconstruct EventGraph + Designer tab widget tree
		UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Detected Widget Blueprint — using BuildWidgetBlueprint()"));
		NewBP = FGraphBuilder::BuildWidgetBlueprint(BPGC, NewPackage, AssetName, Decompiled);
	}
	else
	{
		NewBP = FGraphBuilder::BuildBlueprint(BPGC, NewPackage, AssetName, Decompiled);
	}

	if (!NewBP)
	{
		return FString::Printf(
			TEXT("ERROR: FGraphBuilder returned null for '%s'"), *SourceAssetPath);
	}

	// ── Step 7: Compile ─────────────────────────────────────────────────────
	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Compiling Blueprint..."));
	FKismetEditorUtilities::CompileBlueprint(
		NewBP, EBlueprintCompileOptions::SkipGarbageCollection);

	// Check for errors
	TArray<FString> CompileErrors;
	for (const FBPVariableDescription& Var : NewBP->NewVariables)
	{
		(void)Var; // iterate to force lazy resolution
	}

	bool bHasErrors = false;
	for (UEdGraph* Graph : NewBP->UbergraphPages)
	{
		if (!Graph) continue;
		for (UEdGraphNode* Node : Graph->Nodes)
		{
			if (!Node) continue;
			if (Node->bHasCompilerMessage &&
				Node->ErrorType <= EMessageSeverity::Error)
			{
				CompileErrors.Add(FString::Printf(TEXT("  Node '%s': %s"),
					*Node->GetNodeTitle(ENodeTitleType::FullTitle).ToString(),
					*Node->NodeComment));
				bHasErrors = true;
			}
		}
	}

	// ── Step 7b: Duplicate WBPGC-level extensions (Widget Blueprint only) ──
	// UWidgetBlueprintGeneratedClassExtension sub-objects (e.g. UMVVMBlueprintView
	// for UMG View Model bindings) live on the WBPGC, not on the UWidgetBlueprint
	// or its CDO.  The generic CDO property copy in step 8 never touches them.
	// After CompileBlueprint the new WBPGC may already have freshly-created
	// extension objects from compiler extension plugins (e.g. FMVVMWidgetBlueprintExtension).
	// We clear those and replace them with deep copies of the originals so that
	// UPROPERTY data (view model field paths, binding descriptors, etc.) is preserved.
	// UWidgetBlueprintGeneratedClass::Extensions is declared private in UE5.1.
	// Use the public GetExtensions() getter (returns const TArray<>&) for reading,
	// AddExtension() for writing, and reflection (FArrayProperty) to clear the
	// destination array before repopulating.
	// UWidgetBlueprintGeneratedClass::Extensions is private in UE5.1.
	// Public API available:
	//   GetExtensions(TSubclassOf<...>) — returns filtered array (requires a type arg)
	//   ForEachExtension(Predicate)     — iterates all extensions (no type filter)
	//   No public Add or Clear methods exist.
	// Strategy:
	//   - Check for extensions via ForEachExtension (lambda sets a bool flag).
	//   - Iterate source extensions via ForEachExtension to collect into a local TArray.
	//   - Use FArrayProperty reflection to clear and repopulate the destination array.
	if (!bChildClass && OrigWBPGC)
	{
		// Collect all extensions from the source WBPGC using the public ForEachExtension.
		TArray<UWidgetBlueprintGeneratedClassExtension*> SrcExtensions;
		OrigWBPGC->ForEachExtension(
			[&SrcExtensions](UWidgetBlueprintGeneratedClassExtension* Ext)
			{
				if (Ext) SrcExtensions.Add(Ext);
			});

		if (SrcExtensions.Num() > 0)
		{
			if (UWidgetBlueprintGeneratedClass* NewWBPGC =
				Cast<UWidgetBlueprintGeneratedClass>(NewBP->GeneratedClass))
			{
				// Access the private Extensions array on both src and dst via reflection.
				// FindFProperty works regardless of C++ access level.
				FArrayProperty* DstArrayProp = FindFProperty<FArrayProperty>(
					NewWBPGC->GetClass(), FName(TEXT("Extensions")));

				if (DstArrayProp)
				{
					FObjectProperty* ElemProp =
						CastField<FObjectProperty>(DstArrayProp->Inner);
					void* DstPtr = DstArrayProp->ContainerPtrToValuePtr<void>(NewWBPGC);
					FScriptArrayHelper DstHelper(DstArrayProp, DstPtr);

					// Clear any compiler-generated extensions to avoid duplicates.
					DstHelper.EmptyValues();

					int32 DuplicatedCount = 0;
					for (UWidgetBlueprintGeneratedClassExtension* Ext : SrcExtensions)
					{
						UWidgetBlueprintGeneratedClassExtension* NewExt =
							DuplicateObject<UWidgetBlueprintGeneratedClassExtension>(
								Ext, NewWBPGC);
						if (NewExt && ElemProp)
						{
							int32 NewIdx = DstHelper.AddValue();
							ElemProp->SetObjectPropertyValue(
								DstHelper.GetRawPtr(NewIdx), NewExt);
							++DuplicatedCount;
						}
					}

					UE_LOG(LogTemp, Log,
						TEXT("[BPUncooker] Extensions: duplicated %d extension(s) for '%s'"),
						DuplicatedCount, *BPGC->GetName());
				}
				else
				{
					UE_LOG(LogTemp, Warning,
						TEXT("[BPUncooker] Extensions: could not find 'Extensions' FArrayProperty on '%s' — skipping"),
						*NewWBPGC->GetName());
				}
			}
		}
	}

	// ── Step 8: CDO copy ────────────────────────────────────────────────────
	// Blueprint CDO serialization is DEFERRED by the linker (see
	// FLinkerLoad::CreateExport).  The CDO object may exist (non-null) but
	// still carry RF_NeedLoad, meaning its property data has NOT yet been
	// read from disk — all maps/arrays will appear empty until we explicitly
	// call Linker->Preload(CDO).  This is also why creating a *child* of the
	// cooked BPGC works: UE's CreateDefaultObject walks the parent chain and
	// calls Preload as part of archetype setup, triggering the real load.
	if (!bChildClass)
	{
		if (UBlueprintGeneratedClass* NewGenClass =
			Cast<UBlueprintGeneratedClass>(NewBP->GeneratedClass))
		{
			// ── 8a. Obtain the source CDO ────────────────────────────────
			UObject* OrigCDO = BPGC->GetDefaultObject(/*bCreateIfNeeded=*/true);

			// ── 8b. Force-preload if the CDO is still pending serialization ─
			if (OrigCDO && OrigCDO->HasAnyFlags(RF_NeedLoad))
			{
				UE_LOG(LogTemp, Log,
					TEXT("[BPUncooker] OrigCDO has RF_NeedLoad — force-preloading via linker for '%s'"),
					*BPGC->GetName());
				if (FLinkerLoad* Linker = OrigCDO->GetLinker())
				{
					Linker->Preload(OrigCDO);
				}
				else
				{
					// No linker (already in memory but not deserialized) — try
					// forcing via the class regeneration path.
					UE_LOG(LogTemp, Warning,
						TEXT("[BPUncooker] OrigCDO has RF_NeedLoad but no linker for '%s' — CDO values may be missing"),
						*BPGC->GetName());
				}
			}

			// ── 8c. Log RF_NeedLoad state for diagnosis ──────────────────
			UE_LOG(LogTemp, Log,
				TEXT("[BPUncooker] OrigCDO='%s' RF_NeedLoad=%d RF_WasLoaded=%d"),
				OrigCDO ? *OrigCDO->GetPathName() : TEXT("NULL"),
				OrigCDO ? (int32)OrigCDO->HasAnyFlags(RF_NeedLoad) : -1,
				OrigCDO ? (int32)OrigCDO->HasAnyFlags(RF_WasLoaded) : -1);

			// ── 8d. Obtain the destination CDO ───────────────────────────
			UObject* NewCDO = NewGenClass->GetDefaultObject(/*bCreateIfNeeded=*/true);

			if (!OrigCDO)
			{
				UE_LOG(LogTemp, Warning,
					TEXT("[BPUncooker] CDO copy skipped — OrigCDO is null for '%s'"),
					*BPGC->GetPathName());
			}
			else if (!NewCDO)
			{
				UE_LOG(LogTemp, Warning,
					TEXT("[BPUncooker] CDO copy skipped — NewCDO is null for '%s'"),
					*NewGenClass->GetPathName());
			}
			else
			{
				// ── 8e. Copy properties, logging map/array sizes ──────────
				int32 PropsCopied = 0;
				for (TFieldIterator<FProperty> PropIt(BPGC, EFieldIteratorFlags::IncludeSuper);
					PropIt; ++PropIt)
				{
					FProperty* OrigProp = *PropIt;
					FProperty* NewProp  = NewGenClass->FindPropertyByName(OrigProp->GetFName());
					if (!NewProp) continue;

					// Skip ActorComponent object refs (handled by SCS)
					if (FObjectPropertyBase* ObjProp = CastField<FObjectPropertyBase>(OrigProp))
					{
						if (ObjProp->PropertyClass &&
							ObjProp->PropertyClass->IsChildOf(UActorComponent::StaticClass()))
						{
							continue;
						}
						// NOTE: UWidget* properties are NOT skipped here.
						// UUserWidget::NamedSlotBindings (TArray<FNamedSlotBinding>) contains
						// UWidget* Content pointers that are sub-objects of the CDO itself
						// (not of the UWidgetTree which was separately duplicated in step 6).
						// CopyCompleteValue on the struct array correctly deep-copies these
						// instanced sub-objects into the new CDO.  Adding a blanket UWidget*
						// skip here would lose named-slot data.
					}

					void* Src = OrigProp->ContainerPtrToValuePtr<void>(OrigCDO);
					void* Dst = NewProp->ContainerPtrToValuePtr<void>(NewCDO);

					// Diagnostic: log container sizes before copy
					if (FMapProperty* MapProp = CastField<FMapProperty>(OrigProp))
					{
						FScriptMapHelper SrcMap(MapProp, Src);
						UE_LOG(LogTemp, Log,
							TEXT("[BPUncooker] Map '%s': %d src entries (pre-copy)"),
							*MapProp->GetName(), SrcMap.Num());
					}
					else if (FArrayProperty* ArrProp = CastField<FArrayProperty>(OrigProp))
					{
						FScriptArrayHelper SrcArr(ArrProp, Src);
						if (SrcArr.Num() > 0)
						{
							UE_LOG(LogTemp, Log,
								TEXT("[BPUncooker] Array '%s': %d src entries (pre-copy)"),
								*ArrProp->GetName(), SrcArr.Num());
						}
					}

					// Bug 6 fix: for instanced sub-object properties DuplicateObject instead of
					// raw pointer copy, otherwise the new CDO holds a cross-package pointer into
					// the original cooked package → "Object not found in package" on save.
					if (FObjectProperty* InstProp = CastField<FObjectProperty>(OrigProp))
					{
						if (InstProp->HasAnyPropertyFlags(CPF_InstancedReference))
						{
							UObject* SrcObj = InstProp->GetObjectPropertyValue(Src);
							UObject* DupObj = SrcObj ? DuplicateObject(SrcObj, NewCDO) : nullptr;
							InstProp->SetObjectPropertyValue(Dst, DupObj);
							++PropsCopied;
							continue;
						}
					}

					OrigProp->CopyCompleteValue(Dst, Src);
					++PropsCopied;
				}

				// ── 8f. Verify destination map sizes after copy ───────────
				for (TFieldIterator<FProperty> PropIt(NewGenClass, EFieldIteratorFlags::IncludeSuper);
					PropIt; ++PropIt)
				{
					if (FMapProperty* MapProp = CastField<FMapProperty>(*PropIt))
					{
						void* DstPtr = MapProp->ContainerPtrToValuePtr<void>(NewCDO);
						FScriptMapHelper DstMap(MapProp, DstPtr);
						UE_LOG(LogTemp, Log,
							TEXT("[BPUncooker] Map '%s': %d dst entries (post-copy)"),
							*MapProp->GetName(), DstMap.Num());
					}
					else if (FArrayProperty* ArrProp = CastField<FArrayProperty>(*PropIt))
					{
						void* DstPtr = ArrProp->ContainerPtrToValuePtr<void>(NewCDO);
						FScriptArrayHelper DstArr(ArrProp, DstPtr);
						if (DstArr.Num() > 0)
						{
							UE_LOG(LogTemp, Log,
								TEXT("[BPUncooker] Array '%s': %d dst entries (post-copy)"),
								*ArrProp->GetName(), DstArr.Num());
						}
					}
				}

				UE_LOG(LogTemp, Log,
					TEXT("[BPUncooker] CDO copy complete — %d propert(ies) copied for '%s'"),
					PropsCopied, *BPGC->GetName());
			}
		}
	}

	// ── Step 8b: DynamicBindingObjects ─────────────────────────────────────
	// Runtime delegate bindings (overlaps, input, component events) survive cooking.
	// Duplicate each binding sub-object into the new BPGC so they fire at runtime.
	if (!bChildClass)
	{
		if (UBlueprintGeneratedClass* NewBPGC =
			Cast<UBlueprintGeneratedClass>(NewBP->GeneratedClass))
		{
			for (UDynamicBlueprintBinding* Binding : BPGC->DynamicBindingObjects)
			{
				if (!Binding) continue;
				UDynamicBlueprintBinding* NewBinding =
					DuplicateObject<UDynamicBlueprintBinding>(Binding, NewBPGC);
				if (NewBinding)
					NewBPGC->DynamicBindingObjects.Add(NewBinding);
			}
			UE_LOG(LogTemp, Log,
				TEXT("[BPUncooker] DynamicBindingObjects: copied %d binding(s) for '%s'"),
				BPGC->DynamicBindingObjects.Num(), *BPGC->GetName());

			// ── Step 8c: ComponentClassOverrides ─────────────────────────
			NewBPGC->ComponentClassOverrides = BPGC->ComponentClassOverrides;
			UE_LOG(LogTemp, Log,
				TEXT("[BPUncooker] ComponentClassOverrides: copied %d override(s) for '%s'"),
				BPGC->ComponentClassOverrides.Num(), *BPGC->GetName());
		}
	}

	// ── Step 9: Notify asset registry ──────────────────────────────────────
	IAssetRegistry& AssetRegistry =
		FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
	AssetRegistry.AssetCreated(NewBP);

	// ── Step 10: Save ───────────────────────────────────────────────────────
	FString Filename;
	bool bSaved = false;
	if (FPackageName::TryConvertLongPackageNameToFilename(
		ResolvedOutput, Filename, FPackageName::GetAssetPackageExtension()))
	{
		FSavePackageArgs SaveArgs;
		SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
		SaveArgs.Error         = GError;
		SaveArgs.SaveFlags     = SAVE_NoError;
		// UPackage::SavePackage returns bool in UE5.1
		bSaved = UPackage::SavePackage(NewPackage, NewBP, *Filename, SaveArgs);
	}

	// ── Step 11: Dump ───────────────────────────────────────────────────────
	FGraphValidator::DumpBlueprint(NewBP);

	// ── Step 12: Build result string ────────────────────────────────────────
	FString StatusLine = FString::Printf(
		TEXT("%s | Functions:%d | Saved:%s"),
		bHasErrors ? TEXT("PARTIAL") : TEXT("OK"),
		Decompiled.Num(),
		bSaved ? TEXT("YES") : TEXT("NO"));

	if (CompileErrors.Num() > 0)
	{
		StatusLine += TEXT("\nCompile errors:\n");
		StatusLine += FString::Join(CompileErrors, TEXT("\n"));
	}

	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Result: %s"), *StatusLine);
	return StatusLine;
}

// ---------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------

FString UBlueprintUncookerLibrary::UncookBlueprintAsset(
	const FString& SourceAssetPath,
	const FString& OutputPath)
{
	return UncookImpl(SourceAssetPath, OutputPath, false);
}

FString UBlueprintUncookerLibrary::UncookBlueprintAsChildClass(
	const FString& SourceAssetPath,
	const FString& OutputPath)
{
	return UncookImpl(SourceAssetPath, OutputPath, true);
}

FString UBlueprintUncookerLibrary::UncookAllBlueprintsInDirectory(
	const FString& ContentDir,
	const FString& OutputParentDir)
{
	IAssetRegistry& AssetRegistry =
		FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

	FARFilter Filter;
	Filter.PackagePaths.Add(FName(*ContentDir));
	Filter.ClassPaths.Add(UBlueprint::StaticClass()->GetClassPathName());
	Filter.ClassPaths.Add(UBlueprintGeneratedClass::StaticClass()->GetClassPathName());
	Filter.bRecursivePaths      = false;
	Filter.bRecursiveClasses    = true;

	TArray<FAssetData> Assets;
	AssetRegistry.GetAssets(Filter, Assets);

	if (Assets.Num() == 0)
	{
		return FString::Printf(TEXT("No Blueprint assets found in '%s'."), *ContentDir);
	}

	int32 Succeeded = 0;
	int32 Total     = Assets.Num();

	for (const FAssetData& Asset : Assets)
	{
		FString AssetPath = Asset.GetSoftObjectPath().ToString();

		FString DerivedOutput;
		if (!OutputParentDir.IsEmpty())
		{
			FString Name = Asset.AssetName.ToString();
			if (Name.EndsWith(TEXT("_C"))) Name.LeftChopInline(2);
			DerivedOutput = OutputParentDir / TEXT("Uncooked") / Name;
		}

		FString Result = UncookImpl(AssetPath, DerivedOutput, false);
		if (!Result.StartsWith(TEXT("ERROR")))
		{
			++Succeeded;
		}

		UE_LOG(LogTemp, Log, TEXT("[BPUncooker] %s → %s"), *AssetPath, *Result);
	}

	return FString::Printf(
		TEXT("Uncook complete: %d/%d succeeded in '%s'."),
		Succeeded, Total, *ContentDir);
}

// =============================================================================
// UncookExternalBlueprint
// Load a cooked .uasset from an absolute filesystem path (outside the project)
// via a temporary UE package mount point, then uncook it normally.
// =============================================================================
FString UBlueprintUncookerLibrary::UncookExternalBlueprint(
	const FString& AbsoluteAssetPath,
	const FString& OutputPackagePath,
	const FString& MountPointName,
	const FString& ExternalContentDir)
{
	// ── 1. Normalize the source path ────────────────────────────────────────
	FString NormalizedPath = FPaths::ConvertRelativePathToFull(AbsoluteAssetPath);
	FPaths::NormalizeFilename(NormalizedPath);

	// ── 2. Find (or derive) the Content root ────────────────────────────────
	// The content root is the directory that maps to the mount point root.
	// When ExternalContentDir is provided use it directly; otherwise walk up
	// the directory hierarchy looking for an ancestor named "Content".
	FString ContentRoot = ExternalContentDir;
	FPaths::NormalizeFilename(ContentRoot);

	if (ContentRoot.IsEmpty())
	{
		FString Dir = FPaths::GetPath(NormalizedPath);
		while (!Dir.IsEmpty())
		{
			if (FPaths::GetBaseFilename(Dir).Equals(TEXT("Content"), ESearchCase::IgnoreCase))
			{
				ContentRoot = Dir;
				break;
			}
			FString Parent = FPaths::GetPath(Dir);
			if (Parent == Dir) break; // reached filesystem root
			Dir = Parent;
		}
	}

	if (ContentRoot.IsEmpty())
	{
		return FString::Printf(
			TEXT("ERROR: Cannot find a 'Content' directory ancestor in path '%s'. "
			     "Pass ExternalContentDir explicitly."),
			*AbsoluteAssetPath);
	}

	// Ensure trailing slash for RegisterMountPoint
	if (!ContentRoot.EndsWith(TEXT("/"))) ContentRoot += TEXT("/");

	// ── 3. Build effective mount point name ─────────────────────────────────
	FString Mount = MountPointName.IsEmpty() ? TEXT("/ExternalCooked/") : MountPointName;
	if (!Mount.StartsWith(TEXT("/"))) Mount = TEXT("/") + Mount;
	if (!Mount.EndsWith(TEXT("/")))   Mount += TEXT("/");

	// ── 4. Register mount point → derive package name ────────────────────────
	FPackageName::RegisterMountPoint(Mount, ContentRoot);

	FString PackageName;
	const bool bConverted = FPackageName::TryConvertFilenameToLongPackageName(
		NormalizedPath, PackageName);

	if (!bConverted)
	{
		FPackageName::UnRegisterMountPoint(Mount, ContentRoot);
		return FString::Printf(
			TEXT("ERROR: TryConvertFilenameToLongPackageName failed. "
			     "Path='%s' ContentRoot='%s' Mount='%s'"),
			*NormalizedPath, *ContentRoot, *Mount);
	}

	UE_LOG(LogTemp, Log,
		TEXT("[BPUncooker] UncookExternalBlueprint: '%s' → pkg '%s' → out '%s'"),
		*FPaths::GetCleanFilename(AbsoluteAssetPath), *PackageName, *OutputPackagePath);

	// ── 5. Uncook via the shared implementation ──────────────────────────────
	// UncookImpl calls LoadPackage(nullptr, *PackageName, LOAD_None) internally.
	// Because the mount point is registered, the package manager resolves
	// PackageName to the filesystem path under ContentRoot.
	FString Result = UncookImpl(PackageName, OutputPackagePath, /*bChildClass=*/false);

	// ── 6. Unregister mount point ────────────────────────────────────────────
	FPackageName::UnRegisterMountPoint(Mount, ContentRoot);

	return Result;
}

// =============================================================================
// UncookExternalFolder
// Walk an external cooked Content/ directory and uncook every Blueprint that
// matches the JJK CC naming patterns (ABP_*, BP_*, WBP_*, *_BP, *_ABP).
// =============================================================================
FString UBlueprintUncookerLibrary::UncookExternalFolder(
	const FString& ExternalContentDir,
	const FString& OutputBase,
	const FString& MountPointName,
	bool bDryRun)
{
	// ── Blueprint filename filter (mirrors BLUEPRINT_PATTERN in uncook_batch.py) ──
	auto IsBlueprintAsset = [](const FString& Filename) -> bool
	{
		static const TCHAR* Prefixes[] = { TEXT("ABP_"), TEXT("BP_"), TEXT("WBP_"), nullptr };
		static const TCHAR* Suffixes[] = { TEXT("_BP"), TEXT("_ABP"), nullptr };
		for (int32 i = 0; Prefixes[i]; ++i)
			if (Filename.StartsWith(Prefixes[i])) return true;
		const FString Base = FPaths::GetBaseFilename(Filename);
		for (int32 i = 0; Suffixes[i]; ++i)
			if (Base.EndsWith(Suffixes[i])) return true;
		return false;
	};

	// ── Normalise root dir ───────────────────────────────────────────────────
	FString RootDir = ExternalContentDir;
	FPaths::NormalizeFilename(RootDir);
	if (!RootDir.EndsWith(TEXT("/"))) RootDir += TEXT("/");

	// ── Recursive file discovery ─────────────────────────────────────────────
	TArray<FString> AllFiles;
	IFileManager::Get().FindFilesRecursive(
		AllFiles, *RootDir, TEXT("*.uasset"), /*Files=*/true, /*Dirs=*/false);
	AllFiles.Sort();

	TArray<FString> Blueprints;
	for (const FString& F : AllFiles)
		if (IsBlueprintAsset(FPaths::GetCleanFilename(F)))
			Blueprints.Add(F);

	const int32 Total = Blueprints.Num();
	UE_LOG(LogTemp, Log,
		TEXT("[BPUncooker] UncookExternalFolder: %d blueprint(s) found in '%s' (DryRun=%s)"),
		Total, *ExternalContentDir, bDryRun ? TEXT("true") : TEXT("false"));

	if (Total == 0)
		return TEXT("0/0 succeeded. No blueprint assets matched the naming filter.");

	const FString EffBase = OutputBase.IsEmpty() ? TEXT("/Game/Uncooked") : OutputBase.TrimEnd();

	int32 Succeeded = 0;
	int32 Failed    = 0;

	for (const FString& AssetPath : Blueprints)
	{
		// Build output package path preserving relative structure
		FString RelPath = AssetPath;
		FPaths::NormalizeFilename(RelPath);
		FPaths::MakePathRelativeTo(RelPath, *RootDir);
		RelPath.ReplaceInline(TEXT("\\"), TEXT("/"));
		FString RelNoExt = FPaths::ChangeExtension(RelPath, TEXT(""));
		FString OutputPkg = EffBase / RelNoExt;
		OutputPkg.ReplaceInline(TEXT("\\"), TEXT("/"));

		if (bDryRun)
		{
			UE_LOG(LogTemp, Log, TEXT("  [DRY] %s  →  %s"),
				*FPaths::GetCleanFilename(AssetPath), *OutputPkg);
			++Succeeded;
			continue;
		}

		const FString R = UncookExternalBlueprint(
			AssetPath, OutputPkg, MountPointName, ExternalContentDir);

		if (R.StartsWith(TEXT("ERROR")))
		{
			++Failed;
			UE_LOG(LogTemp, Warning, TEXT("[BPUncooker] FAIL  %s — %s"),
				*FPaths::GetCleanFilename(AssetPath), *R);
		}
		else
		{
			++Succeeded;
			UE_LOG(LogTemp, Log, TEXT("[BPUncooker] OK    %s"),
				*FPaths::GetCleanFilename(AssetPath));
		}
	}

	return FString::Printf(TEXT("%d/%d succeeded."), Succeeded, Total);
}

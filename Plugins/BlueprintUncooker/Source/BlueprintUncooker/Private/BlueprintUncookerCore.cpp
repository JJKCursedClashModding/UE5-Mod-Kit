#include "BlueprintUncookerCore.h"

#include "AssetRegistry/AssetData.h"

#include "BytecodeReader.h"
#include "GraphBuilder.h"
#include "GraphValidator.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Engine/DynamicBlueprintBinding.h"
#include "Components/ActorComponent.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"
#include "Extensions/WidgetBlueprintGeneratedClassExtension.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Widget.h"
#include "WidgetBlueprint.h"

#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"

#include "Misc/PackageName.h"
#include "UObject/SavePackage.h"
#include "UObject/LinkerLoad.h"

DEFINE_LOG_CATEGORY(LogBlueprintUncooker);

// ---------------------------------------------------------------------------
// ResolveClassFromPath
// ---------------------------------------------------------------------------

UBlueprintGeneratedClass* FBlueprintUncookerCore::ResolveClassFromPath(const FString& AssetPath)
{
	FString Cleaned = AssetPath;
	if (Cleaned.EndsWith(TEXT("_C")))
	{
		Cleaned.LeftChopInline(2);
	}

	FString AssetName = FPackageName::GetLongPackageAssetName(Cleaned);
	FString ClassObjectPath = Cleaned + TEXT(".") + AssetName + TEXT("_C");

	UE_LOG(LogBlueprintUncooker, Log, TEXT("ResolveClassFromPath: trying '%s'"), *ClassObjectPath);

	FString PackageName = Cleaned;
	int32 DotIdx = INDEX_NONE;
	PackageName.FindChar(TEXT('.'), DotIdx);
	if (DotIdx != INDEX_NONE)
	{
		PackageName = PackageName.Left(DotIdx);
	}

	if (UPackage* Pkg = LoadPackage(nullptr, *PackageName, LOAD_None))
	{
		Pkg->FullyLoad();

		if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(
			StaticFindObject(UBlueprintGeneratedClass::StaticClass(), nullptr, *ClassObjectPath)))
		{
			UE_LOG(LogBlueprintUncooker, Log, TEXT("Found after LoadPackage+FullyLoad: %s"), *ClassObjectPath);
			return BPGC;
		}

		TArray<UObject*> PkgObjs;
		GetObjectsWithOuter(Pkg, PkgObjs, /*bIncludeNestedObjects=*/false);
		for (UObject* Obj : PkgObjs)
		{
			if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(Obj))
			{
				UE_LOG(LogBlueprintUncooker, Log, TEXT("Found by package scan after FullyLoad: %s"), *BPGC->GetPathName());
				return BPGC;
			}
		}

		for (UObject* Obj : PkgObjs)
		{
			if (UBlueprint* BP = Cast<UBlueprint>(Obj))
			{
				if (UBlueprintGeneratedClass* BPGC =
					Cast<UBlueprintGeneratedClass>(BP->GeneratedClass))
				{
					UE_LOG(LogBlueprintUncooker, Log, TEXT("Found via UBlueprint->GeneratedClass in package: %s"),
						*BPGC->GetPathName());
					return BPGC;
				}
			}
		}
	}

	if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(
		StaticFindObject(UBlueprintGeneratedClass::StaticClass(), nullptr, *ClassObjectPath)))
	{
		UE_LOG(LogBlueprintUncooker, Warning,
			TEXT("Found via StaticFindObject fallback (may be ghost-loaded, 0 funcs possible): %s"),
			*ClassObjectPath);
		return BPGC;
	}

	if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(
		StaticLoadObject(UBlueprintGeneratedClass::StaticClass(), nullptr,
			*ClassObjectPath, nullptr, LOAD_NoWarn | LOAD_NoRedirects)))
	{
		UE_LOG(LogBlueprintUncooker, Log, TEXT("Found via StaticLoadObject(BPGC): %s"), *ClassObjectPath);
		return BPGC;
	}

	if (UBlueprint* BP = Cast<UBlueprint>(
		StaticLoadObject(UBlueprint::StaticClass(), nullptr,
			*Cleaned, nullptr, LOAD_NoWarn | LOAD_NoRedirects)))
	{
		if (UBlueprintGeneratedClass* BPGC =
			Cast<UBlueprintGeneratedClass>(BP->GeneratedClass))
		{
			UE_LOG(LogBlueprintUncooker, Log, TEXT("Found via UBlueprint->GeneratedClass: %s"),
				*BPGC->GetPathName());
			return BPGC;
		}
		if (UBlueprintGeneratedClass* BPGC =
			Cast<UBlueprintGeneratedClass>(BP->SkeletonGeneratedClass))
		{
			UE_LOG(LogBlueprintUncooker, Log, TEXT("Found via UBlueprint->SkeletonGeneratedClass: %s"),
				*BPGC->GetPathName());
			return BPGC;
		}
	}

	if (UClass* Cls = LoadClass<UObject>(nullptr, *ClassObjectPath, nullptr, LOAD_NoWarn))
	{
		if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(Cls))
		{
			UE_LOG(LogBlueprintUncooker, Log, TEXT("Found via LoadClass: %s"), *BPGC->GetPathName());
			return BPGC;
		}
	}

	UE_LOG(LogBlueprintUncooker, Warning,
		TEXT("ResolveClassFromPath: ALL methods failed for '%s' (tried class path '%s')"),
		*AssetPath, *ClassObjectPath);
	return nullptr;
}

// ---------------------------------------------------------------------------
// DeriveOutputPath
// ---------------------------------------------------------------------------

FString FBlueprintUncookerCore::DeriveOutputPath(
	const FString& SourceAssetPath,
	const FString& UserOutputPath)
{
	if (!UserOutputPath.IsEmpty())
	{
		return UserOutputPath;
	}

	FString PackagePath = FPackageName::GetLongPackagePath(SourceAssetPath);
	FString AssetName   = FPackageName::GetLongPackageAssetName(SourceAssetPath);

	if (AssetName.EndsWith(TEXT("_C")))
	{
		AssetName.LeftChopInline(2);
	}

	return PackagePath / TEXT("Uncooked") / AssetName;
}

// ---------------------------------------------------------------------------
// SourcePathFromAssetData
// ---------------------------------------------------------------------------

FString FBlueprintUncookerCore::SourcePathFromAssetData(const FAssetData& Asset)
{
	FString AssetName = Asset.AssetName.ToString();
	if (AssetName.EndsWith(TEXT("_C")))
	{
		AssetName.LeftChopInline(2);
	}
	return Asset.PackagePath.ToString() / AssetName;
}

// ---------------------------------------------------------------------------
// FormatStatusString
// ---------------------------------------------------------------------------

FString FBlueprintUncookerCore::FormatStatusString(const FBlueprintUncookResult& Result)
{
	if (Result.StartsWithError())
	{
		return Result.Message;
	}

	return Result.Message;
}

// ---------------------------------------------------------------------------
// Uncook
// ---------------------------------------------------------------------------

FBlueprintUncookResult FBlueprintUncookerCore::Uncook(
	const FString& SourceAssetPath,
	const FString& OutputPath,
	bool bChildClass)
{
	FBlueprintUncookResult Result;

	UBlueprintGeneratedClass* BPGC = ResolveClassFromPath(SourceAssetPath);
	if (!BPGC)
	{
		Result.Message = FString::Printf(
			TEXT("ERROR: Could not resolve UBlueprintGeneratedClass from '%s'"),
			*SourceAssetPath);
		return Result;
	}

	UE_LOG(LogBlueprintUncooker, Log, TEXT("Resolved class: %s"), *BPGC->GetPathName());

	UWidgetBlueprintGeneratedClass* OrigWBPGC = Cast<UWidgetBlueprintGeneratedClass>(BPGC);

	FString ResolvedOutput = DeriveOutputPath(SourceAssetPath, OutputPath);
	FString AssetName = FPackageName::GetLongPackageAssetName(ResolvedOutput);

	UE_LOG(LogBlueprintUncooker, Log, TEXT("Output path: %s"), *ResolvedOutput);

	if (UPackage* OldPkg = FindPackage(nullptr, *ResolvedOutput))
	{
		TArray<UObject*> OldObjs;
		GetObjectsWithOuter(OldPkg, OldObjs);
		for (UObject* Obj : OldObjs) { Obj->MarkAsGarbage(); }
		CollectGarbage(GARBAGE_COLLECTION_KEEPFLAGS);
	}

	UPackage* NewPackage = CreatePackage(*ResolvedOutput);
	if (!NewPackage)
	{
		Result.Message = FString::Printf(
			TEXT("ERROR: Failed to create package '%s'"), *ResolvedOutput);
		return Result;
	}
	NewPackage->FullyLoad();

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

		UE_LOG(LogBlueprintUncooker, Log,
			TEXT("Evicted stale Blueprint '%s' → transient package (will be GC'd next cycle)"),
			*AssetName);
	}

	UE_LOG(LogBlueprintUncooker, Log, TEXT("Decompiling bytecode..."));
	TArray<FDecompiledFunction> Decompiled = FBytecodeReader::DecompileClass(BPGC);
	Result.FunctionCount = Decompiled.Num();
	UE_LOG(LogBlueprintUncooker, Log, TEXT("Decompiled %d functions."), Decompiled.Num());

	UE_LOG(LogBlueprintUncooker, Log, TEXT("Building Blueprint graph..."));
	UBlueprint* NewBP = nullptr;
	if (bChildClass)
	{
		NewBP = FGraphBuilder::BuildChildBlueprint(BPGC, NewPackage, AssetName, Decompiled);
	}
	else if (Cast<UWidgetBlueprintGeneratedClass>(BPGC) != nullptr)
	{
		UE_LOG(LogBlueprintUncooker, Log, TEXT("Detected Widget Blueprint — using BuildWidgetBlueprint()"));
		NewBP = FGraphBuilder::BuildWidgetBlueprint(BPGC, NewPackage, AssetName, Decompiled);
	}
	else
	{
		NewBP = FGraphBuilder::BuildBlueprint(BPGC, NewPackage, AssetName, Decompiled);
	}

	if (!NewBP)
	{
		Result.Message = FString::Printf(
			TEXT("ERROR: FGraphBuilder returned null for '%s'"), *SourceAssetPath);
		return Result;
	}

	Result.CreatedBlueprint = NewBP;

	UE_LOG(LogBlueprintUncooker, Log, TEXT("Compiling Blueprint..."));
	FKismetEditorUtilities::CompileBlueprint(
		NewBP, EBlueprintCompileOptions::SkipGarbageCollection);

	if (UWidgetBlueprint* NewWBP = Cast<UWidgetBlueprint>(NewBP))
	{
		FGraphBuilder::RebindWidgetPropertiesFromTree(NewWBP);
	}

	TArray<FString> CompileErrors;
	for (const FBPVariableDescription& Var : NewBP->NewVariables)
	{
		(void)Var;
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

	if (!bChildClass && OrigWBPGC)
	{
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
				FArrayProperty* DstArrayProp = FindFProperty<FArrayProperty>(
					NewWBPGC->GetClass(), FName(TEXT("Extensions")));

				if (DstArrayProp)
				{
					FObjectProperty* ElemProp =
						CastField<FObjectProperty>(DstArrayProp->Inner);
					void* DstPtr = DstArrayProp->ContainerPtrToValuePtr<void>(NewWBPGC);
					FScriptArrayHelper DstHelper(DstArrayProp, DstPtr);
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

					UE_LOG(LogBlueprintUncooker, Log,
						TEXT("Extensions: duplicated %d extension(s) for '%s'"),
						DuplicatedCount, *BPGC->GetName());
				}
				else
				{
					UE_LOG(LogBlueprintUncooker, Warning,
						TEXT("Extensions: could not find 'Extensions' FArrayProperty on '%s' — skipping"),
						*NewWBPGC->GetName());
				}
			}
		}
	}

	if (!bChildClass)
	{
		if (UBlueprintGeneratedClass* NewGenClass =
			Cast<UBlueprintGeneratedClass>(NewBP->GeneratedClass))
		{
			FString CDOExportName = FString::Printf(TEXT("Default__%s"), *BPGC->GetName());
			UObject* OrigCDO = FindObject<UObject>(BPGC->GetOutermost(), *CDOExportName);
			if (!OrigCDO)
			{
				OrigCDO = BPGC->GetDefaultObject(/*bCreateIfNeeded=*/true);
			}

			if (OrigCDO && OrigCDO->HasAnyFlags(RF_NeedLoad))
			{
				UE_LOG(LogBlueprintUncooker, Log,
					TEXT("OrigCDO has RF_NeedLoad — force-preloading via linker for '%s'"),
					*BPGC->GetName());

				FLinkerLoad* Linker = OrigCDO->GetLinker();
				if (!Linker)
				{
					Linker = FLinkerLoad::FindExistingLinkerForPackage(BPGC->GetOutermost());
					if (Linker)
					{
						UE_LOG(LogBlueprintUncooker, Log,
							TEXT("Per-object linker was null; using package linker for '%s'"),
							*BPGC->GetName());
					}
				}

				if (Linker)
				{
					Linker->Preload(OrigCDO);
				}
				else
				{
					UE_LOG(LogBlueprintUncooker, Warning,
						TEXT("OrigCDO has RF_NeedLoad but no linker found for '%s' — CDO values may be missing"),
						*BPGC->GetName());
				}
			}

			if (OrigCDO)
			{
				OrigCDO->ConditionalPostLoad();
			}

			UE_LOG(LogBlueprintUncooker, Log,
				TEXT("OrigCDO='%s' RF_NeedLoad=%d RF_WasLoaded=%d"),
				OrigCDO ? *OrigCDO->GetPathName() : TEXT("NULL"),
				OrigCDO ? (int32)OrigCDO->HasAnyFlags(RF_NeedLoad) : -1,
				OrigCDO ? (int32)OrigCDO->HasAnyFlags(RF_WasLoaded) : -1);

			UObject* NewCDO = NewGenClass->GetDefaultObject(/*bCreateIfNeeded=*/true);

			if (!OrigCDO)
			{
				UE_LOG(LogBlueprintUncooker, Warning,
					TEXT("CDO copy skipped — OrigCDO is null for '%s'"),
					*BPGC->GetPathName());
			}
			else if (!NewCDO)
			{
				UE_LOG(LogBlueprintUncooker, Warning,
					TEXT("CDO copy skipped — NewCDO is null for '%s'"),
					*NewGenClass->GetPathName());
			}
			else
			{
				int32 PropsCopied = 0;
				for (TFieldIterator<FProperty> PropIt(BPGC, EFieldIteratorFlags::IncludeSuper);
					PropIt; ++PropIt)
				{
					FProperty* OrigProp = *PropIt;
					FProperty* NewProp  = NewGenClass->FindPropertyByName(OrigProp->GetFName());
					if (!NewProp) continue;

					if (FObjectPropertyBase* ObjProp = CastField<FObjectPropertyBase>(OrigProp))
					{
						if (ObjProp->PropertyClass &&
							ObjProp->PropertyClass->IsChildOf(UActorComponent::StaticClass()))
						{
							continue;
						}

						if (OrigWBPGC && ObjProp->PropertyClass &&
							(ObjProp->PropertyClass->IsChildOf(UWidget::StaticClass()) ||
							 ObjProp->PropertyClass->IsChildOf(UWidgetAnimation::StaticClass())))
						{
							continue;
						}
					}

					void* Src = OrigProp->ContainerPtrToValuePtr<void>(OrigCDO);
					void* Dst = NewProp->ContainerPtrToValuePtr<void>(NewCDO);

					if (FMapProperty* MapProp = CastField<FMapProperty>(OrigProp))
					{
						FScriptMapHelper SrcMap(MapProp, Src);
						UE_LOG(LogBlueprintUncooker, Log,
							TEXT("Map '%s': %d src entries (pre-copy)"),
							*MapProp->GetName(), SrcMap.Num());
					}
					else if (FArrayProperty* ArrProp = CastField<FArrayProperty>(OrigProp))
					{
						FScriptArrayHelper SrcArr(ArrProp, Src);
						if (SrcArr.Num() > 0)
						{
							UE_LOG(LogBlueprintUncooker, Log,
								TEXT("Array '%s': %d src entries (pre-copy)"),
								*ArrProp->GetName(), SrcArr.Num());
						}
					}

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

				for (TFieldIterator<FProperty> PropIt(NewGenClass, EFieldIteratorFlags::IncludeSuper);
					PropIt; ++PropIt)
				{
					if (FMapProperty* MapProp = CastField<FMapProperty>(*PropIt))
					{
						void* DstPtr = MapProp->ContainerPtrToValuePtr<void>(NewCDO);
						FScriptMapHelper DstMap(MapProp, DstPtr);
						UE_LOG(LogBlueprintUncooker, Log,
							TEXT("Map '%s': %d dst entries (post-copy)"),
							*MapProp->GetName(), DstMap.Num());
					}
					else if (FArrayProperty* ArrProp = CastField<FArrayProperty>(*PropIt))
					{
						void* DstPtr = ArrProp->ContainerPtrToValuePtr<void>(NewCDO);
						FScriptArrayHelper DstArr(ArrProp, DstPtr);
						if (DstArr.Num() > 0)
						{
							UE_LOG(LogBlueprintUncooker, Log,
								TEXT("Array '%s': %d dst entries (post-copy)"),
								*ArrProp->GetName(), DstArr.Num());
						}
					}
				}

				UE_LOG(LogBlueprintUncooker, Log,
					TEXT("CDO copy complete — %d propert(ies) copied for '%s'"),
					PropsCopied, *BPGC->GetName());
			}
		}
	}

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
			UE_LOG(LogBlueprintUncooker, Log,
				TEXT("DynamicBindingObjects: copied %d binding(s) for '%s'"),
				BPGC->DynamicBindingObjects.Num(), *BPGC->GetName());

			NewBPGC->ComponentClassOverrides = BPGC->ComponentClassOverrides;
			UE_LOG(LogBlueprintUncooker, Log,
				TEXT("ComponentClassOverrides: copied %d override(s) for '%s'"),
				BPGC->ComponentClassOverrides.Num(), *BPGC->GetName());
		}
	}

	IAssetRegistry& AssetRegistry =
		FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
	AssetRegistry.AssetCreated(NewBP);

	FString Filename;
	Result.bSaved = false;
	if (FPackageName::TryConvertLongPackageNameToFilename(
		ResolvedOutput, Filename, FPackageName::GetAssetPackageExtension()))
	{
		FSavePackageArgs SaveArgs;
		SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
		SaveArgs.Error         = GError;
		SaveArgs.SaveFlags     = SAVE_NoError;
		Result.bSaved = UPackage::SavePackage(NewPackage, NewBP, *Filename, SaveArgs);
	}

	FGraphValidator::DumpBlueprint(NewBP);

	Result.bPartial = bHasErrors;
	Result.bSuccess = !Result.StartsWithError();
	Result.Message = FString::Printf(
		TEXT("%s | Functions:%d | Saved:%s"),
		bHasErrors ? TEXT("PARTIAL") : TEXT("OK"),
		Decompiled.Num(),
		Result.bSaved ? TEXT("YES") : TEXT("NO"));

	if (CompileErrors.Num() > 0)
	{
		Result.Message += TEXT("\nCompile errors:\n");
		Result.Message += FString::Join(CompileErrors, TEXT("\n"));
	}

	UE_LOG(LogBlueprintUncooker, Log, TEXT("Result: %s"), *Result.Message);
	return Result;
}

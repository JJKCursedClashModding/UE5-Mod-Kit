#include "BindWidgetHeaderPatcher.h"

#include "BlueprintUncookerCore.h"

#include "WidgetBlueprint.h"
#include "Blueprint/WidgetTree.h"
#include "Blueprint/UserWidget.h"
#include "Components/Widget.h"

#include "UObject/UnrealType.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

/** Strip the U prefix: UGameFooWidget -> GameFooWidget (matches decompiled filenames). */
static FString StrippedClassName(const FString& WithPrefix)
{
	if (WithPrefix.StartsWith(TEXT("U")))
	{
		return WithPrefix.RightChop(1);
	}
	return WithPrefix;
}

/** Find the matching ')' for the '(' at OpenIdx. Returns INDEX_NONE on failure. */
static int32 FindMatchingParen(const FString& S, int32 OpenIdx)
{
	if (OpenIdx < 0 || OpenIdx >= S.Len() || S[OpenIdx] != TCHAR('('))
	{
		return INDEX_NONE;
	}
	int32 Depth = 0;
	for (int32 i = OpenIdx; i < S.Len(); ++i)
	{
		if (S[i] == TCHAR('(')) ++Depth;
		else if (S[i] == TCHAR(')'))
		{
			--Depth;
			if (Depth == 0) return i;
		}
	}
	return INDEX_NONE;
}

static bool HasBindWidgetMeta(FProperty* Prop)
{
	return Prop
		&& (Prop->HasMetaData(TEXT("BindWidget"))
			|| Prop->HasMetaData(TEXT("BindWidgetOptional")));
}

/**
 * Locate the defining header for a native project class.
 * Strategy:
 *   1. Fast path: a file named <Stripped>.h that references <Stripped>.generated.h
 *      (decompiled headers always include their own .generated.h).
 *   2. Fallback: any project header containing "<Stripped>.generated.h".
 *   3. Last resort: header containing "class ... <ClassName>" + GENERATED_BODY.
 * Returns absolute path or empty string (engine/external class).
 */
static FString FindHeaderForClass(const FString& ClassName)
{
	static TMap<FString, FString> Cache;
	if (const FString* Cached = Cache.Find(ClassName))
	{
		return *Cached;
	}

	const FString SourceDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir() + TEXT("Source/"));
	TArray<FString> AllHeaders;
	IFileManager::Get().FindFilesRecursive(AllHeaders, *SourceDir, TEXT("*.h"), /*Files=*/true, /*Dirs=*/false);

	if (AllHeaders.Num() == 0)
	{
		Cache.Add(ClassName, FString());
		return FString();
	}

	const FString Stripped = StrippedClassName(ClassName);
	const FString FileName = Stripped + TEXT(".h");
	const FString GeneratedInclude = Stripped + TEXT(".generated.h");

	// 1. Fast path: filename match + generated include check.
	for (const FString& H : AllHeaders)
	{
		if (!H.EndsWith(FileName, ESearchCase::CaseSensitive))
		{
			continue;
		}
		FString Content;
		if (!FFileHelper::LoadFileToString(Content, *H))
		{
			continue;
		}
		if (Content.Find(GeneratedInclude, ESearchCase::CaseSensitive) != INDEX_NONE
			&& Content.Find(ClassName, ESearchCase::CaseSensitive) != INDEX_NONE)
		{
			Cache.Add(ClassName, H);
			return H;
		}
	}

	// 2. Any header referencing its .generated.h.
	for (const FString& H : AllHeaders)
	{
		// Skip the fast-path misses cheaply: read only if filename didn't match.
		FString Content;
		if (!FFileHelper::LoadFileToString(Content, *H))
		{
			continue;
		}
		if (Content.Find(GeneratedInclude, ESearchCase::CaseSensitive) != INDEX_NONE)
		{
			Cache.Add(ClassName, H);
			return H;
		}
	}

	// 3. class <ClassName> + GENERATED_BODY heuristic.
	for (const FString& H : AllHeaders)
	{
		FString Content;
		if (!FFileHelper::LoadFileToString(Content, *H))
		{
			continue;
		}
		const int32 ClassIdx = Content.Find(ClassName, ESearchCase::CaseSensitive);
		if (ClassIdx == INDEX_NONE)
		{
			continue;
		}
		// Must look like a definition ("class ... ClassName"), not a forward decl.
		const int32 WindowStart = FMath::Max(0, ClassIdx - 256);
		const FString Window = Content.Mid(WindowStart, ClassIdx - WindowStart);
		if (Window.Find(TEXT("class"), ESearchCase::CaseSensitive, ESearchDir::FromEnd) == INDEX_NONE)
		{
			continue;
		}
		if (Content.Find(TEXT("GENERATED_BODY"), ESearchCase::CaseSensitive) == INDEX_NONE)
		{
			continue;
		}
		Cache.Add(ClassName, H);
		return H;
	}

	Cache.Add(ClassName, FString());
	return FString();
}

/**
 * Insert meta=(BindWidget) for one property declaration in file text.
 */
enum class EPatchOutcome : uint8
{
	Patched,        // text modified — rebuild required
	AlreadyPresent, // UPROPERTY already carries BindWidget/BindWidgetOptional
	NoMatch         // declaration or UPROPERTY block not found
};

static EPatchOutcome PatchOneProperty(FString& Content, const FName& PropName)
{
	const FString Token = PropName.ToString() + TEXT(";");

	// Find a plausible declaration occurrence: "<Token>" on a line containing '*'
	// (all BindWidget candidates are UWidget* pointers).
	int32 SearchFrom = 0;
	int32 DeclIdx = INDEX_NONE;
	while (true)
	{
		const int32 Found = Content.Find(Token, ESearchCase::CaseSensitive, ESearchDir::FromStart, SearchFrom);
		if (Found == INDEX_NONE)
		{
			break;
		}
		// Extract the enclosing line.
		int32 LineStart = Found;
		while (LineStart > 0 && Content[LineStart - 1] != TCHAR('\n')) --LineStart;
		int32 LineEnd = Found + Token.Len();
		while (LineEnd < Content.Len() && Content[LineEnd] != TCHAR('\n')) ++LineEnd;
		const FString Line = Content.Mid(LineStart, LineEnd - LineStart);
		if (Line.Find(TEXT("*")) != INDEX_NONE && Line.Find(PropName.ToString(), ESearchCase::CaseSensitive) != INDEX_NONE)
		{
			DeclIdx = Found;
			break;
		}
		SearchFrom = Found + Token.Len();
	}

	if (DeclIdx == INDEX_NONE)
	{
		return EPatchOutcome::NoMatch;
	}

	// Nearest UPROPERTY before the declaration.
	const int32 UpIdx = Content.Find(TEXT("UPROPERTY"), ESearchCase::CaseSensitive, ESearchDir::FromEnd, DeclIdx);
	if (UpIdx == INDEX_NONE || UpIdx > DeclIdx)
	{
		return EPatchOutcome::NoMatch;
	}

	const int32 ParenOpen = Content.Find(TEXT("("), ESearchCase::CaseSensitive, ESearchDir::FromStart, UpIdx);
	if (ParenOpen == INDEX_NONE || ParenOpen > DeclIdx)
	{
		return EPatchOutcome::NoMatch;
	}
	const int32 ParenClose = FindMatchingParen(Content, ParenOpen);
	if (ParenClose == INDEX_NONE || ParenClose > DeclIdx)
	{
		return EPatchOutcome::NoMatch;
	}

	FString Inner = Content.Mid(ParenOpen + 1, ParenClose - ParenOpen - 1);
	if (Inner.Find(TEXT("BindWidget"), ESearchCase::CaseSensitive) != INDEX_NONE)
	{
		return EPatchOutcome::AlreadyPresent; // already bound (BindWidget or BindWidgetOptional)
	}

	if (Inner.Find(TEXT("meta=("), ESearchCase::CaseSensitive) != INDEX_NONE)
	{
		const int32 MetaIdx = Content.Find(TEXT("meta=("), ESearchCase::CaseSensitive, ESearchDir::FromStart, ParenOpen);
		if (MetaIdx == INDEX_NONE || MetaIdx > ParenClose)
		{
			return EPatchOutcome::NoMatch;
		}
		const int32 MetaOpen = Content.Find(TEXT("("), ESearchCase::CaseSensitive, ESearchDir::FromStart, MetaIdx);
		const int32 MetaClose = FindMatchingParen(Content, MetaOpen);
		if (MetaClose == INDEX_NONE || MetaClose > ParenClose)
		{
			return EPatchOutcome::NoMatch;
		}
		Content.InsertAt(MetaClose, TEXT(", BindWidget"));
		return EPatchOutcome::Patched;
	}

	// No meta=(...) yet.
	if (Inner.TrimStartAndEnd().IsEmpty())
	{
		Content.InsertAt(ParenClose, TEXT("meta=(BindWidget)"));
	}
	else
	{
		Content.InsertAt(ParenClose, TEXT(", meta=(BindWidget)"));
	}
	return EPatchOutcome::Patched;
}

// ---------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------

TArray<FString> FBindWidgetHeaderPatcher::FindMissingBindWidgetProperties(
	UClass* ParentClass,
	const TSet<FName>& TreeWidgetNames)
{
	TArray<FString> Out;
	if (!ParentClass || TreeWidgetNames.Num() == 0)
	{
		return Out;
	}

	for (UClass* C = ParentClass; C; C = C->GetSuperClass())
	{
		if (C == UUserWidget::StaticClass()
			|| C == UWidget::StaticClass()
			|| C == UObject::StaticClass())
		{
			break;
		}
		if (!C->IsNative())
		{
			continue;
		}
		for (TFieldIterator<FObjectProperty> PropIt(C, EFieldIteratorFlags::ExcludeSuper); PropIt; ++PropIt)
		{
			FObjectProperty* Prop = *PropIt;
			if (!Prop || !Prop->PropertyClass) continue;
			if (!Prop->PropertyClass->IsChildOf(UWidget::StaticClass())) continue;
			if (!TreeWidgetNames.Contains(Prop->GetFName())) continue;
			if (HasBindWidgetMeta(Prop)) continue;
			Out.Add(FString::Printf(TEXT("%s::%s"), *C->GetName(), *Prop->GetName()));
		}
	}
	return Out;
}

TArray<FString> FBindWidgetHeaderPatcher::FindMissingBindWidgetPropertiesFromTree(
	UClass* ParentClass,
	UWidgetTree* Tree)
{
	TArray<FString> Empty;
	if (!ParentClass || !Tree)
	{
		return Empty;
	}
	TSet<FName> Names;
	Tree->ForEachWidget([&Names](UWidget* W)
	{
		if (W && W->bIsVariable)
		{
			Names.Add(W->GetFName());
		}
	});
	if (Names.Num() == 0)
	{
		return Empty;
	}
	return FindMissingBindWidgetProperties(ParentClass, Names);
}

FBindWidgetPatchResult FBindWidgetHeaderPatcher::EnsureBindWidget(
	UClass* ParentClass,
	const TSet<FName>& TreeWidgetNames)
{
	FBindWidgetPatchResult Result;
	if (!ParentClass || TreeWidgetNames.Num() == 0)
	{
		return Result;
	}

	// Collect per-class property lists. Stamp transient metadata immediately so
	// the current editor session compiles even before a rebuild.
	TMap<UClass*, TArray<FName>> ByClass;
	for (UClass* C = ParentClass; C; C = C->GetSuperClass())
	{
		if (C == UUserWidget::StaticClass()
			|| C == UWidget::StaticClass()
			|| C == UObject::StaticClass())
		{
			break;
		}
		if (!C->IsNative())
		{
			continue;
		}
		for (TFieldIterator<FObjectProperty> PropIt(C, EFieldIteratorFlags::ExcludeSuper); PropIt; ++PropIt)
		{
			FObjectProperty* Prop = *PropIt;
			if (!Prop || !Prop->PropertyClass) continue;
			if (!Prop->PropertyClass->IsChildOf(UWidget::StaticClass())) continue;
			if (!TreeWidgetNames.Contains(Prop->GetFName())) continue;
			if (HasBindWidgetMeta(Prop)) continue;

			Prop->SetMetaData(TEXT("BindWidget"), TEXT(""));
			++Result.StampedTransient;
			ByClass.FindOrAdd(C).Add(Prop->GetFName());
			UE_LOG(LogBlueprintUncooker, Log,
				TEXT("[BPUncooker] Auto-stamped BindWidget on '%s::%s' (transient)"),
				*C->GetName(), *Prop->GetName());
		}
	}

	// Durable on-disk patch per header.
	for (auto& KV : ByClass)
	{
		UClass* C = KV.Key;
		const FString HeaderPath = FindHeaderForClass(C->GetName());
		if (HeaderPath.IsEmpty())
		{
			for (const FName& P : KV.Value)
			{
				++Result.Unpatchable;
				Result.Messages.Add(FString::Printf(
					TEXT("UNPATCHABLE %s::%s — no project header found (engine/external class?) — rebuild will NOT fix this"),
					*C->GetName(), *P.ToString()));
			}
			UE_LOG(LogBlueprintUncooker, Warning,
				TEXT("[BPUncooker] BindWidget header patch skipped for '%s' — header not found under <Project>/Source"),
				*C->GetName());
			continue;
		}

		FString Content;
		if (!FFileHelper::LoadFileToString(Content, *HeaderPath))
		{
			Result.Unpatchable += KV.Value.Num();
			Result.Messages.Add(FString::Printf(TEXT("ERROR: cannot read %s"), *HeaderPath));
			continue;
		}

		const FString Before = Content;
		int32 PatchedInFile = 0;
		for (const FName& P : KV.Value)
		{
			switch (PatchOneProperty(Content, P))
			{
			case EPatchOutcome::Patched:
				++PatchedInFile;
				++Result.PropertiesNeedingRebuild;
				Result.Messages.Add(FString::Printf(TEXT("PATCHED %s::%s → %s"),
					*C->GetName(), *P.ToString(), *HeaderPath));
				UE_LOG(LogBlueprintUncooker, Log,
					TEXT("[BPUncooker] Patched BindWidget for '%s::%s' in %s"),
					*C->GetName(), *P.ToString(), *HeaderPath);
				break;
			case EPatchOutcome::AlreadyPresent:
				// Header fixed in an earlier run, but the loaded binaries are
				// stale (no rebuild since). The transient stamp above keeps this
				// session compiling; the cook MUST still wait for a rebuild.
				++Result.AlreadyOnDisk;
				Result.Messages.Add(FString::Printf(TEXT("STALE %s::%s — header already patched, binaries predate it (rebuild still required)"),
					*C->GetName(), *P.ToString()));
				break;
			case EPatchOutcome::NoMatch:
			default:
				++Result.Unpatchable;
				Result.Messages.Add(FString::Printf(TEXT("UNPATCHABLE %s::%s — declaration/UPROPERTY not matched in %s (patch manually)"),
					*C->GetName(), *P.ToString(), *HeaderPath));
				UE_LOG(LogBlueprintUncooker, Warning,
					TEXT("[BPUncooker] Could not match UPROPERTY for '%s::%s' in %s — patch manually"),
					*C->GetName(), *P.ToString(), *HeaderPath);
				break;
			}
		}

		if (PatchedInFile > 0 && Content != Before)
		{
			if (FFileHelper::SaveStringToFile(Content, *HeaderPath))
			{
				++Result.HeadersPatched;
				Result.PatchedFiles.AddUnique(HeaderPath);
			}
			else
			{
				Result.Messages.Add(FString::Printf(TEXT("ERROR: cannot write %s"), *HeaderPath));
				UE_LOG(LogBlueprintUncooker, Error,
					TEXT("[BPUncooker] Failed to write patched header %s"), *HeaderPath);
			}
		}
	}

	if (Result.HeadersPatched > 0 || Result.AlreadyOnDisk > 0)
	{
		UE_LOG(LogBlueprintUncooker, Warning,
			TEXT("[BPUncooker] BindWidget headers changed (%d patched, %d already on disk with stale binaries) — YOU MUST REBUILD (build.ps1 or Ctrl+Alt+F11) before recooking, or the cook will still use old binaries and produce the same Serial size mismatch."),
			Result.HeadersPatched, Result.AlreadyOnDisk);
	}

	return Result;
}

FBindWidgetPatchResult FBindWidgetHeaderPatcher::EnsureBindWidgetFromTree(
	UClass* ParentClass,
	UWidgetTree* Tree)
{
	FBindWidgetPatchResult Empty;
	if (!ParentClass || !Tree)
	{
		return Empty;
	}
	// Only bIsVariable widgets make the WBP compiler create BPGC properties, so
	// only they can collide with same-named C++ properties. Structural widgets
	// (panels, spacers, non-variable decoration) are deliberately ignored —
	// stamping them would demand BindWidget where stock headers correctly omit it.
	TSet<FName> Names;
	Tree->ForEachWidget([&Names](UWidget* W)
	{
		if (W && W->bIsVariable)
		{
			Names.Add(W->GetFName());
		}
	});
	if (Names.Num() == 0)
	{
		return Empty;
	}
	return EnsureBindWidget(ParentClass, Names);
}

FBindWidgetPatchResult FBindWidgetHeaderPatcher::EnsureBindWidgetForBlueprint(UWidgetBlueprint* WBP)
{
	FBindWidgetPatchResult Empty;
	if (!WBP || !WBP->ParentClass || !WBP->WidgetTree)
	{
		return Empty;
	}
	return EnsureBindWidgetFromTree(WBP->ParentClass, WBP->WidgetTree);
}

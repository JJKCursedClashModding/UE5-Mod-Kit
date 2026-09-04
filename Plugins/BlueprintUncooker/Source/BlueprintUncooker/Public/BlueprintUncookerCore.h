#pragma once

#include "CoreMinimal.h"

class UBlueprint;
class UBlueprintGeneratedClass;

DECLARE_LOG_CATEGORY_EXTERN(LogBlueprintUncooker, Log, All);

/** Result of a single uncook operation. */
struct FBlueprintUncookResult
{
	bool bSuccess = false;
	bool bPartial = false;
	bool bSaved = false;
	int32 FunctionCount = 0;
	FString Message;
	UBlueprint* CreatedBlueprint = nullptr;

	bool StartsWithError() const { return Message.StartsWith(TEXT("ERROR")); }
};

/**
 * Shared uncook pipeline used by BlueprintUncookerLibrary (Python/API) and
 * BlueprintUncookerModule (Content Browser menu).  All entry points must call
 * into this class — do not duplicate uncook logic elsewhere.
 */
class BLUEPRINTUNCOOKER_API FBlueprintUncookerCore
{
public:
	/** Resolve a cooked UBlueprintGeneratedClass from a content-browser path. */
	static UBlueprintGeneratedClass* ResolveClassFromPath(const FString& AssetPath);

	/** Derive /Game/.../Uncooked/AssetName when UserOutputPath is empty. */
	static FString DeriveOutputPath(
		const FString& SourceAssetPath,
		const FString& UserOutputPath);

	/**
	 * Decompile, reconstruct, compile, copy defaults, and save one blueprint.
	 *
	 * @param SourceAssetPath  Package path, e.g. "/Game/Widgets/WBP_Foo" or ".../WBP_Foo_C"
	 * @param OutputPath       Destination package path (empty → auto-derived)
	 * @param bChildClass      If true, parent the new BP on the cooked BPGC
	 */
	static FBlueprintUncookResult Uncook(
		const FString& SourceAssetPath,
		const FString& OutputPath,
		bool bChildClass);

	/** Format a result struct as the legacy status string returned to Python. */
	static FString FormatStatusString(const FBlueprintUncookResult& Result);

	/** Build a source package path from a Content Browser asset selection. */
	static FString SourcePathFromAssetData(const struct FAssetData& Asset);
};

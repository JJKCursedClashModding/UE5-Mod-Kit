#pragma once

#include "CoreMinimal.h"

class UClass;
class UWidgetBlueprint;
class UWidgetTree;

/** Result of the persistent BindWidget repair pass. */
struct FBindWidgetPatchResult
{
	/** In-memory stamps applied this run (immediate editor compile fix). */
	int32 StampedTransient = 0;
	/** .h files rewritten on disk (durable cook fix — requires rebuild). */
	int32 HeadersPatched = 0;
	/** Distinct C++ properties whose headers were rewritten. */
	int32 PropertiesNeedingRebuild = 0;
	/** Properties whose headers already carry BindWidget on disk, but the
	 *  loaded binaries are stale (no rebuild since the patch). Cook MUST NOT
	 *  run — it would use the stale binaries and emit a corrupt package. */
	int32 AlreadyOnDisk = 0;
	/** Properties that need BindWidget but whose header cannot be patched
	 *  (engine/external class, header not found, declaration not matched).
	 *  A rebuild will NOT fix these — warn, don't block. */
	int32 Unpatchable = 0;
	/** Absolute header paths rewritten. */
	TArray<FString> PatchedFiles;
	/** Human-readable per-property notes (Class::Property → file). */
	TArray<FString> Messages;
};

/**
 * Persistent BindWidget repair.
 *
 * Background: Widget Blueprints whose C++ parent declares Instanced UWidget*
 * properties WITHOUT meta=(BindWidget) fail to recompile after uncooking:
 *   "Tried to create a property X … but another object already exists"
 * The cook still saves a package (NumPackagesSaved=1 with 2 errors), and the
 * game then dies at load with:
 *   "WidgetTree.TopWidget: Serial size mismatch: Expected 10, Actual 7"
 *
 * FGraphBuilder already applies a transient in-memory SetMetaData("BindWidget")
 * stamp so the *current* editor session compiles. That stamp is lost when the
 * cook runs in a fresh UnrealEditor-Cmd.exe process — hence the corrupt pak.
 *
 * This helper does BOTH:
 *   1. Transient stamp (same as before — immediate compile works).
 *   2. Durable on-disk patch of the project's Source headers to add
 *      meta=(BindWidget), so rebuilt editor binaries carry the metadata into
 *      the cook. Only native project classes with a header under
 *      <ProjectDir>/Source are touched; engine classes are skipped.
 *
 * After HeadersPatched > 0 the user MUST rebuild (build.ps1 or Ctrl+Alt+F11)
 * before recooking, otherwise the cook still uses the old binaries.
 */
class BLUEPRINTUNCOOKER_API FBindWidgetHeaderPatcher
{
public:
	/** Stamp + patch for a parent class given widget names from its tree.
	 *  NOTE: prefer EnsureBindWidgetFromTree — the TSet overload cannot tell
	 *  variable widgets (which collide) from structural ones (which don't).
	 */
	static FBindWidgetPatchResult EnsureBindWidget(
		UClass* ParentClass,
		const TSet<FName>& TreeWidgetNames);

	/** Stamp + patch, considering only bIsVariable tree widgets.
	 *  Only variable widgets make the compiler create BPGC properties, so only
	 *  they can collide with same-named C++ properties. Structural widgets
	 *  (RootCanvasPanel, spacers — correctly BindWidget-less in stock headers)
	 *  are ignored, so this never adds spurious metadata. */
	static FBindWidgetPatchResult EnsureBindWidgetFromTree(
		UClass* ParentClass,
		class UWidgetTree* Tree);

	/** Convenience: collect tree names from an already-loaded WidgetBlueprint. */
	static FBindWidgetPatchResult EnsureBindWidgetForBlueprint(UWidgetBlueprint* WBP);

	/** Dry-run: properties that WOULD need a header patch (no writes).
	 *  Variable-widget matches only — same filter as the repair path. */
	static TArray<FString> FindMissingBindWidgetProperties(
		UClass* ParentClass,
		const TSet<FName>& TreeWidgetNames);

	/** Dry-run from a tree (variable-only filter). */
	static TArray<FString> FindMissingBindWidgetPropertiesFromTree(
		UClass* ParentClass,
		class UWidgetTree* Tree);
};

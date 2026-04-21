#pragma once

#include "CoreMinimal.h"
#include "BytecodeReader.h"

class UBlueprint;
class UBlueprintGeneratedClass;
class UEdGraph;
class UEdGraphPin;
class UEdGraphNode;
class UK2Node;
class UK2Node_DynamicCast;
class UPackage;

DECLARE_LOG_CATEGORY_EXTERN(LogGraphBuilder, Log, All);

/**
 * Consumes the IR from FBytecodeReader and constructs a UEdGraph-based UBlueprint.
 */
class BLUEPRINTUNCOOKER_API FGraphBuilder
{
public:
	// ── Public Entry Points ───────────────────────────────────────────────

	/** Create a standalone Blueprint that reimplements the cooked class. */
	static UBlueprint* BuildBlueprint(
		UBlueprintGeneratedClass* OriginalClass,
		UPackage* Package,
		const FString& BlueprintName,
		const TArray<FDecompiledFunction>& DecompiledFunctions);

	/** Create a child-class Blueprint whose parent IS the cooked BPGC. */
	static UBlueprint* BuildChildBlueprint(
		UBlueprintGeneratedClass* OriginalClass,
		UPackage* Package,
		const FString& BlueprintName,
		const TArray<FDecompiledFunction>& DecompiledFunctions);

	/**
	 * Create a UWidgetBlueprint from a cooked UWidgetBlueprintGeneratedClass.
	 * Reconstructs the Designer-tab widget hierarchy (WidgetTree) and property
	 * bindings in addition to all EventGraph / function Blueprint logic.
	 * OriginalClass MUST be a UWidgetBlueprintGeneratedClass.
	 */
	static UBlueprint* BuildWidgetBlueprint(
		UBlueprintGeneratedClass* OriginalClass,
		UPackage* Package,
		const FString& BlueprintName,
		const TArray<FDecompiledFunction>& DecompiledFunctions);

private:
	FGraphBuilder(
		UBlueprintGeneratedClass* InOriginalClass,
		const TArray<FDecompiledFunction>& InFunctions,
		bool bInIsChildClass);

	// ── Core Build ────────────────────────────────────────────────────────
	void BuildBlueprintCore(UBlueprint* BP, bool bIsLiveUncook);

	void SetupVariables(UBlueprint* BP);
	void SetupInterfaces(UBlueprint* BP);
	void SetupComponents(UBlueprint* BP);
	void SetupTimelines(UBlueprint* BP);
	void SetupInheritableComponents(UBlueprint* BP);

	void BuildEventGraph(
		UBlueprint* BP,
		UEdGraph* EventGraph,
		const FDecompiledFunction& UbergraphFunc,
		const TArray<const FDecompiledFunction*>& EventStubs);

	void BuildFunctionGraph(UBlueprint* BP, const FDecompiledFunction& Func);

	/** Emit a range of statements into a graph, returning the last exec-out pin. */
	UEdGraphPin* EmitStatements(
		UBlueprint* BP,
		UEdGraph* Graph,
		const TArray<TSharedPtr<FDecompiledExpr>>& Statements,
		int32 StartIdx,
		int32 EndIdx,
		UEdGraphPin* IncomingExecPin,
		int32& InOutNodeX,
		int32 NodeY);

	/** Create and wire the correct UK2Node for an executable statement expression. */
	UEdGraphPin* CreateNodeForExpr(
		UBlueprint* BP,
		UEdGraph* Graph,
		const TSharedPtr<FDecompiledExpr>& Expr,
		UEdGraphPin* IncomingExecPin,
		int32& InOutNodeX,
		int32 NodeY);

	/** Resolve a data-producing expression to an output pin.
	 *  May set pin->DefaultValue instead (for literals), returning nullptr. */
	UEdGraphPin* ResolveDataExpr(
		UEdGraph* Graph,
		const TSharedPtr<FDecompiledExpr>& Expr,
		UEdGraphPin* ContextPin,
		int32 NodeX,
		int32 NodeY);

	// ── Pin Connection Helpers ────────────────────────────────────────────
	bool TryConnect(UEdGraphPin* A, UEdGraphPin* B);
	void ForceConnect(UEdGraph* Graph, UEdGraphPin* A, UEdGraphPin* B, int32 NodeX, int32 NodeY);
	void SanitizeGraphConnections(UBlueprint* BP);

	// ── Shared Node Factory Helpers ───────────────────────────────────────
	UK2Node_DynamicCast* CreateDynamicCastNode(
		UEdGraph* Graph,
		UClass* TargetType,
		const TSharedPtr<FDecompiledExpr>& SourceExpr,
		int32 NodeX, int32 NodeY);

	/** Post-build fixup passes (wildcard propagation, select fix, etc.). */
	void RunPostBuildFixups(UBlueprint* BP);

	/**
	 * Widget Blueprint only — duplicate the cooked UWidgetTree from
	 * UWidgetBlueprintGeneratedClass into the new UWidgetBlueprint, and
	 * convert runtime bindings to editor bindings.
	 * No-op if OriginalClass is not a UWidgetBlueprintGeneratedClass.
	 */
	void SetupWidgetTree(UBlueprint* BP);

	// ── State ─────────────────────────────────────────────────────────────
	UBlueprintGeneratedClass*         OriginalClass;
	const TArray<FDecompiledFunction>& DecompiledFunctions;
	bool bBuildingChildClass;

	/** The current function entry node (for self-pin resolution). */
	UEdGraphNode* CurrentFunctionEntryNode = nullptr;

	/** Offset→statement-index map for the function currently being emitted.
	 *  Set by BuildEventGraph / BuildFunctionGraph before calling EmitStatements.
	 *  Used by EmitStatements to wire the Else path of EX_JumpIfNot. */
	const TMap<int32, int32>* CurrentOffsetToStatementIndex = nullptr;

	/** Pending context object for EX_Context chains.
	 *  Set just before recursing into the inner expression so function-call
	 *  handlers can wire the context object to the "Target" input pin.
	 *  Consumed and cleared by the first function-call handler that sees it. */
	TSharedPtr<FDecompiledExpr> PendingContextObject;

	/** Maps local variable property names → the output pin that last wrote them. */
	TMap<FString, UEdGraphPin*> LocalVarToPinMap;

	/** Persistent frame vars — NOT cleared between events. */
	TMap<FString, UEdGraphPin*> PersistentFrameVarMap;

	/** Temp_ variable literal cache: name → literal expr (assigned once). */
	TMap<FString, TSharedPtr<FDecompiledExpr>> TempLiteralMap;

	/** Temp_ vars assigned more than once (loop vars): name → shared Get node output pin. */
	TMap<FString, UEdGraphPin*> MultiAssignedTempPins;

	/** Temp_ vars seen more than once in assignments. */
	TSet<FString> MultiAssignedTempVars;

	/** Struct member writes accumulated for MakeStruct inlining. */
	TMap<FString, TMap<FName, TSharedPtr<FDecompiledExpr>>> StructMemberAssignMap;

	/** Pending exec pins from EX_PushExecutionFlow — maps bytecode offset → Sequence Then-1 pin.
	 *  Populated in CreateNodeForExpr, consumed in EmitStatements. Cleared per function. */
	TMap<int32, UEdGraphPin*> PendingExecAtOffset;

	/** Deferred data wires (backward jumps / loops). */
	struct FDeferredWire { UEdGraphPin* Source; UEdGraphPin* Target; };
	TArray<FDeferredWire> DeferredDataWires;

	/** Pin defaults to restore after RefreshAllNodes. */
	struct FDeferredDefault { UEdGraphPin* Pin; FString DefaultValue; };
	TArray<FDeferredDefault> DeferredPinDefaults;

	void ClearLocalVarMap();
};

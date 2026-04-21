#include "GraphBuilder.h"

#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Engine/SimpleConstructionScript.h"
#include "Engine/SCS_Node.h"
#include "Engine/TimelineTemplate.h"
#include "Components/ActorComponent.h"

#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraphSchema.h"
#include "EdGraphSchema_K2.h"

// UK2Node types
#include "K2Node_Event.h"
#include "K2Node_CustomEvent.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_FunctionResult.h"
#include "K2Node_CallFunction.h"
#include "K2Node_VariableGet.h"
#include "K2Node_VariableSet.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_ExecutionSequence.h"
#include "K2Node_DynamicCast.h"
#include "K2Node_Select.h"
#include "K2Node_MakeArray.h"
#include "K2Node_MakeSet.h"
#include "K2Node_MakeMap.h"
#include "K2Node_MakeStruct.h"
#include "K2Node_GetArrayItem.h"
#include "K2Node_AddDelegate.h"
#include "K2Node_RemoveDelegate.h"
#include "K2Node_ClearDelegate.h"
#include "K2Node_CallDelegate.h"
#include "K2Node_CreateDelegate.h"
#include "K2Node_AssignDelegate.h"
#include "K2Node_Self.h"
#include "K2Node_Timeline.h"
#include "K2Node_InputAction.h"
#include "K2Node_InputAxisEvent.h"
#include "K2Node_BreakStruct.h"
#include "Engine/InheritableComponentHandler.h"

#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "KismetCompilerModule.h"

#include "BlueprintEditorSettings.h"
#include "UObject/UnrealType.h"
#include "UObject/UObjectIterator.h"

// Widget Blueprint support
#include "Blueprint/WidgetBlueprintGeneratedClass.h" // UWidgetBlueprintGeneratedClass, FDelegateRuntimeBinding, EBindingKind
#include "Blueprint/WidgetTree.h"                    // UWidgetTree
#include "WidgetBlueprint.h"                         // UWidgetBlueprint, FDelegateEditorBinding
#include "Animation/WidgetAnimation.h"               // UWidgetAnimation — explicit dep (also transitively via WBPGC header)

DEFINE_LOG_CATEGORY(LogGraphBuilder);

// ---------------------------------------------------------------------------
// Layout constants
// ---------------------------------------------------------------------------
static constexpr int32 NodeSpacingX     = 350;
static constexpr int32 DataNodeOffsetY  = 150;
static constexpr int32 EventSpacingY    = 300;

// ---------------------------------------------------------------------------
// Helper: create a node and place it
// ---------------------------------------------------------------------------
template<typename NodeType>
static NodeType* SpawnNode(UEdGraph* Graph, int32 X, int32 Y)
{
	NodeType* Node = NewObject<NodeType>(Graph);
	Graph->AddNode(Node, false, false);
	Node->CreateNewGuid();
	Node->PostPlacedNewNode();
	Node->AllocateDefaultPins();
	Node->NodePosX = X;
	Node->NodePosY = Y;
	return Node;
}

// ---------------------------------------------------------------------------
// Helper: find pin by name
// ---------------------------------------------------------------------------
static UEdGraphPin* FindPinByName(UEdGraphNode* Node, FName PinName,
	EEdGraphPinDirection Dir = EGPD_MAX)
{
	for (UEdGraphPin* Pin : Node->Pins)
	{
		if (Pin && Pin->PinName == PinName
			&& (Dir == EGPD_MAX || Pin->Direction == Dir))
		{
			return Pin;
		}
	}
	return nullptr;
}

// ---------------------------------------------------------------------------
// Helper: get exec input/output pins
// ---------------------------------------------------------------------------
static UEdGraphPin* GetExecIn(UEdGraphNode* Node)
{
	for (UEdGraphPin* Pin : Node->Pins)
	{
		if (Pin && Pin->Direction == EGPD_Input
			&& Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
		{
			return Pin;
		}
	}
	return nullptr;
}

static UEdGraphPin* GetExecOut(UEdGraphNode* Node, int32 Index = 0)
{
	int32 Found = 0;
	for (UEdGraphPin* Pin : Node->Pins)
	{
		if (Pin && Pin->Direction == EGPD_Output
			&& Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
		{
			if (Found == Index) return Pin;
			++Found;
		}
	}
	return nullptr;
}

// ---------------------------------------------------------------------------
// Helper: map FProperty to FEdGraphPinType (UE5.1)
// ---------------------------------------------------------------------------
static FEdGraphPinType PropertyToPinType(FProperty* Prop)
{
	FEdGraphPinType PT;
	if (!Prop) return PT;

	if (Prop->IsA<FBoolProperty>())
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Boolean;
	}
	else if (Prop->IsA<FIntProperty>())
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Int;
	}
	else if (Prop->IsA<FInt64Property>())
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Int64;
	}
	else if (Prop->IsA<FDoubleProperty>())
	{
		PT.PinCategory    = UEdGraphSchema_K2::PC_Real;
		PT.PinSubCategory = UEdGraphSchema_K2::PC_Double;
	}
	else if (Prop->IsA<FFloatProperty>())
	{
		PT.PinCategory    = UEdGraphSchema_K2::PC_Real;
		PT.PinSubCategory = UEdGraphSchema_K2::PC_Float;
	}
	else if (Prop->IsA<FStrProperty>())
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_String;
	}
	else if (Prop->IsA<FNameProperty>())
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Name;
	}
	else if (Prop->IsA<FTextProperty>())
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Text;
	}
	else if (FEnumProperty* EnumProp = CastField<FEnumProperty>(Prop))
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Byte;
		PT.PinSubCategoryObject = EnumProp->GetEnum();
	}
	else if (FByteProperty* ByteProp = CastField<FByteProperty>(Prop))
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Byte;
		if (ByteProp->Enum) PT.PinSubCategoryObject = ByteProp->Enum;
	}
	else if (FClassProperty* ClassProp = CastField<FClassProperty>(Prop))
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Class;
		PT.PinSubCategoryObject = ClassProp->MetaClass;
	}
	else if (FSoftClassProperty* SoftClassProp = CastField<FSoftClassProperty>(Prop))
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_SoftClass;
		PT.PinSubCategoryObject = SoftClassProp->MetaClass;
	}
	else if (FObjectProperty* ObjProp = CastField<FObjectProperty>(Prop))
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Object;
		PT.PinSubCategoryObject = ObjProp->PropertyClass;
	}
	else if (FSoftObjectProperty* SoftProp = CastField<FSoftObjectProperty>(Prop))
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_SoftObject;
		PT.PinSubCategoryObject = SoftProp->PropertyClass;
	}
	else if (FInterfaceProperty* IfaceProp = CastField<FInterfaceProperty>(Prop))
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Interface;
		PT.PinSubCategoryObject = IfaceProp->InterfaceClass;
	}
	else if (FStructProperty* StructProp = CastField<FStructProperty>(Prop))
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Struct;
		PT.PinSubCategoryObject = StructProp->Struct;
	}
	else if (FArrayProperty* ArrProp = CastField<FArrayProperty>(Prop))
	{
		PT.PinCategory           = UEdGraphSchema_K2::PC_Wildcard;
		PT.ContainerType         = EPinContainerType::Array;
		PT.PinValueType          = FEdGraphTerminalType();
		// Recurse for inner type
		FEdGraphPinType InnerType = PropertyToPinType(ArrProp->Inner);
		PT.PinCategory = InnerType.PinCategory;
		PT.PinSubCategory = InnerType.PinSubCategory;
		PT.PinSubCategoryObject = InnerType.PinSubCategoryObject;
		PT.ContainerType = EPinContainerType::Array;
	}
	else if (FSetProperty* SetProp = CastField<FSetProperty>(Prop))
	{
		FEdGraphPinType InnerType = PropertyToPinType(SetProp->ElementProp);
		PT.PinCategory = InnerType.PinCategory;
		PT.PinSubCategory = InnerType.PinSubCategory;
		PT.PinSubCategoryObject = InnerType.PinSubCategoryObject;
		PT.ContainerType = EPinContainerType::Set;
	}
	else if (FMapProperty* MapProp = CastField<FMapProperty>(Prop))
	{
		FEdGraphPinType KeyType = PropertyToPinType(MapProp->KeyProp);
		PT.PinCategory = KeyType.PinCategory;
		PT.PinSubCategory = KeyType.PinSubCategory;
		PT.PinSubCategoryObject = KeyType.PinSubCategoryObject;
		PT.ContainerType = EPinContainerType::Map;
	}
	else if (Prop->IsA<FDelegateProperty>())
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Delegate;
	}
	else if (Prop->IsA<FMulticastDelegateProperty>())
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_MCDelegate;
	}
	else
	{
		PT.PinCategory = UEdGraphSchema_K2::PC_Wildcard;
	}

	return PT;
}

// ---------------------------------------------------------------------------
// Helper: known engine event names → declaring class
// ---------------------------------------------------------------------------
static UClass* FindEventDeclaredClass(const FString& FuncName, UClass* BPGC)
{
	// Walk up the hierarchy to find which class first declares this function
	for (UClass* C = BPGC->GetSuperClass(); C; C = C->GetSuperClass())
	{
		if (C->FindFunctionByName(*FuncName, EIncludeSuperFlag::ExcludeSuper))
		{
			return C;
		}
	}
	return nullptr;
}

// ---------------------------------------------------------------------------
// FGraphBuilder constructor
// ---------------------------------------------------------------------------

FGraphBuilder::FGraphBuilder(
	UBlueprintGeneratedClass* InOriginalClass,
	const TArray<FDecompiledFunction>& InFunctions,
	bool bInIsChildClass)
	: OriginalClass(InOriginalClass)
	, DecompiledFunctions(InFunctions)
	, bBuildingChildClass(bInIsChildClass)
{}

void FGraphBuilder::ClearLocalVarMap()
{
	LocalVarToPinMap.Empty();
	TempLiteralMap.Empty();
	StructMemberAssignMap.Empty();
	PendingExecAtOffset.Empty();
}

// ---------------------------------------------------------------------------
// Public entry points
// ---------------------------------------------------------------------------

UBlueprint* FGraphBuilder::BuildBlueprint(
	UBlueprintGeneratedClass* OriginalClass,
	UPackage* Package,
	const FString& BlueprintName,
	const TArray<FDecompiledFunction>& DecompiledFunctions)
{
	FGraphBuilder Builder(OriginalClass, DecompiledFunctions, false);

	UClass* ParentClass = OriginalClass->GetSuperClass();
	if (!ParentClass) ParentClass = UObject::StaticClass();

	UBlueprint* NewBP = FKismetEditorUtilities::CreateBlueprint(
		ParentClass, Package, *BlueprintName,
		BPTYPE_Normal,
		UBlueprint::StaticClass(),
		UBlueprintGeneratedClass::StaticClass(),
		FName("BlueprintUncooker"));

	if (!NewBP) return nullptr;

	// Missing 8: NativeClass is not exposed on UBlueprint in UE 5.1 (it was added in 5.2+).
	// ParentClass information is already encoded in BP->ParentClass set by CreateBlueprint.

	Builder.BuildBlueprintCore(NewBP, false);

	// Move interface function graphs from FunctionGraphs → InterfaceDesc.Graphs
	for (FBPInterfaceDescription& IfaceDesc : NewBP->ImplementedInterfaces)
	{
		for (int32 i = NewBP->FunctionGraphs.Num() - 1; i >= 0; --i)
		{
			UEdGraph* G = NewBP->FunctionGraphs[i];
			if (!G) continue;
			if (IfaceDesc.Interface &&
				IfaceDesc.Interface->FindFunctionByName(G->GetFName(), EIncludeSuperFlag::IncludeSuper))
			{
				IfaceDesc.Graphs.Add(G);
				NewBP->FunctionGraphs.RemoveAt(i);
			}
		}
	}

	return NewBP;
}

UBlueprint* FGraphBuilder::BuildChildBlueprint(
	UBlueprintGeneratedClass* OriginalClass,
	UPackage* Package,
	const FString& BlueprintName,
	const TArray<FDecompiledFunction>& DecompiledFunctions)
{
	FGraphBuilder Builder(OriginalClass, DecompiledFunctions, true);

	// Parent class IS the cooked BPGC itself
	UBlueprint* NewBP = FKismetEditorUtilities::CreateBlueprint(
		OriginalClass, Package, *BlueprintName,
		BPTYPE_Normal,
		UBlueprint::StaticClass(),
		UBlueprintGeneratedClass::StaticClass(),
		FName("BlueprintUncooker"));

	if (!NewBP) return nullptr;

	Builder.BuildBlueprintCore(NewBP, false);

	for (FBPInterfaceDescription& IfaceDesc : NewBP->ImplementedInterfaces)
	{
		for (int32 i = NewBP->FunctionGraphs.Num() - 1; i >= 0; --i)
		{
			UEdGraph* G = NewBP->FunctionGraphs[i];
			if (!G) continue;
			if (IfaceDesc.Interface &&
				IfaceDesc.Interface->FindFunctionByName(G->GetFName(), EIncludeSuperFlag::IncludeSuper))
			{
				IfaceDesc.Graphs.Add(G);
				NewBP->FunctionGraphs.RemoveAt(i);
			}
		}
	}

	return NewBP;
}

// ---------------------------------------------------------------------------
// BuildWidgetBlueprint
// ---------------------------------------------------------------------------

UBlueprint* FGraphBuilder::BuildWidgetBlueprint(
	UBlueprintGeneratedClass* OriginalClass,
	UPackage* Package,
	const FString& BlueprintName,
	const TArray<FDecompiledFunction>& DecompiledFunctions)
{
	FGraphBuilder Builder(OriginalClass, DecompiledFunctions, false);

	UClass* ParentClass = OriginalClass->GetSuperClass();
	if (!ParentClass) ParentClass = UObject::StaticClass();

	// Create a UWidgetBlueprint (not a plain UBlueprint) so the UE editor
	// gives us the Designer tab and the correct asset type.
	UWidgetBlueprint* NewWBP = Cast<UWidgetBlueprint>(
		FKismetEditorUtilities::CreateBlueprint(
			ParentClass, Package, *BlueprintName,
			BPTYPE_Normal,
			UWidgetBlueprint::StaticClass(),
			UWidgetBlueprintGeneratedClass::StaticClass(),
			FName("BlueprintUncooker")));

	if (!NewWBP)
	{
		UE_LOG(LogTemp, Warning,
			TEXT("[BPUncooker] BuildWidgetBlueprint: FKismetEditorUtilities::CreateBlueprint returned null for '%s'"),
			*BlueprintName);
		return nullptr;
	}

	// ── EventGraph + function graphs (identical to regular BP path) ───────
	Builder.BuildBlueprintCore(NewWBP, false);

	// Move interface function graphs from FunctionGraphs → InterfaceDesc.Graphs
	for (FBPInterfaceDescription& IfaceDesc : NewWBP->ImplementedInterfaces)
	{
		for (int32 i = NewWBP->FunctionGraphs.Num() - 1; i >= 0; --i)
		{
			UEdGraph* G = NewWBP->FunctionGraphs[i];
			if (!G) continue;
			if (IfaceDesc.Interface &&
				IfaceDesc.Interface->FindFunctionByName(
					G->GetFName(), EIncludeSuperFlag::IncludeSuper))
			{
				IfaceDesc.Graphs.Add(G);
				NewWBP->FunctionGraphs.RemoveAt(i);
			}
		}
	}

	// ── Widget tree + bindings (WBP-specific) ─────────────────────────────
	Builder.SetupWidgetTree(NewWBP);

	return NewWBP;
}

// ---------------------------------------------------------------------------
// BuildBlueprintCore
// ---------------------------------------------------------------------------

void FGraphBuilder::BuildBlueprintCore(UBlueprint* BP, bool bIsLiveUncook)
{
	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] BuildBlueprintCore: %d decompiled functions total"),
		DecompiledFunctions.Num());

	if (!bBuildingChildClass)
	{
		SetupVariables(BP);
		SetupComponents(BP);
		SetupTimelines(BP);
		SetupInheritableComponents(BP);
	}
	SetupInterfaces(BP);

	// Classify functions
	const FDecompiledFunction* UbergraphFunc = nullptr;
	TArray<const FDecompiledFunction*> EventStubs;
	TArray<const FDecompiledFunction*> RegularFunctions;

	for (const FDecompiledFunction& Func : DecompiledFunctions)
	{
		UE_LOG(LogTemp, Log, TEXT("[BPUncooker]   Func='%s' bIsUbergraph=%d bIsEventStub=%d stmts=%d entryOff=%d"),
			*Func.FunctionName, (int)Func.bIsUbergraph, (int)Func.bIsEventStub,
			Func.Statements.Num(), Func.UbergraphEntryOffset);
		if (Func.bIsUbergraph)
		{
			UbergraphFunc = &Func;
		}
		else if (Func.bIsEventStub)
		{
			EventStubs.Add(&Func);
		}
		else
		{
			RegularFunctions.Add(&Func);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("[BPUncooker] Classification: ubergraph=%s | eventStubs=%d | regularFuncs=%d"),
		UbergraphFunc ? *UbergraphFunc->FunctionName : TEXT("NONE"),
		EventStubs.Num(), RegularFunctions.Num());

	// Build event graph
	UEdGraph* EventGraph = BP->UbergraphPages.Num() > 0
		? BP->UbergraphPages[0]
		: FBlueprintEditorUtils::CreateNewGraph(BP, TEXT("EventGraph"),
			UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());

	if (BP->UbergraphPages.Num() == 0)
	{
		BP->UbergraphPages.Add(EventGraph);
	}

	if (UbergraphFunc)
	{
		BuildEventGraph(BP, EventGraph, *UbergraphFunc, EventStubs);
	}

	// Build regular function graphs
	for (const FDecompiledFunction* Func : RegularFunctions)
	{
		if (Func->Statements.Num() > 0)
		{
			BuildFunctionGraph(BP, *Func);
		}
	}

	// ── Post-build sequence ──────────────────────────────────────────────

	// Step 1: Skeleton + node refresh
	FKismetEditorUtilities::GenerateBlueprintSkeleton(BP, true);
	FBlueprintEditorUtils::RefreshAllNodes(BP);

	// Step 2-6: Post-refresh fixups
	RunPostBuildFixups(BP);

	// Step 7: Final structural modification
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
}

// ---------------------------------------------------------------------------
// SetupVariables
// ---------------------------------------------------------------------------

void FGraphBuilder::SetupVariables(UBlueprint* BP)
{
	if (!OriginalClass) return;

	// Collect names already in NewVariables to avoid duplicates
	TSet<FName> ExistingVars;
	for (const FBPVariableDescription& Var : BP->NewVariables)
	{
		ExistingVars.Add(Var.VarName);
	}

	for (TFieldIterator<FProperty> PropIt(OriginalClass, EFieldIteratorFlags::ExcludeSuper);
		PropIt; ++PropIt)
	{
		FProperty* Prop = *PropIt;
		if (!Prop) continue;

		const FName PropName = Prop->GetFName();
		const FString PropNameStr = Prop->GetName();

		// Skip compiler-internal props
		if (PropNameStr.StartsWith(TEXT("__"))) continue;
		if (PropNameStr.Contains(TEXT("_INST"))) continue;
		if (PropNameStr.StartsWith(TEXT("K2Node_"))) continue;

		// Skip function parameters
		if (Prop->HasAnyPropertyFlags(CPF_Parm)) continue;

		// ── Skip properties that already exist in ANY parent class ────────
		// Cooked BPGCs sometimes "flatten" parent-class properties directly
		// onto the generated class. Adding them as Blueprint variables causes
		// "tried to create property X … but another object already exists"
		// compiler errors because the property is still owned by the C++ parent.
		{
			bool bInParent = false;
			for (UClass* C = BP->ParentClass; C; C = C->GetSuperClass())
			{
				if (FindFProperty<FProperty>(C, PropName))
				{
					bInParent = true;
					break;
				}
			}
			if (bInParent) continue;
		}

		// Skip component refs (handled by SCS)
		if (FObjectProperty* ObjProp = CastField<FObjectProperty>(Prop))
		{
			if (ObjProp->PropertyClass &&
				ObjProp->PropertyClass->IsChildOf(UActorComponent::StaticClass()))
			{
				continue;
			}

			// ── Widget Blueprints: skip UWidget-typed properties ──────────
			// In a cooked WidgetBlueprintGeneratedClass every named widget in
			// the WidgetTree is also stored as an ObjectProperty on the BPGC
			// (so the compiler can bind it).  Adding these as BP NewVariables
			// causes duplicate-property ensures (e.g. "Top") because the WBP
			// compiler later re-creates those properties from the WidgetTree.
			if (ObjProp->PropertyClass &&
				ObjProp->PropertyClass->IsChildOf(UWidget::StaticClass()))
			{
				continue;
			}

			// ── Widget Blueprints: skip UWidgetAnimation-typed properties ─
			// The cooked WBPGC has one CPF_Transient FObjectProperty per
			// animation (property class = UWidgetAnimation).  The WBP compiler
			// re-creates these automatically from the Animations[] array;
			// adding them as NewVariables causes duplicate-property errors.
			if (ObjProp->PropertyClass &&
				ObjProp->PropertyClass->IsChildOf(UWidgetAnimation::StaticClass()))
			{
				continue;
			}
		}

		// Skip timeline-internal properties
		if (PropNameStr.Equals(TEXT("Direction")) ||
			PropNameStr.Equals(TEXT("NewTime"))   ||
			PropNameStr.StartsWith(TEXT("Timeline_")))
		{
			continue;
		}

		// Skip duplicates
		if (ExistingVars.Contains(PropName)) continue;

		FBPVariableDescription VarDesc;
		VarDesc.VarName = PropName;
		VarDesc.VarType = PropertyToPinType(Prop);

		// Preserve the original GUID so property redirects work on saved instances.
		{
			const FGuid* OrigGuid = OriginalClass->CookedPropertyGuids.Find(PropName);
			VarDesc.VarGuid = OrigGuid ? *OrigGuid : FGuid::NewGuid();
		}

		// Copy all property flags that survive cooking
		if (Prop->HasAnyPropertyFlags(CPF_BlueprintVisible))    VarDesc.PropertyFlags |= CPF_BlueprintVisible;
		if (Prop->HasAnyPropertyFlags(CPF_Edit))                VarDesc.PropertyFlags |= CPF_Edit;
		if (Prop->HasAnyPropertyFlags(CPF_BlueprintReadOnly))   VarDesc.PropertyFlags |= CPF_BlueprintReadOnly;
		if (Prop->HasAnyPropertyFlags(CPF_Net))                 VarDesc.PropertyFlags |= CPF_Net;
		if (Prop->HasAnyPropertyFlags(CPF_SaveGame))            VarDesc.PropertyFlags |= CPF_SaveGame;
		if (Prop->HasAnyPropertyFlags(CPF_BlueprintAssignable)) VarDesc.PropertyFlags |= CPF_BlueprintAssignable;
		if (Prop->HasAnyPropertyFlags(CPF_BlueprintCallable))   VarDesc.PropertyFlags |= CPF_BlueprintCallable;
		// Replication notification function
		if (!Prop->RepNotifyFunc.IsNone())
			VarDesc.RepNotifyFunc = Prop->RepNotifyFunc;

		// Missing 2 fix: additional editor/replication flags not previously copied
		if (Prop->HasAnyPropertyFlags(CPF_Transient))             VarDesc.PropertyFlags |= CPF_Transient;
		if (Prop->HasAnyPropertyFlags(CPF_ExposeOnSpawn))         VarDesc.PropertyFlags |= CPF_ExposeOnSpawn;
		if (Prop->HasAnyPropertyFlags(CPF_NoClear))               VarDesc.PropertyFlags |= CPF_NoClear;
		// CPF_InstancedReference (0x4000) — sub-object instancing (deep copy on spawn)
		if (Prop->HasAnyPropertyFlags(CPF_InstancedReference))    VarDesc.PropertyFlags |= CPF_InstancedReference;
		if (Prop->HasAnyPropertyFlags(CPF_DisableEditOnInstance)) VarDesc.PropertyFlags |= CPF_DisableEditOnInstance;
		if (Prop->HasAnyPropertyFlags(CPF_DisableEditOnTemplate)) VarDesc.PropertyFlags |= CPF_DisableEditOnTemplate;
		if (Prop->HasAnyPropertyFlags(CPF_Config))                VarDesc.PropertyFlags |= CPF_Config;

		// Missing 3 fix: category, tooltip, and friendly name from FProperty metadata
		{
			FString CategoryStr = Prop->GetMetaData(TEXT("Category"));
			if (!CategoryStr.IsEmpty())
				VarDesc.Category = FText::FromString(CategoryStr);

			FString ToolTipStr = Prop->GetMetaData(TEXT("ToolTip"));
			if (!ToolTipStr.IsEmpty())
			{
				FBPVariableMetaDataEntry MetaEntry;
				MetaEntry.DataKey   = TEXT("Tooltip");
				MetaEntry.DataValue = ToolTipStr;
				VarDesc.MetaDataArray.Add(MetaEntry);
			}

			FString FriendlyNameStr = Prop->GetMetaData(TEXT("DisplayName"));
			if (!FriendlyNameStr.IsEmpty())
				VarDesc.FriendlyName = FriendlyNameStr;
		}

		BP->NewVariables.Add(VarDesc);
		ExistingVars.Add(PropName);
	}
}

// ---------------------------------------------------------------------------
// SetupInterfaces
// ---------------------------------------------------------------------------

void FGraphBuilder::SetupInterfaces(UBlueprint* BP)
{
	if (!OriginalClass) return;

	for (const FImplementedInterface& IfaceInfo : OriginalClass->Interfaces)
	{
		if (!IfaceInfo.Class) continue;

		// Check not already added
		bool bAlreadyAdded = false;
		for (const FBPInterfaceDescription& Existing : BP->ImplementedInterfaces)
		{
			if (Existing.Interface == IfaceInfo.Class)
			{
				bAlreadyAdded = true;
				break;
			}
		}
		if (bAlreadyAdded) continue;

		FBPInterfaceDescription Desc;
		Desc.Interface = IfaceInfo.Class;
		BP->ImplementedInterfaces.Add(Desc);
	}
}

// ---------------------------------------------------------------------------
// SetupComponents
// ---------------------------------------------------------------------------

void FGraphBuilder::SetupComponents(UBlueprint* BP)
{
	if (!OriginalClass) return;

	USimpleConstructionScript* OrigSCS = OriginalClass->SimpleConstructionScript;
	if (!OrigSCS) return;

	USimpleConstructionScript* NewSCS = BP->SimpleConstructionScript;
	if (!NewSCS) return;

	// Bug 5 fix: preserve the parent-child hierarchy instead of making all nodes root-level.
	// USimpleConstructionScript::AddNode() always creates a root node; to attach a child we
	// must explicitly add it to the parent node's ChildNodes array instead.

	// Pass 1: create all nodes and build old→new mapping
	TMap<USCS_Node*, USCS_Node*> NodeMap;
	for (USCS_Node* OrigNode : OrigSCS->GetAllNodes())
	{
		if (!OrigNode || !OrigNode->ComponentClass) continue;

		USCS_Node* NewNode = NewSCS->CreateNode(OrigNode->ComponentClass,
			OrigNode->GetVariableName());
		if (!NewNode) continue;

		NewNode->AttachToName = OrigNode->AttachToName;

		// Copy component template properties
		if (OrigNode->ComponentTemplate && NewNode->ComponentTemplate)
		{
			UEngine::CopyPropertiesForUnrelatedObjects(
				OrigNode->ComponentTemplate, NewNode->ComponentTemplate);
		}

		NodeMap.Add(OrigNode, NewNode);
	}

	// Pass 2: wire hierarchy — child nodes into parent ChildNodes; root nodes via AddNode
	for (USCS_Node* OrigNode : OrigSCS->GetAllNodes())
	{
		USCS_Node** NewNodePtr = NodeMap.Find(OrigNode);
		if (!NewNodePtr) continue;
		USCS_Node* NewNode = *NewNodePtr;

		USCS_Node* ParentOrig = OrigSCS->FindParentNode(OrigNode);
		if (ParentOrig)
		{
			USCS_Node** NewParentPtr = NodeMap.Find(ParentOrig);
			if (NewParentPtr)
			{
				(*NewParentPtr)->ChildNodes.Add(NewNode);
				continue; // skip AddNode — it would re-root the child
			}
		}
		// No parent (or parent not in map) → add as root
		NewSCS->AddNode(NewNode);
	}
}

// ---------------------------------------------------------------------------
// SetupTimelines
// ---------------------------------------------------------------------------

void FGraphBuilder::SetupTimelines(UBlueprint* BP)
{
	if (!OriginalClass) return;

	// Get the event graph — timeline nodes live there.
	UEdGraph* EventGraph = BP->UbergraphPages.Num() > 0
		? BP->UbergraphPages[0] : nullptr;

	int32 TimelineNodeY = -EventSpacingY;
	for (UTimelineTemplate* OrigTT : OriginalClass->Timelines)
	{
		if (!OrigTT) continue;

		// Deep-copy the timeline template (curve assets, track arrays, flags)
		UTimelineTemplate* NewTT = DuplicateObject<UTimelineTemplate>(OrigTT, BP);
		if (!NewTT) continue;

		BP->Timelines.Add(NewTT);

		UE_LOG(LogGraphBuilder, Log,
			TEXT("[BPUncooker] SetupTimelines: '%s' Len=%.2f Loop=%d AutoPlay=%d "
			     "Float=%d Vec=%d Evt=%d"),
			*NewTT->GetName(), NewTT->TimelineLength, (int)NewTT->bLoop,
			(int)NewTT->bAutoPlay, NewTT->FloatTracks.Num(),
			NewTT->VectorTracks.Num(), NewTT->EventTracks.Num());

		// Spawn a UK2Node_Timeline in the event graph.
		// TimelineName MUST be set before AllocateDefaultPins() so the node
		// can look up the template and generate the correct track pins.
		if (EventGraph)
		{
			UK2Node_Timeline* TimelineNode = NewObject<UK2Node_Timeline>(EventGraph);
			EventGraph->AddNode(TimelineNode, false, false);
			TimelineNode->CreateNewGuid();
			TimelineNode->TimelineName        = OrigTT->GetFName();
			TimelineNode->TimelineGuid        = OrigTT->TimelineGuid;
			TimelineNode->bAutoPlay           = OrigTT->bAutoPlay;
			TimelineNode->bLoop               = OrigTT->bLoop;
			TimelineNode->bReplicated         = OrigTT->bReplicated;
			TimelineNode->bIgnoreTimeDilation = OrigTT->bIgnoreTimeDilation;
			TimelineNode->PostPlacedNewNode();
			TimelineNode->AllocateDefaultPins();
			TimelineNode->NodePosX = -NodeSpacingX * 2;
			TimelineNode->NodePosY = TimelineNodeY;
		}

		TimelineNodeY -= EventSpacingY;
	}
}

// ---------------------------------------------------------------------------
// SetupInheritableComponents
// ---------------------------------------------------------------------------

void FGraphBuilder::SetupInheritableComponents(UBlueprint* BP)
{
	if (!OriginalClass) return;

	UInheritableComponentHandler* OrigICH = OriginalClass->InheritableComponentHandler;
	if (!OrigICH) return;

	// DuplicateObject deep-copies all component override records and templates.
	UInheritableComponentHandler* NewICH =
		DuplicateObject<UInheritableComponentHandler>(OrigICH, BP);
	if (!NewICH) return;

	BP->InheritableComponentHandler = NewICH;

	UE_LOG(LogGraphBuilder, Log,
		TEXT("[BPUncooker] SetupInheritableComponents: copied ICH for '%s'"),
		*BP->GetName());
}

// ---------------------------------------------------------------------------
// SetupWidgetTree
// ---------------------------------------------------------------------------

void FGraphBuilder::SetupWidgetTree(UBlueprint* BP)
{
	// Only applies to Widget Blueprints
	UWidgetBlueprintGeneratedClass* WBPGC =
		Cast<UWidgetBlueprintGeneratedClass>(OriginalClass);
	if (!WBPGC) return;

	UWidgetBlueprint* WBP = Cast<UWidgetBlueprint>(BP);
	if (!WBP) return;

	// Log named-slot topology for traceability — the WBP compiler re-derives
	// these arrays from the widget tree at compile time; we do not need to copy
	// them manually, but logging helps diagnose missed slot reconstruction.
	UE_LOG(LogTemp, Log,
		TEXT("[BPUncooker] '%s': NamedSlots=%d Available=%d Instance=%d"),
		*WBP->GetName(),
		WBPGC->NamedSlots.Num(),
		WBPGC->AvailableNamedSlots.Num(),
		WBPGC->InstanceNamedSlots.Num());

	// ── Step 1: Duplicate WidgetTree ──────────────────────────────────────
	// UWidgetBlueprintGeneratedClass::WidgetTree is private in UE5.1, but the
	// class exposes public accessors: GetWidgetTreeArchetype() and
	// SetWidgetTreeArchetype(). Use those instead of reflection.
	UWidgetTree* SourceTree = WBPGC->GetWidgetTreeArchetype();

	if (SourceTree)
	{
		// DuplicateObject does a deep copy following all UObject references
		// inside the tree — nested slots and sub-widgets are copied correctly.
		UWidgetTree* CopiedTree = DuplicateObject<UWidgetTree>(SourceTree, WBP);
		if (CopiedTree)
		{
			WBP->WidgetTree = CopiedTree;
			UE_LOG(LogTemp, Log,
				TEXT("[BPUncooker] WidgetTree duplicated for '%s': RootWidget='%s' NamedSlotBindings=%d"),
				*WBP->GetName(),
				CopiedTree->RootWidget ? *CopiedTree->RootWidget->GetName() : TEXT("NULL"),
				CopiedTree->NamedSlotBindings.Num());
		}
		else
		{
			UE_LOG(LogTemp, Warning,
				TEXT("[BPUncooker] DuplicateObject<UWidgetTree> returned nullptr for '%s'"),
				*WBP->GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Log,
			TEXT("[BPUncooker] WidgetTree is null on WBPGC (empty widget blueprint '%s')"),
			*WBP->GetName());
	}

	// ── Step 2: Convert runtime bindings → editor bindings ───────────────
	// Full 1-to-1 mapping (confirmed against FWidgetBlueprintCompilerContext):
	//   ObjectName, PropertyName, FunctionName, SourcePath, Kind.
	// SourceProperty is an editor-display hint:
	//   Function bindings → same as FunctionName.
	//   Property bindings → left NAME_None; the WBP compiler uses SourcePath.
	// BUG FIX: previous code omitted Kind and SourcePath, so all property-kind
	// bindings were silently treated as function-kind by the editor.
	if (WBPGC->Bindings.Num() > 0)
	{
		WBP->Bindings.Reserve(WBPGC->Bindings.Num());
		for (const FDelegateRuntimeBinding& RB : WBPGC->Bindings)
		{
			FDelegateEditorBinding EB;
			EB.ObjectName   = RB.ObjectName;
			EB.PropertyName = RB.PropertyName;
			EB.FunctionName = RB.FunctionName;
			EB.Kind         = RB.Kind;          // function vs property kind   (FIX: was missing)
			// NOTE: FDelegateEditorBinding::SourcePath is FEditorPropertyPath (UMGEditor type)
			// while FDelegateRuntimeBinding::SourcePath is FDynamicPropertyPath (CoreUObject).
			// These are incompatible types in UE5.1 — no cross-assignment operator exists.
			// The WBP compiler reconstructs the binding from Kind + FunctionName/SourceProperty,
			// so omitting the editor SourcePath path string does not break functional binding.

			// SourceProperty: editor-display hint only.
			// For Function bindings it equals FunctionName.
			// For Property bindings the WBP compiler uses SourcePath directly,
			// so SourceProperty is left as NAME_None (FIX: was wrongly set to
			// RB.FunctionName which is empty for property bindings).
			if (RB.Kind == EBindingKind::Function)
			{
				EB.SourceProperty = RB.FunctionName;
			}

			WBP->Bindings.Add(MoveTemp(EB));
		}
		UE_LOG(LogTemp, Log,
			TEXT("[BPUncooker] Converted %d widget binding(s) for '%s'"),
			WBPGC->Bindings.Num(), *WBP->GetName());
	}

	// ── Step 4: Auto-stamp BindWidget on C++ parent widget properties ─────
	// When the cooked WBP's widget tree contains a widget whose FName matches
	// an FObjectProperty on a C++ ancestor class, the WBP compiler tries to
	// create a new BPGC property for that tree widget — conflicting with the
	// inherited C++ property and raising:
	//   "Tried to create a property X … but another object already exists"
	// The conflict is suppressed by setting the BindWidget metadata on the
	// C++ property at this point, which tells the WBP compiler "this property
	// is the authoritative binding for that named widget — do not create a
	// duplicate".  This is the generic equivalent of writing
	// meta=(BindWidget) in the original C++ source header, and means no
	// per-class header edits are ever required.
	if (WBP->WidgetTree)
	{
		// ── 4a. Collect every widget name present in the duplicated tree ─
		TSet<FName> TreeWidgetNames;
		WBP->WidgetTree->ForEachWidget([&TreeWidgetNames](UWidget* W)
		{
			if (W) TreeWidgetNames.Add(W->GetFName());
		});

		// ── 4b. Walk every C++ ancestor of the new WBP's parent class ───
		// Stop at UUserWidget/UWidget — engine classes never hold game-
		// specific BindWidget properties.
		int32 StampCount = 0;
		for (UClass* C = WBP->ParentClass; C; C = C->GetSuperClass())
		{
			if (C == UUserWidget::StaticClass() ||
				C == UWidget::StaticClass()     ||
				C == UObject::StaticClass())
			{
				break;
			}

			for (TFieldIterator<FObjectProperty> PropIt(C, EFieldIteratorFlags::ExcludeSuper);
				PropIt; ++PropIt)
			{
				FObjectProperty* Prop = *PropIt;
				if (!Prop || !Prop->PropertyClass) continue;
				if (!Prop->PropertyClass->IsChildOf(UWidget::StaticClass())) continue;
				if (!TreeWidgetNames.Contains(Prop->GetFName())) continue;

				// Already stamped (e.g. from a prior uncook run or from the
				// header itself)?  Nothing to do.
				if (Prop->HasMetaData(TEXT("BindWidget"))) continue;

				Prop->SetMetaData(TEXT("BindWidget"), TEXT(""));
				++StampCount;
				UE_LOG(LogTemp, Log,
					TEXT("[BPUncooker] Auto-stamped BindWidget on '%s::%s' for '%s'"),
					*C->GetName(), *Prop->GetName(), *WBP->GetName());
			}
		}

		if (StampCount > 0)
		{
			UE_LOG(LogTemp, Log,
				TEXT("[BPUncooker] Auto-stamped BindWidget on %d C++ parent propert(ies) for '%s'"),
				StampCount, *WBP->GetName());
		}
	}

	// ── Step 3: Duplicate widget animations ───────────────────────────────
	// WBPGC->Animations[] holds complete UWidgetAnimation (UMovieSceneSequence)
	// sub-objects: full UMovieScene with possessables, all tracks/sections,
	// AnimationBindings[] (FGuid ↔ widget name map), DisplayLabel, and
	// bLegacyFinishOnStop.  Without this step the Designer Animation panel is
	// empty and every animation variable reference in the logic graph is null.
	if (WBPGC->Animations.Num() > 0)
	{
		WBP->Animations.Reserve(WBPGC->Animations.Num());
		for (UWidgetAnimation* OrigAnim : WBPGC->Animations)
		{
			if (!OrigAnim) continue;
			UWidgetAnimation* NewAnim = DuplicateObject<UWidgetAnimation>(OrigAnim, WBP);
			if (NewAnim)
			{
				WBP->Animations.Add(NewAnim);
				UE_LOG(LogTemp, Log,
					TEXT("[BPUncooker] Duplicated animation '%s' (bindings=%d) for '%s'"),
					*OrigAnim->GetName(),
					OrigAnim->AnimationBindings.Num(),
					*WBP->GetName());
			}
			else
			{
				UE_LOG(LogTemp, Warning,
					TEXT("[BPUncooker] DuplicateObject<UWidgetAnimation> failed for '%s' in '%s'"),
					*OrigAnim->GetName(), *WBP->GetName());
			}
		}
		UE_LOG(LogTemp, Log,
			TEXT("[BPUncooker] %d animation(s) reconstructed for '%s'"),
			WBP->Animations.Num(), *WBP->GetName());
	}
}

// ---------------------------------------------------------------------------
// BuildEventGraph
// ---------------------------------------------------------------------------

void FGraphBuilder::BuildEventGraph(
	UBlueprint* BP,
	UEdGraph* EventGraph,
	const FDecompiledFunction& UbergraphFunc,
	const TArray<const FDecompiledFunction*>& EventStubs)
{
	int32 NodeX = 0;
	int32 NodeY = 0;

	for (const FDecompiledFunction* Stub : EventStubs)
	{
		if (!Stub) continue;

		ClearLocalVarMap();

		// Find the range of statements for this event in the ubergraph
		int32 StartIdx = INDEX_NONE;
		for (auto& KV : UbergraphFunc.OffsetToStatementIndex)
		{
			if (KV.Key == Stub->UbergraphEntryOffset)
			{
				StartIdx = KV.Value;
				break;
			}
		}

		// Find the next event's start to determine our end
		int32 EndIdx = UbergraphFunc.Statements.Num();
		for (const FDecompiledFunction* OtherStub : EventStubs)
		{
			if (OtherStub == Stub) continue;
			for (auto& KV : UbergraphFunc.OffsetToStatementIndex)
			{
				if (KV.Key == OtherStub->UbergraphEntryOffset && KV.Value > StartIdx)
				{
					EndIdx = FMath::Min(EndIdx, KV.Value);
				}
			}
		}

		if (StartIdx == INDEX_NONE) continue;

		// Determine event node type
		const FString& FuncName = Stub->FunctionName;
		UEdGraphNode* EntryNode = nullptr;

		UClass* DeclClass = FindEventDeclaredClass(FuncName, OriginalClass);
		bool bIsOverridableEvent = (DeclClass != nullptr)
			&& DeclClass->FindFunctionByName(*FuncName, EIncludeSuperFlag::ExcludeSuper) != nullptr;

		if (bBuildingChildClass)
		{
			// Always use CustomEvent for child class
			UK2Node_CustomEvent* CustomEventNode =
				SpawnNode<UK2Node_CustomEvent>(EventGraph, NodeX, NodeY);
			CustomEventNode->CustomFunctionName = FName(*FuncName);
			// Note: UK2Node_CustomEvent inherits from UK2Node_Event (not FunctionEntry)
			// and has no public replication API in UE5.1. Replication flags survive in
			// the compiled UFunction and take effect when the Blueprint is recompiled.
			EntryNode = CustomEventNode;
		}
		else if (bIsOverridableEvent)
		{
			UK2Node_Event* EventNode = SpawnNode<UK2Node_Event>(EventGraph, NodeX, NodeY);
			EventNode->EventReference.SetExternalMember(FName(*FuncName), DeclClass);
			EventNode->bOverrideFunction = true;
			EntryNode = EventNode;
		}
		else
		{
			UK2Node_CustomEvent* CustomEventNode =
				SpawnNode<UK2Node_CustomEvent>(EventGraph, NodeX, NodeY);
			CustomEventNode->CustomFunctionName = FName(*FuncName);
			// Add parameters and apply replication flags from original stub
			if (Stub->OriginalFunction)
			{
				for (TFieldIterator<FProperty> ParamIt(Stub->OriginalFunction);
					ParamIt && ParamIt->HasAnyPropertyFlags(CPF_Parm); ++ParamIt)
				{
					if (!ParamIt->HasAnyPropertyFlags(CPF_ReturnParm))
					{
						FEdGraphPinType PinType = PropertyToPinType(*ParamIt);
						CustomEventNode->CreateUserDefinedPin(
							ParamIt->GetFName(), PinType, EGPD_Output);
					}
				}
				// Note: UK2Node_CustomEvent has no public replication setter in UE5.1.
				// The net flags are encoded in the original UFunction and will be
				// visible after a full Blueprint recompile via the editor.
			}
			EntryNode = CustomEventNode;
		}

		if (!EntryNode) continue;

	CurrentFunctionEntryNode = EntryNode;
	CurrentOffsetToStatementIndex = &UbergraphFunc.OffsetToStatementIndex;

	UEdGraphPin* ExecOut = GetExecOut(EntryNode);
	int32 EmitX = NodeX + NodeSpacingX;

	// Emit statements for this event's region
	EmitStatements(BP, EventGraph, UbergraphFunc.Statements,
		StartIdx, EndIdx, ExecOut, EmitX, NodeY);

		NodeY += EventSpacingY;
	}
}

// ---------------------------------------------------------------------------
// BuildFunctionGraph
// ---------------------------------------------------------------------------

void FGraphBuilder::BuildFunctionGraph(UBlueprint* BP, const FDecompiledFunction& Func)
{
	ClearLocalVarMap();

	UEdGraph* FuncGraph = FBlueprintEditorUtils::CreateNewGraph(
		BP, FName(*Func.FunctionName),
		UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());

	// AddFunctionGraph is a template; pass a typed null to allow deduction
	FBlueprintEditorUtils::AddFunctionGraph<UFunction>(BP, FuncGraph, false, (UFunction*)nullptr);

	// Function entry node
	UK2Node_FunctionEntry* EntryNode =
		SpawnNode<UK2Node_FunctionEntry>(FuncGraph, 0, 0);

	if (Func.OriginalFunction)
	{
		EntryNode->FunctionReference.SetExternalMember(
			Func.OriginalFunction->GetFName(),
			OriginalClass);

		// Add input parameters
		for (TFieldIterator<FProperty> ParamIt(Func.OriginalFunction);
			ParamIt && ParamIt->HasAnyPropertyFlags(CPF_Parm); ++ParamIt)
		{
			if (!ParamIt->HasAnyPropertyFlags(CPF_ReturnParm | CPF_OutParm))
			{
				FEdGraphPinType PinType = PropertyToPinType(*ParamIt);
				EntryNode->CreateUserDefinedPin(
					ParamIt->GetFName(), PinType, EGPD_Output);
			}
		}

		// ── Apply function flags (pure, const, replication) via public AddExtraFlags ──
		const EFunctionFlags FuncFlags =
			(EFunctionFlags)Func.OriginalFunction->FunctionFlags;
		if (FuncFlags & FUNC_BlueprintPure)
			EntryNode->AddExtraFlags((int32)FUNC_BlueprintPure);
		if (FuncFlags & FUNC_Const)
			EntryNode->AddExtraFlags((int32)FUNC_Const);
		if (FuncFlags & FUNC_Net)
		{
			EntryNode->AddExtraFlags((int32)(FuncFlags &
				(FUNC_Net | FUNC_NetReliable | FUNC_NetMulticast |
				 FUNC_NetServer | FUNC_NetClient)));
		}
		// Pure functions have no exec pins — rebuild them now
		if (FuncFlags & FUNC_BlueprintPure)
		{
			EntryNode->ReconstructNode();
		}

		// Missing 6 fix: AuthorityOnly, Cosmetic, EditorOnly flags
		if (FuncFlags & FUNC_BlueprintAuthorityOnly)
			EntryNode->AddExtraFlags((int32)FUNC_BlueprintAuthorityOnly);
		if (FuncFlags & FUNC_BlueprintCosmetic)
			EntryNode->AddExtraFlags((int32)FUNC_BlueprintCosmetic);
		if (FuncFlags & FUNC_EditorOnly)
			EntryNode->AddExtraFlags((int32)FUNC_EditorOnly);

		// Missing 6 fix: Restore function metadata (tooltip, category, keywords, CallInEditor)
		{
			FString ToolTipStr = Func.OriginalFunction->GetMetaData(TEXT("ToolTip"));
			if (!ToolTipStr.IsEmpty())
				EntryNode->MetaData.ToolTip = FText::FromString(ToolTipStr);

			FString CategoryStr = Func.OriginalFunction->GetMetaData(TEXT("Category"));
			if (!CategoryStr.IsEmpty())
				EntryNode->MetaData.Category = FText::FromString(CategoryStr);

			FString KeywordsStr = Func.OriginalFunction->GetMetaData(TEXT("Keywords"));
			if (!KeywordsStr.IsEmpty())
				EntryNode->MetaData.Keywords = FText::FromString(KeywordsStr);

			FString CompactTitleStr = Func.OriginalFunction->GetMetaData(TEXT("CompactNodeTitle"));
			if (!CompactTitleStr.IsEmpty())
				EntryNode->MetaData.CompactNodeTitle = FText::FromString(CompactTitleStr);

			FString CallInEditorStr = Func.OriginalFunction->GetMetaData(TEXT("CallInEditor"));
			if (CallInEditorStr.Equals(TEXT("true"), ESearchCase::IgnoreCase))
				EntryNode->MetaData.bCallInEditor = true;
		}
	}

	CurrentFunctionEntryNode = EntryNode;
	CurrentOffsetToStatementIndex = &Func.OffsetToStatementIndex;

	// Function result node (if there's a return value)
	UK2Node_FunctionResult* ResultNode = nullptr;
	bool bHasReturnValue = false;
	if (Func.OriginalFunction)
	{
		for (TFieldIterator<FProperty> ParamIt(Func.OriginalFunction);
			ParamIt && ParamIt->HasAnyPropertyFlags(CPF_Parm); ++ParamIt)
		{
			if (ParamIt->HasAnyPropertyFlags(CPF_ReturnParm))
			{
				bHasReturnValue = true;
				break;
			}
		}
	}

	if (bHasReturnValue)
	{
		ResultNode = SpawnNode<UK2Node_FunctionResult>(
			FuncGraph, (Func.Statements.Num() + 2) * NodeSpacingX, 0);
	}

	UEdGraphPin* ExecOut = GetExecOut(EntryNode);
	int32 EmitX = NodeSpacingX;

	EmitStatements(BP, FuncGraph, Func.Statements,
		0, Func.Statements.Num(), ExecOut, EmitX, 0);

	// Connect deferred data wires
	for (const FDeferredWire& Wire : DeferredDataWires)
	{
		if (Wire.Source && Wire.Target)
		{
			TryConnect(Wire.Source, Wire.Target);
		}
	}
	DeferredDataWires.Empty();
}

// ---------------------------------------------------------------------------
// EmitStatements
// ---------------------------------------------------------------------------

UEdGraphPin* FGraphBuilder::EmitStatements(
	UBlueprint* BP,
	UEdGraph* Graph,
	const TArray<TSharedPtr<FDecompiledExpr>>& Statements,
	int32 StartIdx,
	int32 EndIdx,
	UEdGraphPin* IncomingExecPin,
	int32& InOutNodeX,
	int32 NodeY)
{
	UEdGraphPin* LastExecOut = IncomingExecPin;

	for (int32 i = StartIdx; i < EndIdx && i < Statements.Num(); ++i)
	{
		const TSharedPtr<FDecompiledExpr>& Stmt = Statements[i];
		if (!Stmt) continue;

		// ── Pending exec-pin from EX_PushExecutionFlow (Sequence Then-1) ─
		// When a Sequence node was created, its Then-1 pin was stored at the
		// bytecode offset of the code that should run after Then-0 completes.
		// Wire it as LastExecOut when we reach that offset.
		if (Stmt->StartOffset >= 0 && PendingExecAtOffset.Num() > 0)
		{
			if (UEdGraphPin** PendingPinPtr = PendingExecAtOffset.Find(Stmt->StartOffset))
			{
				UEdGraphPin* PendingPin = *PendingPinPtr;
				PendingExecAtOffset.Remove(Stmt->StartOffset);
				// If Then-0 path has already ended (LastExecOut == null), use Then-1
				// as the new incoming exec so subsequent nodes are wired correctly.
				if (!LastExecOut && PendingPin)
					LastExecOut = PendingPin;
			}
		}

		// Skip pure no-ops, jumps (handled structurally), tracepoints
		switch (Stmt->Token)
		{
		case EX_Nothing:
		case EX_Tracepoint:
		case EX_WireTracepoint:
		case EX_Breakpoint:
		case EX_ComputedJump:    // ubergraph dispatch — no visual node
		case EX_Jump:            // unconditional gotos handled by CFG structure
		case EX_Return:          // handled by FunctionResult wiring
		case EX_EndOfScript:
		case EX_InstrumentationEvent:
			continue;
		case EX_PopExecutionFlow: // end of Sequence Then-0 path; Then-1 fires at JumpTarget
			LastExecOut = nullptr;
			continue;
		default:
			break;
		}

		// LetValueOnPersistentFrame: parameter copy from event to persistent frame
		if (Stmt->Token == EX_LetValueOnPersistentFrame)
		{
			// Store in persistent frame map for later reference
			if (Stmt->PropertyRef && Stmt->Children.Num() > 0)
			{
				FString VarName = Stmt->PropertyRef->GetName();
				// Resolve the source expression and store output pin
				UEdGraphPin* SrcPin = ResolveDataExpr(Graph, Stmt->Children[0],
					nullptr, InOutNodeX, NodeY - DataNodeOffsetY);
				if (SrcPin)
				{
					PersistentFrameVarMap.Add(VarName, SrcPin);
				}
			}
			continue;
		}

		// ── EX_JumpIfNot: wire both Then and Else branches ────────────────
		// We handle this here (not in CreateNodeForExpr) because we need the
		// full Statements array and CurrentOffsetToStatementIndex to find the
		// else-block start and call EmitStatements recursively for each path.
		if (Stmt->Token == EX_JumpIfNot)
		{
			UK2Node_IfThenElse* BranchNode =
				SpawnNode<UK2Node_IfThenElse>(Graph, InOutNodeX, NodeY);

			if (LastExecOut) TryConnect(LastExecOut, GetExecIn(BranchNode));

			// Wire condition
			if (Stmt->Children.Num() > 0)
			{
				UEdGraphPin* CondPin = BranchNode->GetConditionPin();
				UEdGraphPin* SrcPin  = ResolveDataExpr(
					Graph, Stmt->Children[0], CondPin, InOutNodeX, NodeY - DataNodeOffsetY);
				if (SrcPin && CondPin)
					ForceConnect(Graph, SrcPin, CondPin, InOutNodeX, NodeY - DataNodeOffsetY);
			}

			UEdGraphPin* ThenPin = GetExecOut(BranchNode, 0); // "Then"
			UEdGraphPin* ElsePin = GetExecOut(BranchNode, 1); // "Else"
			InOutNodeX += NodeSpacingX;

			// Resolve the else-block start statement index from JumpTarget
			int32 ElseStartIdx = EndIdx; // fallback: no else block
			if (CurrentOffsetToStatementIndex)
			{
				const int32* FoundIdx =
					CurrentOffsetToStatementIndex->Find((int32)Stmt->JumpTarget);
				if (FoundIdx)
					ElseStartIdx = FMath::Clamp(*FoundIdx, i + 1, EndIdx);
			}

			// Emit then-block (statements from i+1 to ElseStartIdx)
			int32 ThenX = InOutNodeX;
			EmitStatements(BP, Graph, Statements, i + 1, ElseStartIdx, ThenPin, ThenX, NodeY);

			// Emit else-block (statements from ElseStartIdx to EndIdx)
			int32 ElseX = InOutNodeX;
			EmitStatements(BP, Graph, Statements, ElseStartIdx, EndIdx, ElsePin,
				ElseX, NodeY + DataNodeOffsetY);

			InOutNodeX = FMath::Max(ThenX, ElseX);

			// All remaining statements handled by the recursive calls — exit loop
			break;
		}

		UEdGraphPin* NodeExecOut = CreateNodeForExpr(
			BP, Graph, Stmt, LastExecOut, InOutNodeX, NodeY);

		if (NodeExecOut)
		{
			LastExecOut = NodeExecOut;
		}
	}

	return LastExecOut;
}

// ---------------------------------------------------------------------------
// CreateNodeForExpr — main dispatcher
// ---------------------------------------------------------------------------

UEdGraphPin* FGraphBuilder::CreateNodeForExpr(
	UBlueprint* BP,
	UEdGraph* Graph,
	const TSharedPtr<FDecompiledExpr>& Expr,
	UEdGraphPin* IncomingExecPin,
	int32& InOutNodeX,
	int32 NodeY)
{
	if (!Expr) return IncomingExecPin;

	int32 X = InOutNodeX;
	int32 Y = NodeY;
	UEdGraphPin* ExecOut = nullptr;

	switch (Expr->Token)
	{
	// ── Function Calls ────────────────────────────────────────────────────
	case EX_FinalFunction:
	case EX_LocalFinalFunction:
	case EX_CallMath:
	{
		UFunction* Func = Expr->FunctionRef;
		if (!Func)
		{
			InOutNodeX += NodeSpacingX;
			return IncomingExecPin;
		}

		UK2Node_CallFunction* CallNode = SpawnNode<UK2Node_CallFunction>(Graph, X, Y);
		CallNode->SetFromFunction(Func);
		CallNode->ReconstructNode();

		// Wire exec
		if (IncomingExecPin)
		{
			TryConnect(IncomingExecPin, GetExecIn(CallNode));
		}
		ExecOut = GetExecOut(CallNode);

		// Wire arguments
		int32 ArgIdx = 0;
		for (TFieldIterator<FProperty> ParamIt(Func);
			ParamIt && ParamIt->HasAnyPropertyFlags(CPF_Parm); ++ParamIt)
		{
			if (ParamIt->HasAnyPropertyFlags(CPF_ReturnParm)) continue;
			if (ParamIt->HasAnyPropertyFlags(CPF_OutParm) &&
				!ParamIt->HasAnyPropertyFlags(CPF_ReferenceParm)) continue;

			if (ArgIdx < Expr->Children.Num())
			{
				UEdGraphPin* ArgPin = FindPinByName(CallNode, ParamIt->GetFName(), EGPD_Input);
				if (ArgPin)
				{
					UEdGraphPin* SrcPin = ResolveDataExpr(
						Graph, Expr->Children[ArgIdx], ArgPin, X, Y - DataNodeOffsetY);
					if (SrcPin) ForceConnect(Graph, SrcPin, ArgPin, X, Y - DataNodeOffsetY);
				}
			}
			++ArgIdx;
		}

		// Cache return value pin in local var map if there's a result
		UEdGraphPin* ReturnPin = CallNode->GetReturnValuePin();
		if (ReturnPin)
		{
			// Store by function name for downstream consumption
			LocalVarToPinMap.Add(
				TEXT("__ret_") + Func->GetName(), ReturnPin);
		}

		InOutNodeX += NodeSpacingX;
		break;
	}

	case EX_VirtualFunction:
	case EX_LocalVirtualFunction:
	{
		// Resolve by name on the original class
		UFunction* Func = OriginalClass
			? OriginalClass->FindFunctionByName(Expr->NameValue)
			: nullptr;

		UK2Node_CallFunction* CallNode = SpawnNode<UK2Node_CallFunction>(Graph, X, Y);
		if (Func) CallNode->SetFromFunction(Func);
		else      CallNode->FunctionReference.SetExternalMember(Expr->NameValue, OriginalClass);
		CallNode->ReconstructNode();

		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(CallNode));
		ExecOut = GetExecOut(CallNode);

		if (Func)
		{
			int32 ArgIdx = 0;
			for (TFieldIterator<FProperty> ParamIt(Func);
				ParamIt && ParamIt->HasAnyPropertyFlags(CPF_Parm); ++ParamIt)
			{
				if (ParamIt->HasAnyPropertyFlags(CPF_ReturnParm)) continue;
				if (ArgIdx < Expr->Children.Num())
				{
					UEdGraphPin* ArgPin =
						FindPinByName(CallNode, ParamIt->GetFName(), EGPD_Input);
					if (ArgPin)
					{
						UEdGraphPin* SrcPin = ResolveDataExpr(
							Graph, Expr->Children[ArgIdx], ArgPin, X, Y - DataNodeOffsetY);
						if (SrcPin) ForceConnect(Graph, SrcPin, ArgPin, X, Y - DataNodeOffsetY);
					}
				}
				++ArgIdx;
			}
		}
		InOutNodeX += NodeSpacingX;
		break;
	}

	// ── Assignments ────────────────────────────────────────────────────────
	case EX_Let:
	case EX_LetObj:
	case EX_LetBool:
	case EX_LetDelegate:
	case EX_LetMulticastDelegate:
	case EX_LetWeakObjPtr:
	{
		if (Expr->Children.Num() < 2)
		{
			InOutNodeX += NodeSpacingX;
			return IncomingExecPin;
		}

		// Destination is Children[0], source is Children[1]
		const TSharedPtr<FDecompiledExpr>& DestExpr = Expr->Children[0];
		const TSharedPtr<FDecompiledExpr>& SrcExpr  = Expr->Children[1];

		FProperty* DestProp = nullptr;
		if (DestExpr->Token == EX_LocalVariable ||
			DestExpr->Token == EX_InstanceVariable ||
			DestExpr->Token == EX_DefaultVariable)
		{
			DestProp = DestExpr->PropertyRef;
		}
		else if (Expr->Token == EX_Let)
		{
			DestProp = Expr->PropertyRef;
		}

		if (!DestProp)
		{
			InOutNodeX += NodeSpacingX;
			return IncomingExecPin;
		}

		// Temp_ variable optimization: cache and don't emit a Set node
		FString VarName = DestProp->GetName();
		if (VarName.StartsWith(TEXT("Temp_")))
		{
			if (!MultiAssignedTempVars.Contains(VarName))
			{
				// Single-assign: cache as literal
				TempLiteralMap.Add(VarName, SrcExpr);
				LocalVarToPinMap.Remove(VarName);
			}
			else
			{
				// Multi-assign: create a VariableSet node for the first assign
				if (!MultiAssignedTempPins.Contains(VarName))
				{
					UEdGraphPin* SrcPin = ResolveDataExpr(
						Graph, SrcExpr, nullptr, X, Y - DataNodeOffsetY);
					if (SrcPin)
					{
						MultiAssignedTempPins.Add(VarName, SrcPin);
					}
				}
			}
			return IncomingExecPin;
		}

		// Regular variable — create a VariableSet node
		UK2Node_VariableSet* SetNode = SpawnNode<UK2Node_VariableSet>(Graph, X, Y);
		SetNode->VariableReference.SetSelfMember(DestProp->GetFName());
		SetNode->ReconstructNode();

		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(SetNode));
		ExecOut = GetExecOut(SetNode);

		// Wire value
		UEdGraphPin* ValPin = nullptr;
		for (UEdGraphPin* Pin : SetNode->Pins)
		{
			if (Pin && Pin->Direction == EGPD_Input
				&& Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
			{
				ValPin = Pin;
				break;
			}
		}

		if (ValPin)
		{
			UEdGraphPin* SrcPin = ResolveDataExpr(
				Graph, SrcExpr, ValPin, X, Y - DataNodeOffsetY);
			if (SrcPin) ForceConnect(Graph, SrcPin, ValPin, X, Y - DataNodeOffsetY);
		}

		// Cache the variable output for downstream reads
		UEdGraphPin* VarOutPin = nullptr;
		for (UEdGraphPin* Pin : SetNode->Pins)
		{
			if (Pin && Pin->Direction == EGPD_Output
				&& Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
			{
				VarOutPin = Pin;
				break;
			}
		}
		if (VarOutPin) LocalVarToPinMap.Add(VarName, VarOutPin);

		InOutNodeX += NodeSpacingX;
		break;
	}

	// ── Branch ────────────────────────────────────────────────────────────
	case EX_JumpIfNot:
	{
		UK2Node_IfThenElse* BranchNode = SpawnNode<UK2Node_IfThenElse>(Graph, X, Y);

		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(BranchNode));

		// Wire condition
		if (Expr->Children.Num() > 0)
		{
			UEdGraphPin* CondPin = BranchNode->GetConditionPin();
			UEdGraphPin* SrcPin = ResolveDataExpr(
				Graph, Expr->Children[0], CondPin, X, Y - DataNodeOffsetY);
			if (SrcPin && CondPin) ForceConnect(Graph, SrcPin, CondPin, X, Y - DataNodeOffsetY);
		}

		// True path: ExecOut index 0, False path: ExecOut index 1
		ExecOut = GetExecOut(BranchNode, 0); // "Then" pin
		// False path would be GetExecOut(BranchNode, 1) — "Else"
		InOutNodeX += NodeSpacingX;
		break;
	}

	// ── Sequence / Push+Pop ────────────────────────────────────────────────
	case EX_PushExecutionFlow:
	{
		UK2Node_ExecutionSequence* SeqNode =
			SpawnNode<UK2Node_ExecutionSequence>(Graph, X, Y);

		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(SeqNode));

		// Register Then-1 to be wired at the JumpTarget offset.
		// EmitStatements picks it up when it reaches that bytecode offset.
		UEdGraphPin* Then1Pin = GetExecOut(SeqNode, 1);
		if (Then1Pin && (int32)Expr->JumpTarget > 0)
			PendingExecAtOffset.Add((int32)Expr->JumpTarget, Then1Pin);

		ExecOut = GetExecOut(SeqNode, 0); // Then-0 is the immediate continuation
		InOutNodeX += NodeSpacingX;
		break;
	}

	// ── Dynamic Cast (EX_DynamicCast already in reader) ───────────────────
	case EX_DynamicCast:
	{
		if (!Expr->ClassRef || Expr->Children.Num() == 0)
		{
			InOutNodeX += NodeSpacingX;
			return IncomingExecPin;
		}

		UK2Node_DynamicCast* CastNode =
			CreateDynamicCastNode(Graph, Expr->ClassRef, Expr->Children[0], X, Y);

		if (CastNode)
		{
			if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(CastNode));
			ExecOut = GetExecOut(CastNode, 0); // cast success
		}
		InOutNodeX += NodeSpacingX;
		break;
	}

	// ── Interface/Meta Casts (new node additions) ─────────────────────────
	case EX_ObjToInterfaceCast:
	case EX_CrossInterfaceCast:
	case EX_InterfaceToObjCast:
	case EX_MetaCast:
	{
		if (!Expr->ClassRef || Expr->Children.Num() == 0)
		{
			InOutNodeX += NodeSpacingX;
			return IncomingExecPin;
		}

		UK2Node_DynamicCast* CastNode =
			CreateDynamicCastNode(Graph, Expr->ClassRef, Expr->Children[0], X, Y);

		if (CastNode)
		{
			if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(CastNode));
			ExecOut = GetExecOut(CastNode, 0);
		}
		InOutNodeX += NodeSpacingX;
		break;
	}

	// ── EX_Cast (UE5 primitive casts) → math library calls ────────────────
	case EX_Cast:
	{
		// Pass through — handle in ResolveDataExpr for data-flow
		// If reached as a statement, just emit the inner expression
		if (Expr->Children.Num() > 0)
		{
			return CreateNodeForExpr(BP, Graph, Expr->Children[0],
				IncomingExecPin, InOutNodeX, NodeY);
		}
		break;
	}

	// ── Make Array ────────────────────────────────────────────────────────
	case EX_SetArray:
	{
		// Children[0] = target array var, Children[1..] = elements
		int32 NumElems = FMath::Max(0, Expr->Children.Num() - 1);

		UK2Node_MakeArray* MakeNode = SpawnNode<UK2Node_MakeArray>(Graph, X, Y - DataNodeOffsetY);
		for (int32 i = 1; i < NumElems; ++i) MakeNode->AddInputPin();

		TArray<UEdGraphPin*> ElemPins;
		for (UEdGraphPin* Pin : MakeNode->Pins)
		{
			if (Pin && Pin->Direction == EGPD_Input)
				ElemPins.Add(Pin);
		}

		for (int32 i = 0; i < NumElems && i < ElemPins.Num(); ++i)
		{
			UEdGraphPin* SrcPin = ResolveDataExpr(
				Graph, Expr->Children[i + 1], ElemPins[i], X, Y - DataNodeOffsetY * 2);
			if (SrcPin) TryConnect(SrcPin, ElemPins[i]);
		}

		// Wire to target variable if Children[0] is a variable
		if (Expr->Children.Num() > 0 && Expr->Children[0]->PropertyRef)
		{
			FString VarName = Expr->Children[0]->PropertyRef->GetName();
			UEdGraphPin* OutPin = MakeNode->GetOutputPin();
			if (OutPin) LocalVarToPinMap.Add(VarName, OutPin);
		}

		// No exec wiring — MakeArray is pure
		return IncomingExecPin;
	}

	// ── Make Set (NEW) ─────────────────────────────────────────────────────
	case EX_SetSet:
	{
		int32 NumElems = FMath::Max(0, Expr->Children.Num() - 1);

		UK2Node_MakeSet* MakeNode = SpawnNode<UK2Node_MakeSet>(Graph, X, Y - DataNodeOffsetY);
		for (int32 i = 1; i < NumElems; ++i) MakeNode->AddInputPin();

		TArray<UEdGraphPin*> ElemPins;
		for (UEdGraphPin* Pin : MakeNode->Pins)
		{
			if (Pin && Pin->Direction == EGPD_Input)
				ElemPins.Add(Pin);
		}

		for (int32 i = 0; i < NumElems && i < ElemPins.Num(); ++i)
		{
			UEdGraphPin* SrcPin = ResolveDataExpr(
				Graph, Expr->Children[i + 1], ElemPins[i], X, Y - DataNodeOffsetY * 2);
			if (SrcPin) TryConnect(SrcPin, ElemPins[i]);
		}

		return IncomingExecPin;
	}

	// ── Make Map (NEW) ─────────────────────────────────────────────────────
	case EX_SetMap:
	{
		int32 NumPairs = (Expr->Children.Num() - 1) / 2;

		UK2Node_MakeMap* MakeNode = SpawnNode<UK2Node_MakeMap>(Graph, X, Y - DataNodeOffsetY);
		for (int32 i = 1; i < NumPairs; ++i)
		{
			MakeNode->AddInputPin();
			MakeNode->AddInputPin();
		}

		TArray<UEdGraphPin*> InputPins;
		for (UEdGraphPin* Pin : MakeNode->Pins)
		{
			if (Pin && Pin->Direction == EGPD_Input)
				InputPins.Add(Pin);
		}

		int32 ChildIdx = 1;
		int32 PinIdx = 0;
		while (ChildIdx + 1 < Expr->Children.Num() && PinIdx + 1 < InputPins.Num())
		{
			UEdGraphPin* KeyPin = InputPins[PinIdx++];
			UEdGraphPin* ValPin = InputPins[PinIdx++];

			UEdGraphPin* KeySrc = ResolveDataExpr(
				Graph, Expr->Children[ChildIdx++], KeyPin, X, Y - DataNodeOffsetY * 2);
			if (KeySrc) TryConnect(KeySrc, KeyPin);

			UEdGraphPin* ValSrc = ResolveDataExpr(
				Graph, Expr->Children[ChildIdx++], ValPin, X, Y - DataNodeOffsetY * 2);
			if (ValSrc) TryConnect(ValSrc, ValPin);
		}

		return IncomingExecPin;
	}

	// ── Struct Const → MakeStruct ─────────────────────────────────────────
	case EX_StructConst:
	{
		if (!Expr->StructRef)
		{
			return IncomingExecPin;
		}

		UK2Node_MakeStruct* MakeNode =
			SpawnNode<UK2Node_MakeStruct>(Graph, X, Y - DataNodeOffsetY);
		MakeNode->StructType = Expr->StructRef;
		MakeNode->ReconstructNode();

		// Wire member values
		int32 ChildIdx = 0;
		for (TFieldIterator<FProperty> MemberIt(Expr->StructRef); MemberIt; ++MemberIt)
		{
			if (ChildIdx >= Expr->Children.Num()) break;
			UEdGraphPin* MemberPin =
				FindPinByName(MakeNode, MemberIt->GetFName(), EGPD_Input);
			if (MemberPin)
			{
				UEdGraphPin* SrcPin = ResolveDataExpr(
					Graph, Expr->Children[ChildIdx], MemberPin, X, Y - DataNodeOffsetY * 2);
				if (SrcPin) TryConnect(SrcPin, MemberPin);
			}
			++ChildIdx;
		}

		return IncomingExecPin;
	}

	// ── Switch/Select ─────────────────────────────────────────────────────
	case EX_SwitchValue:
	{
		// Children: [0]=index, [1,3,5,...]=case values, [2,4,6,...]=results, last=default
		// Expr->IntValue = NumCases (stored by BytecodeReader)
		int32 NumCases = Expr->IntValue;

		UK2Node_Select* SelectNode = SpawnNode<UK2Node_Select>(Graph, X, Y);

		// Wire index (Children[0])
		UEdGraphPin* IndexPin = SelectNode->GetIndexPin();
		if (IndexPin && Expr->Children.Num() > 0)
		{
			UEdGraphPin* IdxSrc = ResolveDataExpr(
				Graph, Expr->Children[0], IndexPin, X, Y - DataNodeOffsetY);
			if (IdxSrc) TryConnect(IdxSrc, IndexPin);
		}

		// Helper: collect option input pins (non-exec, non-index)
		auto CollectOptionPins = [&]() -> TArray<UEdGraphPin*>
		{
			TArray<UEdGraphPin*> Pins;
			for (UEdGraphPin* P : SelectNode->Pins)
			{
				if (P && P->Direction == EGPD_Input
					&& P->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec
					&& (!IndexPin || P->PinName != IndexPin->PinName))
				{
					Pins.Add(P);
				}
			}
			return Pins;
		};

		// Ensure we have NumCases+1 option pins (cases + default).
		// UE 5.1: UK2Node_Select implements IK2Node_AddPinInterface → AddInputPin().
		// AddOptionPinToNode() was introduced in a later engine version.
		while (CollectOptionPins().Num() < NumCases + 1)
		{
			SelectNode->AddInputPin();
		}

		TArray<UEdGraphPin*> OptionPins = CollectOptionPins();

		// Wire result expressions (at indices 2, 4, 6, ...) to option pins
		// Layout: [0]=index, [1]=caseVal0, [2]=result0, [3]=caseVal1, [4]=result1, ...
		int32 OptionIdx = 0;
		for (int32 c = 0; c < NumCases && OptionIdx < OptionPins.Num(); ++c)
		{
			int32 ResultChildIdx = 2 + c * 2; // skip index + each (case,result) pair
			if (ResultChildIdx < Expr->Children.Num())
			{
				UEdGraphPin* Src = ResolveDataExpr(
					Graph, Expr->Children[ResultChildIdx], OptionPins[OptionIdx], X, Y - DataNodeOffsetY);
				if (Src) TryConnect(Src, OptionPins[OptionIdx]);
			}
			++OptionIdx;
		}

		// Wire default expression (last child) to the remaining option pin
		if (Expr->Children.Num() > 0 && OptionIdx < OptionPins.Num())
		{
			UEdGraphPin* Src = ResolveDataExpr(
				Graph, Expr->Children.Last(), OptionPins[OptionIdx], X, Y - DataNodeOffsetY);
			if (Src) TryConnect(Src, OptionPins[OptionIdx]);
		}

		// No exec pins on Select (it's pure)
		return IncomingExecPin;
	}

	// ── Delegate operations ───────────────────────────────────────────────
	case EX_BindDelegate:
	{
		// Bug 3 fix: wire Children[0] (delegate variable) and Children[1] (target object).
		UK2Node_AssignDelegate* AssignNode =
			SpawnNode<UK2Node_AssignDelegate>(Graph, X, Y);
		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(AssignNode));
		ExecOut = GetExecOut(AssignNode);

		// Children[0] = the delegate variable being assigned
		if (Expr->Children.Num() >= 1)
		{
			UEdGraphPin* DelegatePin = FindPinByName(AssignNode, TEXT("Delegate"), EGPD_Input);
			if (!DelegatePin)
			{
				for (UEdGraphPin* P : AssignNode->Pins)
				{
					if (P && P->Direction == EGPD_Input
						&& P->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
					{ DelegatePin = P; break; }
				}
			}
			if (DelegatePin)
			{
				UEdGraphPin* Src = ResolveDataExpr(Graph, Expr->Children[0], DelegatePin, X, Y - DataNodeOffsetY);
				if (Src) TryConnect(Src, DelegatePin);
			}
		}

		// Children[1] = the target object to bind to
		if (Expr->Children.Num() >= 2)
		{
			UEdGraphPin* ObjPin = FindPinByName(AssignNode, TEXT("Object"), EGPD_Input);
			if (ObjPin)
			{
				UEdGraphPin* Src = ResolveDataExpr(Graph, Expr->Children[1], ObjPin, X, Y - DataNodeOffsetY);
				if (Src) TryConnect(Src, ObjPin);
			}
		}

		InOutNodeX += NodeSpacingX;
		break;
	}

	case EX_AddMulticastDelegate:
	{
		UK2Node_AddDelegate* AddNode = SpawnNode<UK2Node_AddDelegate>(Graph, X, Y);
		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(AddNode));
		ExecOut = GetExecOut(AddNode);

		// Children[0] = target multicast delegate (the "self" / owner delegate)
		if (Expr->Children.Num() >= 1)
		{
			UEdGraphPin* DelPin = FindPinByName(AddNode, TEXT("self"), EGPD_Input);
			if (!DelPin)
			{
				for (UEdGraphPin* P : AddNode->Pins)
				{
					if (P && P->Direction == EGPD_Input
						&& P->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
					{ DelPin = P; break; }
				}
			}
			if (DelPin)
			{
				UEdGraphPin* Src = ResolveDataExpr(
					Graph, Expr->Children[0], DelPin, X, Y - DataNodeOffsetY);
				if (Src) TryConnect(Src, DelPin);
			}
		}

		// Children[1] = the delegate value to add
		if (Expr->Children.Num() >= 2)
		{
			UEdGraphPin* DelegatePin = FindPinByName(AddNode, TEXT("Delegate"), EGPD_Input);
			if (DelegatePin)
			{
				UEdGraphPin* Src = ResolveDataExpr(
					Graph, Expr->Children[1], DelegatePin, X, Y - DataNodeOffsetY);
				if (Src) TryConnect(Src, DelegatePin);
			}
		}
		InOutNodeX += NodeSpacingX;
		break;
	}

	case EX_RemoveMulticastDelegate:
	{
		UK2Node_RemoveDelegate* RemNode = SpawnNode<UK2Node_RemoveDelegate>(Graph, X, Y);
		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(RemNode));
		ExecOut = GetExecOut(RemNode);

		// Children[0] = target multicast delegate
		if (Expr->Children.Num() >= 1)
		{
			UEdGraphPin* DelPin = nullptr;
			for (UEdGraphPin* P : RemNode->Pins)
			{
				if (P && P->Direction == EGPD_Input
					&& P->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
				{ DelPin = P; break; }
			}
			if (DelPin)
			{
				UEdGraphPin* Src = ResolveDataExpr(
					Graph, Expr->Children[0], DelPin, X, Y - DataNodeOffsetY);
				if (Src) TryConnect(Src, DelPin);
			}
		}

		// Children[1] = the delegate value to remove
		if (Expr->Children.Num() >= 2)
		{
			UEdGraphPin* DelegatePin = FindPinByName(RemNode, TEXT("Delegate"), EGPD_Input);
			if (DelegatePin)
			{
				UEdGraphPin* Src = ResolveDataExpr(
					Graph, Expr->Children[1], DelegatePin, X, Y - DataNodeOffsetY);
				if (Src) TryConnect(Src, DelegatePin);
			}
		}
		InOutNodeX += NodeSpacingX;
		break;
	}

	case EX_ClearMulticastDelegate:
	{
		UK2Node_ClearDelegate* ClrNode = SpawnNode<UK2Node_ClearDelegate>(Graph, X, Y);
		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(ClrNode));
		ExecOut = GetExecOut(ClrNode);
		InOutNodeX += NodeSpacingX;
		break;
	}

	case EX_CallMulticastDelegate:
	{
		// Bug 4 fix: wire Children[0] (delegate target) and Children[1..N] (arguments).
		// Engine format: FuncPtr (signature) + DelegateExpr + args until EX_EndFunctionParms.
		UK2Node_CallDelegate* CallDelNode = SpawnNode<UK2Node_CallDelegate>(Graph, X, Y);
		if (Expr->FunctionRef)
		{
			// UK2Node_CallDelegate does not have SetFromFunction; wire up via
			// the delegate member reference so the node reconstructs correctly.
			CallDelNode->DelegateReference.SetExternalMember(
				Expr->FunctionRef->GetFName(), Expr->FunctionRef->GetOwnerClass());
			CallDelNode->ReconstructNode();
		}
		if (IncomingExecPin) TryConnect(IncomingExecPin, GetExecIn(CallDelNode));
		ExecOut = GetExecOut(CallDelNode);

		// Children[0] = delegate target object expression
		if (Expr->Children.Num() >= 1)
		{
			UEdGraphPin* TargetPin = FindPinByName(CallDelNode, TEXT("self"), EGPD_Input);
			if (!TargetPin)
			{
				for (UEdGraphPin* P : CallDelNode->Pins)
				{
					if (P && P->Direction == EGPD_Input
						&& P->PinType.PinCategory == UEdGraphSchema_K2::PC_MCDelegate)
					{ TargetPin = P; break; }
				}
			}
			if (TargetPin)
			{
				UEdGraphPin* Src = ResolveDataExpr(Graph, Expr->Children[0], TargetPin, X, Y - DataNodeOffsetY);
				if (Src) TryConnect(Src, TargetPin);
			}
		}

		// Children[1..N] = call arguments (matched by position to function params)
		if (Expr->FunctionRef && Expr->Children.Num() > 1)
		{
			int32 ArgIdx = 1; // skip Children[0] (delegate target)
			for (TFieldIterator<FProperty> ParamIt(Expr->FunctionRef);
				ParamIt && ParamIt->HasAnyPropertyFlags(CPF_Parm); ++ParamIt)
			{
				if (ParamIt->HasAnyPropertyFlags(CPF_ReturnParm)) continue;
				if (ArgIdx >= Expr->Children.Num()) break;

				UEdGraphPin* ArgPin = FindPinByName(CallDelNode, ParamIt->GetFName(), EGPD_Input);
				if (ArgPin)
				{
					UEdGraphPin* Src = ResolveDataExpr(
						Graph, Expr->Children[ArgIdx], ArgPin, X, Y - DataNodeOffsetY);
					if (Src) TryConnect(Src, ArgPin);
				}
				++ArgIdx;
			}
		}

		InOutNodeX += NodeSpacingX;
		break;
	}

	// ── Array Get By Ref (NEW) ────────────────────────────────────────────
	case EX_ArrayGetByRef:
	{
		if (Expr->Children.Num() < 2)
		{
			return IncomingExecPin;
		}

		UK2Node_GetArrayItem* GetNode = SpawnNode<UK2Node_GetArrayItem>(Graph, X, Y - DataNodeOffsetY);

		UEdGraphPin* ArrayPin = GetNode->GetTargetArrayPin();
		if (ArrayPin)
		{
			UEdGraphPin* ArrSrc = ResolveDataExpr(
				Graph, Expr->Children[0], ArrayPin, X, Y - DataNodeOffsetY * 2);
			if (ArrSrc) TryConnect(ArrSrc, ArrayPin);
		}

		UEdGraphPin* IndexPin = GetNode->GetIndexPin();
		if (IndexPin)
		{
			UEdGraphPin* IdxSrc = ResolveDataExpr(
				Graph, Expr->Children[1], IndexPin, X, Y - DataNodeOffsetY * 2);
			if (IdxSrc) TryConnect(IdxSrc, IndexPin);
		}

		return IncomingExecPin; // pure node, no exec
	}

	// ── Interface context: passthrough wrapper ────────────────────────────
	case EX_InterfaceContext:   // 0x51
	{
		if (Expr->Children.Num() > 0)
			return CreateNodeForExpr(BP, Graph, Expr->Children[0],
				IncomingExecPin, InOutNodeX, NodeY);
		break;
	}

	// ── Const collection literals surfacing as statements (rare) ─────────
	case EX_ArrayConst:  // 0x65
	case EX_SetConst:    // 0x3D
	case EX_MapConst:    // 0x3F
	{
		// These are data-producing expressions; route to ResolveDataExpr.
		// No exec wiring — pure nodes.
		ResolveDataExpr(Graph, Expr, nullptr, X, Y - DataNodeOffsetY);
		return IncomingExecPin;
	}

	// ── EX_ClassContext: static/CDO function call ─────────────────────────
	case EX_ClassContext:
	{
		// Missing 5 fix: EX_ClassContext wraps static/const class function calls.
		// Children[0] = class expression, Children[1] = inner operation (e.g. EX_FinalFunction).
		if (Expr->Children.Num() > 1)
			return CreateNodeForExpr(BP, Graph, Expr->Children[1], IncomingExecPin, InOutNodeX, NodeY);
		else if (Expr->Children.Num() == 1)
			return CreateNodeForExpr(BP, Graph, Expr->Children[0], IncomingExecPin, InOutNodeX, NodeY);
		break;
	}

	// ── EX_Skip: optional parameter default value ─────────────────────────
	case EX_Skip:
	{
		// Missing 4 fix: EX_Skip marks a parameter slot with an explicit default.
		// Resolve the inner default expression and pass it through.
		if (Expr->Children.Num() > 0)
			return CreateNodeForExpr(BP, Graph, Expr->Children[0], IncomingExecPin, InOutNodeX, NodeY);
		return IncomingExecPin;
	}

	// ── Context: call on another object ───────────────────────────────────
	case EX_Context:
	case EX_Context_FailSilent:
	{
		// Propagate context object so inner function-call nodes can wire it
		// to their "Target" input pin (fixes method calls on non-self objects).
		if (Expr->Children.Num() > 0)
		{
			PendingContextObject = Expr->ContextObject;
			UEdGraphPin* Result = CreateNodeForExpr(BP, Graph, Expr->Children[0],
				IncomingExecPin, InOutNodeX, NodeY);
			PendingContextObject.Reset(); // clear in case inner handler didn't consume it
			return Result;
		}
		break;
	}

	default:
		UE_LOG(LogGraphBuilder, Verbose,
			TEXT("CreateNodeForExpr: unhandled token 0x%02X — skipping"),
			(uint8)Expr->Token);
		break;
	}

	return ExecOut ? ExecOut : IncomingExecPin;
}

// ---------------------------------------------------------------------------
// ResolveDataExpr — convert a data expression to an output pin
// ---------------------------------------------------------------------------

UEdGraphPin* FGraphBuilder::ResolveDataExpr(
	UEdGraph* Graph,
	const TSharedPtr<FDecompiledExpr>& Expr,
	UEdGraphPin* ContextPin,
	int32 NodeX,
	int32 NodeY)
{
	if (!Expr) return nullptr;

	switch (Expr->Token)
	{
	// ── Self ──────────────────────────────────────────────────────────────
	case EX_Self:
	{
		if (CurrentFunctionEntryNode)
		{
			return FindPinByName(CurrentFunctionEntryNode, TEXT("self"), EGPD_Output);
		}
		return nullptr;
	}

	// ── Literals → set pin default value ─────────────────────────────────
	case EX_IntConst:
	case EX_IntZero:
	case EX_IntOne:
	case EX_IntConstByte:
		if (ContextPin) ContextPin->DefaultValue = Expr->GetLiteralAsString();
		return nullptr;

	case EX_ByteConst:
		if (ContextPin) ContextPin->DefaultValue = Expr->GetLiteralAsString();
		return nullptr;

	case EX_Int64Const:
	case EX_UInt64Const:
		if (ContextPin) ContextPin->DefaultValue = Expr->GetLiteralAsString();
		return nullptr;

	case EX_FloatConst:
		if (ContextPin) ContextPin->DefaultValue = FString::SanitizeFloat(Expr->FloatValue);
		return nullptr;

	case EX_DoubleConst:
		if (ContextPin) ContextPin->DefaultValue = FString::SanitizeFloat(Expr->DoubleValue);
		return nullptr;

	case EX_True:
		if (ContextPin) ContextPin->DefaultValue = TEXT("true");
		return nullptr;

	case EX_False:
		if (ContextPin) ContextPin->DefaultValue = TEXT("false");
		return nullptr;

	case EX_StringConst:
	case EX_UnicodeStringConst:
		if (ContextPin) ContextPin->DefaultValue = Expr->StringValue;
		return nullptr;

	case EX_NameConst:
		if (ContextPin) ContextPin->DefaultValue = Expr->NameValue.ToString();
		return nullptr;

	case EX_VectorConst:
	{
		if (ContextPin)
		{
			ContextPin->DefaultValue = FString::Printf(TEXT("X=%f Y=%f Z=%f"),
				Expr->VectorValue.X, Expr->VectorValue.Y, Expr->VectorValue.Z);
		}
		return nullptr;
	}

	case EX_RotationConst:
	{
		if (ContextPin)
		{
			ContextPin->DefaultValue = FString::Printf(TEXT("P=%f Y=%f R=%f"),
				Expr->RotatorValue.Pitch, Expr->RotatorValue.Yaw, Expr->RotatorValue.Roll);
		}
		return nullptr;
	}

	case EX_NoObject:
	case EX_NoInterface:
		if (ContextPin) ContextPin->DefaultObject = nullptr;
		return nullptr;

	case EX_ObjectConst:
		if (ContextPin && Expr->ObjectRef)
		{
			ContextPin->DefaultObject = Expr->ObjectRef;
		}
		return nullptr;

	case EX_TextConst:
	{
		// EBlueprintTextLiteralType (now fixed in BytecodeReader):
		//   0=Empty, 1=LocalizedText (3 children), 2=InvariantText (1 child),
		//   3=LiteralString (1 child), 4=StringTableEntry (ObjectRef + 2 children)
		if (Expr->ByteValue == 0) // Empty
		{
			if (ContextPin) ContextPin->DefaultValue = TEXT("");
			return nullptr;
		}
		// Kinds 1/2/3 all have at least one string child — resolve it as the text value
		if ((Expr->ByteValue == 1 || Expr->ByteValue == 2 || Expr->ByteValue == 3)
			&& Expr->Children.Num() > 0)
		{
			return ResolveDataExpr(Graph, Expr->Children[0], ContextPin, NodeX, NodeY);
		}
		// Kind 4 = StringTableEntry — cannot trivially resolve as a pin default
		return nullptr;
	}

	// ── Variable reads ────────────────────────────────────────────────────
	case EX_LocalVariable:
	case EX_InstanceVariable:
	case EX_DefaultVariable:
	case EX_LocalOutVariable:
	{
		FProperty* Prop = Expr->PropertyRef;
		if (!Prop) return nullptr;

		FString VarName = Prop->GetName();

		// Check temp literal cache
		if (TSharedPtr<FDecompiledExpr>* CachedLiteral = TempLiteralMap.Find(VarName))
		{
			return ResolveDataExpr(Graph, *CachedLiteral, ContextPin, NodeX, NodeY);
		}

		// Check local pin cache
		if (UEdGraphPin** CachedPin = LocalVarToPinMap.Find(VarName))
		{
			return *CachedPin;
		}

		// Check persistent frame cache
		if (UEdGraphPin** PersistPin = PersistentFrameVarMap.Find(VarName))
		{
			return *PersistPin;
		}

		// Create a VariableGet node
		UK2Node_VariableGet* GetNode = SpawnNode<UK2Node_VariableGet>(Graph, NodeX, NodeY);
		GetNode->VariableReference.SetSelfMember(Prop->GetFName());
		GetNode->ReconstructNode();

		UEdGraphPin* OutPin = nullptr;
		for (UEdGraphPin* Pin : GetNode->Pins)
		{
			if (Pin && Pin->Direction == EGPD_Output
				&& Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
			{
				OutPin = Pin;
				break;
			}
		}

		if (OutPin) LocalVarToPinMap.Add(VarName, OutPin);
		return OutPin;
	}

	// ── Function calls (pure / math) ──────────────────────────────────────
	case EX_FinalFunction:
	case EX_LocalFinalFunction:
	case EX_CallMath:
	{
		UFunction* Func = Expr->FunctionRef;
		if (!Func) return nullptr;

		UK2Node_CallFunction* CallNode = SpawnNode<UK2Node_CallFunction>(Graph, NodeX, NodeY);
		CallNode->SetFromFunction(Func);
		CallNode->ReconstructNode();

		int32 ArgIdx = 0;
		for (TFieldIterator<FProperty> ParamIt(Func);
			ParamIt && ParamIt->HasAnyPropertyFlags(CPF_Parm); ++ParamIt)
		{
			if (ParamIt->HasAnyPropertyFlags(CPF_ReturnParm)) continue;
			if (ArgIdx < Expr->Children.Num())
			{
				UEdGraphPin* ArgPin = FindPinByName(CallNode, ParamIt->GetFName(), EGPD_Input);
				if (ArgPin)
				{
					UEdGraphPin* SrcPin = ResolveDataExpr(
						Graph, Expr->Children[ArgIdx], ArgPin, NodeX, NodeY - DataNodeOffsetY);
					if (SrcPin) TryConnect(SrcPin, ArgPin);
				}
			}
			++ArgIdx;
		}

		return CallNode->GetReturnValuePin();
	}

	case EX_VirtualFunction:
	case EX_LocalVirtualFunction:
	{
		UFunction* Func = OriginalClass
			? OriginalClass->FindFunctionByName(Expr->NameValue)
			: nullptr;

		UK2Node_CallFunction* CallNode = SpawnNode<UK2Node_CallFunction>(Graph, NodeX, NodeY);
		if (Func) CallNode->SetFromFunction(Func);
		else CallNode->FunctionReference.SetExternalMember(Expr->NameValue, OriginalClass);
		CallNode->ReconstructNode();

		return CallNode->GetReturnValuePin();
	}

	// ── EX_Cast: primitive type conversion ────────────────────────────────
	case EX_Cast:
	{
		// Map ECastToken (UE5 Script.h) to KismetMathLibrary conversion function.
		// Real UE5 ECastToken enum (confirmed against Script.h):
		//   CST_ObjectToInterface=0x00, CST_ObjectToBool=0x01, CST_InterfaceToBool=0x02,
		//   CST_DoubleToFloat=0x03, CST_FloatToDouble=0x04.
		// The old values (0x28-0x35) were UE4 ECastToken remnants that never match real bytecode.
		static TMap<uint8, FName> CastFuncMap = {
			{ 0x00, TEXT("Conv_ObjectToInterface") },
			{ 0x01, TEXT("Conv_ObjectToBool")      },
			{ 0x02, TEXT("Conv_InterfaceToBool")   },
			{ 0x03, TEXT("Conv_DoubleToFloat")     },
			{ 0x04, TEXT("Conv_FloatToDouble")     },
		};

		uint8 CastType = Expr->ByteValue;
		TSharedPtr<FDecompiledExpr> InnerExpr = Expr->Children.Num() > 0
			? Expr->Children[0] : nullptr;

		if (const FName* FuncName = CastFuncMap.Find(CastType))
		{
			UClass* MathLib = FindObject<UClass>(nullptr,
				TEXT("/Script/Engine.KismetMathLibrary"), true);
			UFunction* ConvFunc = MathLib
				? MathLib->FindFunctionByName(*FuncName) : nullptr;

			if (ConvFunc)
			{
				UK2Node_CallFunction* CallNode =
					SpawnNode<UK2Node_CallFunction>(Graph, NodeX, NodeY);
				CallNode->SetFromFunction(ConvFunc);
				CallNode->ReconstructNode();

				if (InnerExpr)
				{
					for (TFieldIterator<FProperty> ParamIt(ConvFunc);
						ParamIt && ParamIt->HasAnyPropertyFlags(CPF_Parm); ++ParamIt)
					{
						if (!ParamIt->HasAnyPropertyFlags(CPF_ReturnParm | CPF_OutParm))
						{
							UEdGraphPin* ArgPin =
								FindPinByName(CallNode, ParamIt->GetFName(), EGPD_Input);
							if (ArgPin)
							{
								UEdGraphPin* SrcPin = ResolveDataExpr(
									Graph, InnerExpr, ArgPin, NodeX, NodeY - DataNodeOffsetY);
								if (SrcPin) TryConnect(SrcPin, ArgPin);
							}
							break;
						}
					}
				}
				return CallNode->GetReturnValuePin();
			}
		}

		// Passthrough: just resolve the inner expression
		if (InnerExpr) return ResolveDataExpr(Graph, InnerExpr, ContextPin, NodeX, NodeY);
		return nullptr;
	}

	// ── Context: member access on another object ──────────────────────────
	case EX_Context:
	case EX_Context_FailSilent:
	{
		if (Expr->Children.Num() > 0)
		{
			PendingContextObject = Expr->ContextObject;
			UEdGraphPin* Result = ResolveDataExpr(Graph, Expr->Children[0], ContextPin, NodeX, NodeY);
			PendingContextObject.Reset();
			return Result;
		}
		return nullptr;
	}

	// ── Dynamic/Interface cast as data expression ─────────────────────────
	case EX_DynamicCast:
	case EX_ObjToInterfaceCast:
	case EX_CrossInterfaceCast:
	case EX_InterfaceToObjCast:
	case EX_MetaCast:
	{
		if (!Expr->ClassRef || Expr->Children.Num() == 0) return nullptr;

		UK2Node_DynamicCast* CastNode =
			CreateDynamicCastNode(Graph, Expr->ClassRef, Expr->Children[0], NodeX, NodeY);

		return CastNode ? CastNode->GetCastResultPin() : nullptr;
	}

	// ── Array Get By Ref as data ──────────────────────────────────────────
	case EX_ArrayGetByRef:
	{
		if (Expr->Children.Num() < 2) return nullptr;

		UK2Node_GetArrayItem* GetNode =
			SpawnNode<UK2Node_GetArrayItem>(Graph, NodeX, NodeY);

		UEdGraphPin* ArrayPin = GetNode->GetTargetArrayPin();
		if (ArrayPin)
		{
			UEdGraphPin* Src = ResolveDataExpr(
				Graph, Expr->Children[0], ArrayPin, NodeX, NodeY - DataNodeOffsetY);
			if (Src) TryConnect(Src, ArrayPin);
		}
		UEdGraphPin* IndexPin = GetNode->GetIndexPin();
		if (IndexPin)
		{
			UEdGraphPin* Src = ResolveDataExpr(
				Graph, Expr->Children[1], IndexPin, NodeX, NodeY - DataNodeOffsetY);
			if (Src) TryConnect(Src, IndexPin);
		}
		return GetNode->GetResultPin();
	}

	// ── Instance delegate (standalone) ───────────────────────────────────
	case EX_InstanceDelegate:
	{
		UK2Node_CreateDelegate* CreateDel =
			SpawnNode<UK2Node_CreateDelegate>(Graph, NodeX, NodeY);
		CreateDel->SelectedFunctionName = Expr->NameValue;
		CreateDel->ReconstructNode();
		return FindPinByName(CreateDel, TEXT("OutputDelegate"), EGPD_Output);
	}

	// ── EX_SoftObjectConst: soft object/class reference literal ──────────
	case EX_SoftObjectConst:   // 0x67
	{
		// Children[0] is an EX_StringConst (or Unicode variant) holding the asset path.
		if (Expr->Children.Num() > 0 && ContextPin)
		{
			const TSharedPtr<FDecompiledExpr>& PathExpr = Expr->Children[0];
			if (PathExpr && (PathExpr->Token == EX_StringConst ||
			                 PathExpr->Token == EX_UnicodeStringConst))
			{
				ContextPin->DefaultValue = PathExpr->StringValue;
			}
			else if (PathExpr)
			{
				ResolveDataExpr(Graph, PathExpr, ContextPin, NodeX, NodeY);
			}
		}
		return nullptr;
	}

	// ── EX_ClassSparseDataVariable / EX_PropertyConst: property-as-var ───
	// Same semantics as EX_InstanceVariable — create a VariableGet node.
	case EX_ClassSparseDataVariable:  // 0x6C
	case EX_PropertyConst:            // 0x33
	{
		FProperty* Prop = Expr->PropertyRef;
		if (!Prop) return nullptr;

		const FString VarName = Prop->GetName();

		if (TSharedPtr<FDecompiledExpr>* CachedLit = TempLiteralMap.Find(VarName))
			return ResolveDataExpr(Graph, *CachedLit, ContextPin, NodeX, NodeY);
		if (UEdGraphPin** CachedPin = LocalVarToPinMap.Find(VarName))
			return *CachedPin;

		UK2Node_VariableGet* GetNode = SpawnNode<UK2Node_VariableGet>(Graph, NodeX, NodeY);
		GetNode->VariableReference.SetSelfMember(Prop->GetFName());
		GetNode->ReconstructNode();

		UEdGraphPin* OutPin = nullptr;
		for (UEdGraphPin* Pin : GetNode->Pins)
		{
			if (Pin && Pin->Direction == EGPD_Output
				&& Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
			{ OutPin = Pin; break; }
		}
		if (OutPin) LocalVarToPinMap.Add(VarName, OutPin);
		return OutPin;
	}

	// ── EX_StructMemberContext: access a member field of a struct value ───
	case EX_StructMemberContext:   // 0x42
	{
		FProperty* MemberProp = Expr->PropertyRef;
		if (!MemberProp || Expr->Children.Num() == 0) return nullptr;

		UScriptStruct* OwnerStruct = MemberProp->GetOwner<UScriptStruct>();
		if (!OwnerStruct)
		{
			// Fallback: resolve owner expression only
			return ResolveDataExpr(Graph, Expr->Children[0], ContextPin, NodeX, NodeY);
		}

		// Create a BreakStruct node for the owning struct type
		UK2Node_BreakStruct* BreakNode = SpawnNode<UK2Node_BreakStruct>(Graph, NodeX, NodeY);
		BreakNode->StructType = OwnerStruct;
		BreakNode->bMadeAfterOverridePinRemoval = true;
		BreakNode->ReconstructNode();

		// Wire the struct source expression to the struct input pin
		UEdGraphPin* StructInputPin = nullptr;
		for (UEdGraphPin* Pin : BreakNode->Pins)
		{
			if (Pin && Pin->Direction == EGPD_Input
				&& Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
			{ StructInputPin = Pin; break; }
		}
		if (StructInputPin)
		{
			UEdGraphPin* SrcPin = ResolveDataExpr(
				Graph, Expr->Children[0], StructInputPin, NodeX, NodeY - DataNodeOffsetY);
			if (SrcPin) TryConnect(SrcPin, StructInputPin);
		}

		// Return the output pin for the requested member
		return FindPinByName(BreakNode, MemberProp->GetFName(), EGPD_Output);
	}

	// ── EX_InterfaceContext: interface wrapper passthrough ────────────────
	case EX_InterfaceContext:   // 0x51
	{
		if (Expr->Children.Num() > 0)
			return ResolveDataExpr(Graph, Expr->Children[0], ContextPin, NodeX, NodeY);
		return nullptr;
	}

	// ── EX_ClassContext: static/CDO call as data expression ─────────────
	case EX_ClassContext:
	{
		// Missing 5 fix (data path): forward to the inner operation.
		// Children[0] = class expr, Children[1] = inner operation.
		if (Expr->Children.Num() > 1)
			return ResolveDataExpr(Graph, Expr->Children[1], ContextPin, NodeX, NodeY);
		else if (Expr->Children.Num() == 1)
			return ResolveDataExpr(Graph, Expr->Children[0], ContextPin, NodeX, NodeY);
		return nullptr;
	}

	// ── EX_Skip: optional parameter default value ─────────────────────────
	case EX_Skip:
	{
		// Missing 4 fix (data path): resolve the inner default expression.
		if (Expr->Children.Num() > 0)
			return ResolveDataExpr(Graph, Expr->Children[0], ContextPin, NodeX, NodeY);
		return nullptr;
	}

	// ── EX_FieldPathConst: FFieldPath constant — passthrough ─────────────
	case EX_FieldPathConst:    // 0x6D
	{
		if (Expr->Children.Num() > 0)
			return ResolveDataExpr(Graph, Expr->Children[0], ContextPin, NodeX, NodeY);
		return nullptr;
	}

	// ── EX_ArrayConst: const array literal → UK2Node_MakeArray ───────────
	case EX_ArrayConst:   // 0x65
	{
		int32 NumElems = Expr->Children.Num();
		UK2Node_MakeArray* MakeNode = SpawnNode<UK2Node_MakeArray>(Graph, NodeX, NodeY);
		for (int32 i = 1; i < NumElems; ++i) MakeNode->AddInputPin();
		MakeNode->ReconstructNode();

		TArray<UEdGraphPin*> ElemPins;
		for (UEdGraphPin* Pin : MakeNode->Pins)
			if (Pin && Pin->Direction == EGPD_Input) ElemPins.Add(Pin);

		for (int32 i = 0; i < NumElems && i < ElemPins.Num(); ++i)
		{
			UEdGraphPin* SrcPin = ResolveDataExpr(
				Graph, Expr->Children[i], ElemPins[i], NodeX, NodeY - DataNodeOffsetY);
			if (SrcPin) TryConnect(SrcPin, ElemPins[i]);
		}
		return MakeNode->GetOutputPin();
	}

	// ── EX_SetConst: const set literal → UK2Node_MakeSet ─────────────────
	case EX_SetConst:    // 0x3D
	{
		int32 NumElems = Expr->Children.Num();
		UK2Node_MakeSet* MakeNode = SpawnNode<UK2Node_MakeSet>(Graph, NodeX, NodeY);
		for (int32 i = 1; i < NumElems; ++i) MakeNode->AddInputPin();
		MakeNode->ReconstructNode();

		TArray<UEdGraphPin*> ElemPins;
		for (UEdGraphPin* Pin : MakeNode->Pins)
			if (Pin && Pin->Direction == EGPD_Input) ElemPins.Add(Pin);

		for (int32 i = 0; i < NumElems && i < ElemPins.Num(); ++i)
		{
			UEdGraphPin* SrcPin = ResolveDataExpr(
				Graph, Expr->Children[i], ElemPins[i], NodeX, NodeY - DataNodeOffsetY);
			if (SrcPin) TryConnect(SrcPin, ElemPins[i]);
		}
		UEdGraphPin* OutPin = nullptr;
		for (UEdGraphPin* Pin : MakeNode->Pins)
			if (Pin && Pin->Direction == EGPD_Output) { OutPin = Pin; break; }
		return OutPin;
	}

	// ── EX_MapConst: const map literal → UK2Node_MakeMap ─────────────────
	case EX_MapConst:    // 0x3F
	{
		int32 NumPairs = Expr->Children.Num() / 2;
		UK2Node_MakeMap* MakeNode = SpawnNode<UK2Node_MakeMap>(Graph, NodeX, NodeY);
		for (int32 i = 1; i < NumPairs; ++i)
		{
			MakeNode->AddInputPin(); // key
			MakeNode->AddInputPin(); // value
		}
		MakeNode->ReconstructNode();

		TArray<UEdGraphPin*> InputPins;
		for (UEdGraphPin* Pin : MakeNode->Pins)
			if (Pin && Pin->Direction == EGPD_Input) InputPins.Add(Pin);

		int32 ChildIdx = 0, PinIdx = 0;
		while (ChildIdx + 1 < Expr->Children.Num() && PinIdx + 1 < InputPins.Num())
		{
			UEdGraphPin* KeyPin = InputPins[PinIdx++];
			UEdGraphPin* ValPin = InputPins[PinIdx++];
			UEdGraphPin* KSrc = ResolveDataExpr(
				Graph, Expr->Children[ChildIdx++], KeyPin, NodeX, NodeY - DataNodeOffsetY);
			if (KSrc) TryConnect(KSrc, KeyPin);
			UEdGraphPin* VSrc = ResolveDataExpr(
				Graph, Expr->Children[ChildIdx++], ValPin, NodeX, NodeY - DataNodeOffsetY);
			if (VSrc) TryConnect(VSrc, ValPin);
		}
		UEdGraphPin* OutPin = nullptr;
		for (UEdGraphPin* Pin : MakeNode->Pins)
			if (Pin && Pin->Direction == EGPD_Output) { OutPin = Pin; break; }
		return OutPin;
	}

	default:
		// EX_Vector3fConst (0x41)
		if ((uint8)Expr->Token == 0x41)
		{
			if (ContextPin)
			{
				ContextPin->DefaultValue = FString::Printf(TEXT("X=%f Y=%f Z=%f"),
					(double)Expr->Vector3fValue.X,
					(double)Expr->Vector3fValue.Y,
					(double)Expr->Vector3fValue.Z);
			}
			return nullptr;
		}

		UE_LOG(LogGraphBuilder, Verbose,
			TEXT("ResolveDataExpr: unhandled token 0x%02X"),
			(uint8)Expr->Token);
		return nullptr;
	}
}

// ---------------------------------------------------------------------------
// Pin connection helpers
// ---------------------------------------------------------------------------

bool FGraphBuilder::TryConnect(UEdGraphPin* A, UEdGraphPin* B)
{
	if (!A || !B) return false;
	if (A->Direction == EGPD_Output && B->Direction == EGPD_Input)
	{
		const UEdGraphSchema* Schema = A->GetOwningNode()->GetGraph()->GetSchema();
		if (Schema)
		{
			FPinConnectionResponse Response = Schema->CanCreateConnection(A, B);
			if (Response.Response != CONNECT_RESPONSE_DISALLOW)
			{
				return Schema->TryCreateConnection(A, B);
			}
		}
	}
	else if (A->Direction == EGPD_Input && B->Direction == EGPD_Output)
	{
		return TryConnect(B, A);
	}
	return false;
}

void FGraphBuilder::ForceConnect(UEdGraph* Graph,
	UEdGraphPin* A, UEdGraphPin* B, int32 NodeX, int32 NodeY)
{
	if (!A || !B) return;

	if (TryConnect(A, B)) return;

	// Ensure output → input order
	UEdGraphPin* OutPin = (A->Direction == EGPD_Output) ? A : B;
	UEdGraphPin* InPin  = (A->Direction == EGPD_Input)  ? A : B;

	if (!OutPin || !InPin) return;

	// Object type mismatch: insert dynamic cast
	if (OutPin->PinType.PinCategory == UEdGraphSchema_K2::PC_Object &&
		InPin->PinType.PinCategory  == UEdGraphSchema_K2::PC_Object)
	{
		UClass* TargetClass = Cast<UClass>(InPin->PinType.PinSubCategoryObject.Get());
		if (TargetClass)
		{
			auto FakeExpr = MakeShared<FDecompiledExpr>();
			FakeExpr->Token = EX_Nothing; // won't be read
			UK2Node_DynamicCast* CastNode =
				CreateDynamicCastNode(Graph, TargetClass, FakeExpr, NodeX, NodeY);
			if (CastNode)
			{
				UEdGraphPin* CastIn = CastNode->GetCastSourcePin();
				UEdGraphPin* CastOut = CastNode->GetCastResultPin();
				if (CastIn && CastOut)
				{
					OutPin->MakeLinkTo(CastIn);
					CastOut->MakeLinkTo(InPin);
					return;
				}
			}
		}
	}

	// Final fallback: force the link
	OutPin->MakeLinkTo(InPin);
}

UK2Node_DynamicCast* FGraphBuilder::CreateDynamicCastNode(
	UEdGraph* Graph,
	UClass* TargetType,
	const TSharedPtr<FDecompiledExpr>& SourceExpr,
	int32 NodeX, int32 NodeY)
{
	if (!TargetType) return nullptr;

	UK2Node_DynamicCast* CastNode = SpawnNode<UK2Node_DynamicCast>(Graph, NodeX, NodeY);
	CastNode->TargetType = TargetType;
	CastNode->ReconstructNode();

	if (SourceExpr && SourceExpr->Token != EX_Nothing)
	{
		UEdGraphPin* InputPin = CastNode->GetCastSourcePin();
		if (InputPin)
		{
			UEdGraphPin* SrcPin = ResolveDataExpr(
				Graph, SourceExpr, InputPin, NodeX, NodeY - DataNodeOffsetY);
			if (SrcPin) TryConnect(SrcPin, InputPin);
		}
	}

	return CastNode;
}

void FGraphBuilder::SanitizeGraphConnections(UBlueprint* BP)
{
	TArray<UEdGraph*> AllGraphs;
	BP->GetAllGraphs(AllGraphs);

	for (UEdGraph* Graph : AllGraphs)
	{
		if (!Graph) continue;
		for (UEdGraphNode* Node : Graph->Nodes)
		{
			if (!Node) continue;
			for (UEdGraphPin* Pin : Node->Pins)
			{
				if (!Pin) continue;
				for (int32 i = Pin->LinkedTo.Num() - 1; i >= 0; --i)
				{
					UEdGraphPin* Other = Pin->LinkedTo[i];
					if (!Other || Other->Direction == Pin->Direction)
					{
						if (Other) Other->LinkedTo.Remove(Pin);
						Pin->LinkedTo.RemoveAt(i);
					}
				}
			}
		}
	}
}

// ---------------------------------------------------------------------------
// Post-build fixups
// ---------------------------------------------------------------------------

void FGraphBuilder::RunPostBuildFixups(UBlueprint* BP)
{
	// Step 2: Wildcard pin type propagation
	TArray<UEdGraph*> AllGraphs;
	BP->GetAllGraphs(AllGraphs);

	for (UEdGraph* Graph : AllGraphs)
	{
		if (!Graph) continue;
		for (UEdGraphNode* Node : Graph->Nodes)
		{
			if (!Node) continue;

			bool bHasWildcard = false;
			for (UEdGraphPin* Pin : Node->Pins)
			{
				if (Pin && Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Wildcard
					&& Pin->LinkedTo.Num() > 0)
				{
					bHasWildcard = true;
					break;
				}
			}

			if (bHasWildcard)
			{
				Node->GetSchema()->ReconstructNode(*Node, true);
			}
		}
	}

	// Step 3: Select node wildcard option pin fix
	for (UEdGraph* Graph : AllGraphs)
	{
		if (!Graph) continue;
		for (UEdGraphNode* Node : Graph->Nodes)
		{
			if (UK2Node_Select* SelectNode = Cast<UK2Node_Select>(Node))
			{
				UEdGraphPin* ReturnPin = SelectNode->GetReturnValuePin();
				if (ReturnPin && ReturnPin->PinType.PinCategory != UEdGraphSchema_K2::PC_Wildcard)
				{
					for (UEdGraphPin* Pin : SelectNode->Pins)
					{
						if (Pin && Pin->Direction == EGPD_Input
							&& Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Wildcard)
						{
							Pin->PinType = ReturnPin->PinType;
						}
					}
				}
			}
		}
	}

	// Step 4: Connection sanitization
	SanitizeGraphConnections(BP);

	// Step 5: Restore deferred pin defaults
	for (const FDeferredDefault& DD : DeferredPinDefaults)
	{
		if (DD.Pin) DD.Pin->DefaultValue = DD.DefaultValue;
	}
	DeferredPinDefaults.Empty();
}

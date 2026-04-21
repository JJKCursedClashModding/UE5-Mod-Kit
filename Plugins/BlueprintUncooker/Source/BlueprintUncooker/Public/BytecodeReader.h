#pragma once

#include "CoreMinimal.h"
#include "UObject/Script.h"   // EExprToken
#include "Math/Vector.h"
#include "Math/Rotator.h"
#include "Math/Transform.h"

class UFunction;
class UClass;
class UScriptStruct;
class UObject;
class FField;
class FProperty;

DECLARE_LOG_CATEGORY_EXTERN(LogBytecodeReader, Log, All);

// ---------------------------------------------------------------------------
// Intermediate Representation
// ---------------------------------------------------------------------------

/** A single decompiled expression (one bytecode instruction + its operands). */
struct BLUEPRINTUNCOOKER_API FDecompiledExpr : public TSharedFromThis<FDecompiledExpr>
{
	EExprToken Token = EX_Nothing;

	/** Byte offsets within the owning UFunction::Script. */
	int32 StartOffset = 0;
	int32 EndOffset   = 0;

	// ── Object/Field Refs (populated based on Token) ──────────────────────
	UFunction*     FunctionRef      = nullptr;
	FProperty*     PropertyRef      = nullptr;
	/** EX_MapConst: value FProperty* (stored separately from key PropertyRef). */
	FProperty*     ValuePropertyRef = nullptr;
	FField*        FieldRef         = nullptr;
	UObject*       ObjectRef        = nullptr;
	UClass*        ClassRef         = nullptr;
	UScriptStruct* StructRef        = nullptr;

	// ── Scalar Literals ───────────────────────────────────────────────────
	int32   IntValue    = 0;
	int64   Int64Value  = 0;
	uint8   ByteValue   = 0;
	float   FloatValue  = 0.f;
	double  DoubleValue = 0.0;   // EX_DoubleConst (UE5 new)
	FString StringValue;
	FName   NameValue;
	bool    BoolValue   = false;

	// ── Spatial Literals ─────────────────────────────────────────────────
	FVector   VectorValue;         // EX_VectorConst (doubles in UE5 LWC)
	FVector3f Vector3fValue;       // EX_Vector3fConst (explicit float, UE5 new)
	FRotator  RotatorValue;        // EX_RotationConst (doubles in UE5 LWC)
	FTransform TransformValue;     // EX_TransformConst (doubles in UE5 LWC)

	// ── Control Flow ─────────────────────────────────────────────────────
	uint32 JumpTarget = 0;         // Absolute bytecode offset for jumps

	// ── Tree Structure ────────────────────────────────────────────────────
	TArray<TSharedPtr<FDecompiledExpr>> Children;
	TSharedPtr<FDecompiledExpr> ContextObject; // For EX_Context: owner object

	// ── Helpers ───────────────────────────────────────────────────────────
	bool IsLiteral() const;
	bool IsStatement() const;
	bool IsFunctionCall() const;
	FString GetLiteralAsString() const;
	FString ToDebugString() const;
};

/** One fully decompiled UFunction. */
struct BLUEPRINTUNCOOKER_API FDecompiledFunction
{
	UFunction* OriginalFunction  = nullptr;
	FString    FunctionName;

	/** Top-level statements in execution order. */
	TArray<TSharedPtr<FDecompiledExpr>> Statements;

	/** Maps bytecode offsets → statement index, used for jump resolution. */
	TMap<int32, int32> OffsetToStatementIndex;

	/** For ubergraphs: event name → entry offset in this ubergraph. */
	TMap<FName, int32> EventEntryPoints;

	bool bIsUbergraph   = false;
	bool bIsEventStub   = false;
	int32 UbergraphEntryOffset = -1;
};

// ---------------------------------------------------------------------------
// Reader
// ---------------------------------------------------------------------------

/**
 * Reads raw Kismet bytecode from UFunction::Script and produces an IR tree.
 */
class BLUEPRINTUNCOOKER_API FBytecodeReader
{
public:
	/** Decompile all functions on a class (excluding inherited). */
	static TArray<FDecompiledFunction> DecompileClass(UClass* OriginalClass);

private:
	FBytecodeReader(const TArray<uint8>& InScript, UFunction* InFunc);

	// ── State ─────────────────────────────────────────────────────────────
	const TArray<uint8>& Script;
	int32  Offset    = 0;
	bool   bReadError = false;
	TArray<FString> Errors;
	UFunction* OwnerFunction = nullptr;

	// ── Core Decompilation ────────────────────────────────────────────────
	FDecompiledFunction DecompileFunction();
	TSharedPtr<FDecompiledExpr> ReadExpression();

	// ── Event Stub Detection ─────────────────────────────────────────────
	static bool IsEventStubFunction(UFunction* Func, int32& OutUbergraphOffset);

	// ── Typed Readers ─────────────────────────────────────────────────────
	template<typename T>
	T Read()
	{
		if (!Script.IsValidIndex(Offset + (int32)sizeof(T) - 1))
		{
			bReadError = true;
			return T{};
		}
		T Value;
		FMemory::Memcpy(&Value, &Script[Offset], sizeof(T));
		Offset += sizeof(T);
		return Value;
	}

	UObject*   ReadObject();
	FProperty* ReadProperty();
	FField*    ReadField();
	UClass*    ReadClass();
	UFunction* ReadFunction();
	FName      ReadScriptName();
	FString    ReadAnsiString();
	FString    ReadUnicodeString();
	uint32     ReadSkipCount();   // reads CodeSkipSizeType (uint32, 4 bytes)

	/** Validates that a raw pointer value appears to be a readable UObject. */
	static bool IsValidObjectPointer(void* Ptr);
};

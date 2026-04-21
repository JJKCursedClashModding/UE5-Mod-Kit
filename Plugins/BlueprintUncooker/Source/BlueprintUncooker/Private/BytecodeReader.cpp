#include "BytecodeReader.h"

#include "UObject/Class.h"
#include "UObject/Script.h"
#include "UObject/UnrealType.h"
#include "UObject/NameTypes.h"
#include "Engine/BlueprintGeneratedClass.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <memoryapi.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

DEFINE_LOG_CATEGORY(LogBytecodeReader);

// ---------------------------------------------------------------------------
// FDecompiledExpr helpers
// ---------------------------------------------------------------------------

bool FDecompiledExpr::IsLiteral() const
{
	switch (Token)
	{
	case EX_IntConst:
	case EX_Int64Const:
	case EX_UInt64Const:
	case EX_IntZero:
	case EX_IntOne:
	case EX_IntConstByte:
	case EX_ByteConst:
	case EX_FloatConst:
	case EX_DoubleConst:
	case EX_True:
	case EX_False:
	case EX_StringConst:
	case EX_UnicodeStringConst:
	case EX_NameConst:
	case EX_TextConst:
	case EX_ObjectConst:
	case EX_SoftObjectConst:
	case EX_NoObject:
	case EX_NoInterface:
	case EX_VectorConst:
	case EX_RotationConst:
	case EX_TransformConst:
	case EX_StructConst:
	case EX_Self:
		return true;
	default:
		// EX_Vector3fConst is 0x41 — check raw value
		if ((uint8)Token == 0x41) return true;
		return false;
	}
}

bool FDecompiledExpr::IsFunctionCall() const
{
	switch (Token)
	{
	case EX_FinalFunction:
	case EX_LocalFinalFunction:
	case EX_VirtualFunction:
	case EX_LocalVirtualFunction:
	case EX_CallMath:
	case EX_CallMulticastDelegate:
		return true;
	default:
		return false;
	}
}

bool FDecompiledExpr::IsStatement() const
{
	switch (Token)
	{
	case EX_Let:
	case EX_LetObj:
	case EX_LetBool:
	case EX_LetDelegate:
	case EX_LetMulticastDelegate:
	case EX_LetWeakObjPtr:
	case EX_LetValueOnPersistentFrame:
	case EX_Jump:
	case EX_JumpIfNot:
	case EX_Return:
	case EX_PushExecutionFlow:
	case EX_PopExecutionFlow:
	case EX_PopExecutionFlowIfNot:
	case EX_ComputedJump:
	case EX_SwitchValue:
	case EX_BindDelegate:
	case EX_AddMulticastDelegate:
	case EX_RemoveMulticastDelegate:
	case EX_ClearMulticastDelegate:
		return true;
	default:
		return IsFunctionCall();
	}
}

FString FDecompiledExpr::GetLiteralAsString() const
{
	switch (Token)
	{
	case EX_IntConst:
	case EX_IntZero:
	case EX_IntOne:
	case EX_IntConstByte:
		return FString::FromInt(IntValue);
	case EX_ByteConst:
		return FString::FromInt((int32)ByteValue);
	case EX_Int64Const:
		return FString::Printf(TEXT("%lld"), Int64Value);
	case EX_UInt64Const:
		return FString::Printf(TEXT("%llu"), (uint64)Int64Value);
	case EX_FloatConst:
		return FString::SanitizeFloat(FloatValue);
	case EX_DoubleConst:
		return FString::SanitizeFloat(DoubleValue);
	case EX_True:
		return TEXT("true");
	case EX_False:
		return TEXT("false");
	case EX_StringConst:
	case EX_UnicodeStringConst:
		return StringValue;
	case EX_NameConst:
		return NameValue.ToString();
	case EX_VectorConst:
		return FString::Printf(TEXT("X=%f Y=%f Z=%f"),
			VectorValue.X, VectorValue.Y, VectorValue.Z);
	case EX_RotationConst:
		return FString::Printf(TEXT("P=%f Y=%f R=%f"),
			RotatorValue.Pitch, RotatorValue.Yaw, RotatorValue.Roll);
	case EX_NoObject:
	case EX_NoInterface:
		return TEXT("None");
	default:
		// EX_Vector3fConst (0x41)
		if ((uint8)Token == 0x41)
		{
			return FString::Printf(TEXT("X=%f Y=%f Z=%f"),
				(double)Vector3fValue.X, (double)Vector3fValue.Y, (double)Vector3fValue.Z);
		}
		return TEXT("");
	}
}

FString FDecompiledExpr::ToDebugString() const
{
	return FString::Printf(TEXT("[0x%02X @ %d..%d]"), (uint8)Token, StartOffset, EndOffset);
}

// ---------------------------------------------------------------------------
// FBytecodeReader — constructor
// ---------------------------------------------------------------------------

FBytecodeReader::FBytecodeReader(const TArray<uint8>& InScript, UFunction* InFunc)
	: Script(InScript)
	, Offset(0)
	, bReadError(false)
	, OwnerFunction(InFunc)
{}

// ---------------------------------------------------------------------------
// Pointer validation
// ---------------------------------------------------------------------------

bool FBytecodeReader::IsValidObjectPointer(void* Ptr)
{
	if (Ptr == nullptr) return false;

#if PLATFORM_WINDOWS
	MEMORY_BASIC_INFORMATION MemInfo;
	if (VirtualQuery(Ptr, &MemInfo, sizeof(MemInfo)) == 0) return false;
	const DWORD ReadableFlags = PAGE_READONLY | PAGE_READWRITE
	                          | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE;
	if (!(MemInfo.State == MEM_COMMIT && (MemInfo.Protect & ReadableFlags)))
	{
		return false;
	}
#endif

	UObject* Candidate = static_cast<UObject*>(Ptr);
	return Candidate->IsValidLowLevel();
}

// ---------------------------------------------------------------------------
// Typed readers
// ---------------------------------------------------------------------------

UObject* FBytecodeReader::ReadObject()
{
	ScriptPointerType Raw = Read<ScriptPointerType>();
	UObject* Obj = (UObject*)(Raw);
	if (Raw != 0 && !IsValidObjectPointer(Obj))
	{
		UE_LOG(LogBytecodeReader, Verbose,
			TEXT("ReadObject: invalid pointer 0x%llX at offset %d"), (uint64)Raw, Offset);
		return nullptr;
	}
	return Obj;
}

FProperty* FBytecodeReader::ReadProperty()
{
	ScriptPointerType Raw = Read<ScriptPointerType>();
	return (FProperty*)(Raw);
}

FField* FBytecodeReader::ReadField()
{
	ScriptPointerType Raw = Read<ScriptPointerType>();
	return (FField*)(Raw);
}

UClass* FBytecodeReader::ReadClass()
{
	return Cast<UClass>(ReadObject());
}

UFunction* FBytecodeReader::ReadFunction()
{
	ScriptPointerType Raw = Read<ScriptPointerType>();
	UFunction* Func = (UFunction*)(Raw);
	if (Raw != 0 && !IsValidObjectPointer(Func))
	{
		return nullptr;
	}
	return Func;
}

FName FBytecodeReader::ReadScriptName()
{
	// FScriptName private members cannot be accessed directly (UE5.1).
	// Use a bitwise memcpy — same technique as FKismetBytecodeDisassembler::ReadName().
	if (!Script.IsValidIndex(Offset + (int32)sizeof(FScriptName) - 1))
	{
		bReadError = true;
		return NAME_None;
	}
	FScriptName SN;
	FMemory::Memcpy(&SN, &Script[Offset], sizeof(FScriptName));
	Offset += sizeof(FScriptName);
	return ScriptNameToName(SN);
}

FString FBytecodeReader::ReadAnsiString()
{
	FString Result;
	while (Script.IsValidIndex(Offset))
	{
		uint8 Ch = Read<uint8>();
		if (Ch == 0) break;
		Result.AppendChar((TCHAR)Ch);
	}
	return Result;
}

FString FBytecodeReader::ReadUnicodeString()
{
	FString Result;
	while (Script.IsValidIndex(Offset + 1))
	{
		uint16 Ch = Read<uint16>();
		if (Ch == 0) break;
		Result.AppendChar((TCHAR)Ch);
	}
	return Result;
}

uint32 FBytecodeReader::ReadSkipCount()
{
	return Read<uint32>();
}

// ---------------------------------------------------------------------------
// Event stub detection
// ---------------------------------------------------------------------------

bool FBytecodeReader::IsEventStubFunction(UFunction* Func, int32& OutUbergraphOffset)
{
	if (!Func || Func->Script.Num() == 0) return false;

	const TArray<uint8>& S = Func->Script;
	int32 SearchStart = 0;

	// Dump first 24 bytes for diagnosis
	{
		FString HexDump;
		int32 DumpLen = FMath::Min(24, S.Num());
		for (int32 i = 0; i < DumpLen; ++i)
			HexDump += FString::Printf(TEXT("%02X "), S[i]);
		UE_LOG(LogBytecodeReader, Log, TEXT("IsEventStub [%s] Script[0..%d]: %s"),
			*Func->GetName(), DumpLen - 1, *HexDump);
	}

	// Skip leading 1-byte debug/trace NOPs that the compiler emits in Development/Editor builds.
	// EX_Tracepoint (0x5E), EX_WireTracepoint (0x5A), EX_Breakpoint (0x50) are all 1-byte ops.
	// This is the #1 cause of "empty graph" on editor-compiled (non-cooked) Blueprints.
	while (SearchStart < S.Num())
	{
		uint8 Tok = S[SearchStart];
		if (Tok == (uint8)EX_Tracepoint     // 0x5E
		||  Tok == (uint8)EX_WireTracepoint // 0x5A
		||  Tok == (uint8)EX_Breakpoint)    // 0x50
		{
			UE_LOG(LogBytecodeReader, Log, TEXT("  -> skipping debug NOP 0x%02X at [%d]"), Tok, SearchStart);
			++SearchStart;
		}
		else
		{
			break;
		}
	}

	if (SearchStart >= S.Num())
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: all bytes were debug NOPs"));
		return false;
	}

	UE_LOG(LogBytecodeReader, Log, TEXT("  -> first real byte at [%d] = 0x%02X (EX_FinalFunction=0x%02X EX_LocalFinalFunction=0x%02X EX_LetValueOnPersistentFrame=0x%02X)"),
		SearchStart, S[SearchStart],
		(uint8)EX_FinalFunction, (uint8)EX_LocalFinalFunction, (uint8)EX_LetValueOnPersistentFrame);

	// Pattern 1: starts directly with a function-call token (after any debug NOPs)
	// Pattern 2: starts with EX_LetValueOnPersistentFrame (parameter copies first)
	if (S[SearchStart] == (uint8)EX_LetValueOnPersistentFrame)
	{
		// Scan forward (max 512 bytes) looking for the ubergraph call
		++SearchStart;
		int32 Limit = FMath::Min(SearchStart + 512, S.Num());
		bool bFound = false;
		while (SearchStart < Limit)
		{
			uint8 Tok = S[SearchStart];
			if (Tok == (uint8)EX_FinalFunction || Tok == (uint8)EX_LocalFinalFunction)
			{
				bFound = true;
				break;
			}
			++SearchStart;
		}
		if (!bFound)
		{
			UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: LetValueOnPersistentFrame found but no FinalFunction in 512 bytes"));
			return false;
		}
	}
	else if (S[SearchStart] != (uint8)EX_FinalFunction && S[SearchStart] != (uint8)EX_LocalFinalFunction)
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: byte 0x%02X is not FinalFunction/LocalFinalFunction/LetValueOnPersistentFrame"), S[SearchStart]);
		return false;
	}

	// At SearchStart we expect: FuncCallToken + FuncPtr(8) + IntConst + IntValue(4) + EndFunctionParms
	int32 Idx = SearchStart;
	if (Idx + 1 + (int32)sizeof(ScriptPointerType) >= S.Num())
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: not enough bytes after call token (Idx=%d, ScriptNum=%d)"), Idx, S.Num());
		return false;
	}

	++Idx; // skip the token byte

	// Read function pointer
	ScriptPointerType FuncRaw = 0;
	FMemory::Memcpy(&FuncRaw, &S[Idx], sizeof(ScriptPointerType));
	Idx += sizeof(ScriptPointerType);

	UFunction* CalledFunc = (UFunction*)(FuncRaw);
	if (!IsValidObjectPointer(CalledFunc))
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: FuncPtr 0x%llX at Idx=%d is not a valid UObject"), (uint64)FuncRaw, Idx - (int32)sizeof(ScriptPointerType));
		return false;
	}

	// Check if called function name is "ExecuteUbergraph_"
	FString CalledName = CalledFunc->GetName();
	UE_LOG(LogBytecodeReader, Log, TEXT("  -> FuncPtr resolved to '%s'"), *CalledName);
	if (!CalledName.StartsWith(TEXT("ExecuteUbergraph_")))
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: called function is not ExecuteUbergraph_*"));
		return false;
	}

	// Expect EX_IntConst next
	if (Idx >= S.Num())
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: ran out of bytes before EX_IntConst"));
		return false;
	}
	UE_LOG(LogBytecodeReader, Log, TEXT("  -> byte after FuncPtr: 0x%02X (expect EX_IntConst=0x%02X)"), S[Idx], (uint8)EX_IntConst);
	if (S[Idx] != (uint8)EX_IntConst)
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: expected EX_IntConst (0x%02X) got 0x%02X"), (uint8)EX_IntConst, S[Idx]);
		return false;
	}
	++Idx;

	if (Idx + (int32)sizeof(int32) > S.Num())
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> REJECT: not enough bytes for entry offset int32"));
		return false;
	}
	int32 EntryOffset = 0;
	FMemory::Memcpy(&EntryOffset, &S[Idx], sizeof(int32));

	UE_LOG(LogBytecodeReader, Log, TEXT("  -> ACCEPT: entry offset = %d"), EntryOffset);
	OutUbergraphOffset = EntryOffset;
	return true;
}

// ---------------------------------------------------------------------------
// Class-level decompilation
// ---------------------------------------------------------------------------

TArray<FDecompiledFunction> FBytecodeReader::DecompileClass(UClass* OriginalClass)
{
	TArray<FDecompiledFunction> Results;
	if (!OriginalClass) return Results;

	TMap<FName, int32> EventEntryOffsets; // event name → ubergraph offset
	UFunction* UbergraphFunc = nullptr;

	UE_LOG(LogBytecodeReader, Log, TEXT("DecompileClass: scanning '%s'"),
		*OriginalClass->GetName());

	// First pass: classify functions
	int32 TotalFuncs = 0;
	for (TFieldIterator<UFunction> FuncIt(OriginalClass, EFieldIteratorFlags::ExcludeSuper);
		FuncIt; ++FuncIt)
	{
		UFunction* Func = *FuncIt;
		++TotalFuncs;

		if (!Func || Func->Script.Num() == 0)
		{
			UE_LOG(LogBytecodeReader, Log, TEXT("  [%s] Script.Num()==0 — skipping"), Func ? *Func->GetName() : TEXT("null"));
			continue;
		}

		FString FuncName = Func->GetName();
		UE_LOG(LogBytecodeReader, Log, TEXT("  Classifying [%s] (%d bytes)"), *FuncName, Func->Script.Num());

		// Check if this is the ubergraph
		if (FuncName.StartsWith(TEXT("ExecuteUbergraph_")))
		{
			UbergraphFunc = Func;
			UE_LOG(LogBytecodeReader, Log, TEXT("  -> UBERGRAPH"));
			continue;
		}

		// Check for event stub
		int32 UbergraphOffset = -1;
		if (IsEventStubFunction(Func, UbergraphOffset))
		{
			UE_LOG(LogBytecodeReader, Log, TEXT("  -> EVENT STUB (entryOffset=%d)"), UbergraphOffset);
			FDecompiledFunction StubFunc;
			StubFunc.OriginalFunction    = Func;
			StubFunc.FunctionName        = FuncName;
			StubFunc.bIsEventStub        = true;
			StubFunc.UbergraphEntryOffset = UbergraphOffset;
			EventEntryOffsets.Add(Func->GetFName(), UbergraphOffset);
			Results.Add(MoveTemp(StubFunc));
		}
		else
		{
			UE_LOG(LogBytecodeReader, Log, TEXT("  -> REGULAR FUNCTION"));
			// Regular function — full decompile
			FBytecodeReader Reader(Func->Script, Func);
			FDecompiledFunction DecompiledFunc = Reader.DecompileFunction();
			DecompiledFunc.OriginalFunction = Func;
			DecompiledFunc.FunctionName     = FuncName;
			Results.Add(MoveTemp(DecompiledFunc));
		}
	}

	UE_LOG(LogBytecodeReader, Log, TEXT("DecompileClass SUMMARY: %d total funcs | %d event stubs | ubergraph=%s"),
		TotalFuncs, EventEntryOffsets.Num(), UbergraphFunc ? *UbergraphFunc->GetName() : TEXT("NONE"));

	// Second pass: decompile ubergraph and attach event entry points
	if (UbergraphFunc && UbergraphFunc->Script.Num() > 0)
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("Decompiling ubergraph '%s' (%d bytes)..."),
			*UbergraphFunc->GetName(), UbergraphFunc->Script.Num());
		FBytecodeReader Reader(UbergraphFunc->Script, UbergraphFunc);
		FDecompiledFunction UbergraphDecomp = Reader.DecompileFunction();
		UE_LOG(LogBytecodeReader, Log, TEXT("  -> %d statements, %d offset entries"),
			UbergraphDecomp.Statements.Num(), UbergraphDecomp.OffsetToStatementIndex.Num());

		// Log offset map (first 20 entries)
		int32 LogCount = 0;
		for (auto& KV : UbergraphDecomp.OffsetToStatementIndex)
		{
			UE_LOG(LogBytecodeReader, Log, TEXT("  OffsetMap: byte %d -> stmtIdx %d"), KV.Key, KV.Value);
			if (++LogCount >= 20) { UE_LOG(LogBytecodeReader, Log, TEXT("  ... (truncated)")); break; }
		}
		// Log event entry offsets we're looking for
		for (auto& KV : EventEntryOffsets)
		{
			bool bFound = UbergraphDecomp.OffsetToStatementIndex.Contains(KV.Value);
			UE_LOG(LogBytecodeReader, Log, TEXT("  EventEntry [%s] offset=%d found_in_map=%s"),
				*KV.Key.ToString(), KV.Value, bFound ? TEXT("YES") : TEXT("NO"));
		}

		UbergraphDecomp.OriginalFunction = UbergraphFunc;
		UbergraphDecomp.FunctionName     = UbergraphFunc->GetName();
		UbergraphDecomp.bIsUbergraph     = true;
		UbergraphDecomp.EventEntryPoints = EventEntryOffsets;
		Results.Add(MoveTemp(UbergraphDecomp));
	}
	else
	{
		UE_LOG(LogBytecodeReader, Log, TEXT("DecompileClass: NO UBERGRAPH FOUND or empty script"));
	}

	return Results;
}

// ---------------------------------------------------------------------------
// Function-level decompilation
// ---------------------------------------------------------------------------

FDecompiledFunction FBytecodeReader::DecompileFunction()
{
	FDecompiledFunction Result;
	Result.OriginalFunction = OwnerFunction;

	while (!bReadError && Offset < Script.Num())
	{
		// Record offset-to-statement mapping before reading
		int32 StmtOffset = Offset;

		TSharedPtr<FDecompiledExpr> Expr = ReadExpression();
		if (!Expr) break;

		if (Expr->Token == EX_EndOfScript) break;

		Result.OffsetToStatementIndex.Add(StmtOffset, Result.Statements.Num());
		Result.Statements.Add(Expr);
	}

	return Result;
}

// ---------------------------------------------------------------------------
// Recursive expression reader — the heart of the decompiler
// ---------------------------------------------------------------------------

TSharedPtr<FDecompiledExpr> FBytecodeReader::ReadExpression()
{
	if (bReadError || !Script.IsValidIndex(Offset)) return nullptr;

	auto Expr = MakeShared<FDecompiledExpr>();
	Expr->StartOffset = Offset;
	Expr->Token = (EExprToken)Read<uint8>();

	switch (Expr->Token)
	{
	// ── Terminators / No-ops ────────────────────────────────────────────
	case EX_Nothing:
	case EX_EndOfScript:
	case EX_EndFunctionParms:
	case EX_EndStructConst:
	case EX_EndArray:
	case EX_EndArrayConst:
	case EX_EndSet:
	case EX_EndMap:
	case EX_EndSetConst:
	case EX_EndMapConst:
	case EX_Self:
	case EX_Tracepoint:
	case EX_WireTracepoint:
	case EX_Breakpoint:
	case EX_NoObject:
	case EX_NoInterface:
	case EX_IntZero:
	case EX_IntOne:
	case EX_True:
	case EX_False:
	case EX_PopExecutionFlow:
		// No additional bytes
		break;

	case (EExprToken)0x0C:  // EX_NothingInt32 — not in UE5.1 enum; raw opcode 0x0C
		// NOP with unused int32
		Expr->IntValue = Read<int32>();
		break;

	// ── Integer Literals ─────────────────────────────────────────────────
	case EX_IntConst:
		Expr->IntValue = Read<int32>();
		break;

	case EX_ByteConst:
		Expr->ByteValue = Read<uint8>();
		break;

	case EX_IntConstByte:
		Expr->IntValue = (int32)Read<uint8>();
		break;

	case EX_Int64Const:
		Expr->Int64Value = Read<int64>();
		break;

	case EX_UInt64Const:
		Expr->Int64Value = (int64)Read<uint64>();
		break;

	// ── Float/Double Literals ────────────────────────────────────────────
	case EX_FloatConst:
		Expr->FloatValue = Read<float>();
		break;

	case EX_DoubleConst:  // 0x37 — NEW in UE5
		Expr->DoubleValue = Read<double>();
		break;

	// ── String / Name / Text Literals ────────────────────────────────────
	case EX_StringConst:
		Expr->StringValue = ReadAnsiString();
		break;

	case EX_UnicodeStringConst:
		Expr->StringValue = ReadUnicodeString();
		break;

	case EX_NameConst:
		Expr->NameValue = ReadScriptName();
		break;

	case EX_TextConst:
	{
		// EBlueprintTextLiteralType byte, then sub-expressions.
		// Real enum (Script.h / ScriptDisassembler.cpp):
		//   Empty=0, LocalizedText=1, InvariantText=2, LiteralString=3, StringTableEntry=4.
		// (Previous mapping was off-by-one — Empty was at 3, Localized at 0, etc.)
		uint8 TextKind = Read<uint8>();
		Expr->ByteValue = TextKind;
		switch (TextKind)
		{
		case 0: // Empty — nothing follows
			break;
		case 1: // LocalizedText: SourceString + Key + Namespace (3 string expressions)
			Expr->Children.Add(ReadExpression()); // source string
			Expr->Children.Add(ReadExpression()); // key
			Expr->Children.Add(ReadExpression()); // namespace
			break;
		case 2: // InvariantText: 1 string expression
		case 3: // LiteralString: 1 string expression
			Expr->Children.Add(ReadExpression());
			break;
		case 4: // StringTableEntry: UObject*(8 bytes) + table-id expression + key expression
			Expr->ObjectRef = ReadObject();          // table asset pointer
			Expr->Children.Add(ReadExpression());    // table id string expression
			Expr->Children.Add(ReadExpression());    // key string expression
			break;
		default:
			UE_LOG(LogBytecodeReader, Warning,
				TEXT("EX_TextConst: unknown TextKind %d at offset %d"), TextKind, Expr->StartOffset);
			break;
		}
		break;
	}

	// ── Object Literals ──────────────────────────────────────────────────
	case EX_ObjectConst:
		Expr->ObjectRef = ReadObject();
		break;

	case EX_SoftObjectConst:
		Expr->Children.Add(ReadExpression()); // inner path string expression
		break;

	// ── Spatial Literals (UE5: all doubles via LWC) ──────────────────────
	case EX_VectorConst:
	{
		// UE5: 3 × double = 24 bytes
		double X = Read<double>();
		double Y = Read<double>();
		double Z = Read<double>();
		Expr->VectorValue = FVector(X, Y, Z);
		break;
	}

	case EX_RotationConst:
	{
		// UE5: 3 × double = 24 bytes
		double Pitch = Read<double>();
		double Yaw   = Read<double>();
		double Roll  = Read<double>();
		Expr->RotatorValue = FRotator(Pitch, Yaw, Roll);
		break;
	}

	case EX_TransformConst:
	{
		// UE5: 10 × double = 80 bytes  (Quat:4 + Translation:3 + Scale:3)
		FQuat  Rot(Read<double>(), Read<double>(), Read<double>(), Read<double>());
		FVector Trans(Read<double>(), Read<double>(), Read<double>());
		FVector Scale(Read<double>(), Read<double>(), Read<double>());
		Expr->TransformValue = FTransform(Rot, Trans, Scale);
		break;
	}

	// EX_Vector3fConst = 0x41 (new UE5 — explicit float-precision vector)
	// Handled in the default case below using the raw token value.

	// ── Variable Access ──────────────────────────────────────────────────
	case EX_LocalVariable:
	case EX_InstanceVariable:
	case EX_DefaultVariable:
	case EX_LocalOutVariable:
	case EX_ClassSparseDataVariable:  // 0x6C
	case EX_PropertyConst:            // 0x33
		Expr->PropertyRef = ReadProperty();
		break;

	case EX_FieldPathConst:           // 0x6D — format is a full sub-expression, NOT a raw 8-byte pointer
		// Confirmed by ScriptDisassembler.cpp: SerializeExpr() is called, not a pointer read.
		Expr->Children.Add(ReadExpression());
		break;

	case EX_StructMemberContext:
		// Property + struct-owner expression
		Expr->PropertyRef = ReadProperty();
		Expr->Children.Add(ReadExpression());
		break;

	// ── Function Calls ───────────────────────────────────────────────────
	case EX_FinalFunction:
	case EX_LocalFinalFunction:
	case EX_CallMath:
		Expr->FunctionRef = ReadFunction();
		// Read arguments until EX_EndFunctionParms
		while (!bReadError && Offset < Script.Num())
		{
			if (Script.IsValidIndex(Offset) && Script[Offset] == (uint8)EX_EndFunctionParms)
			{
				Read<uint8>(); // consume EX_EndFunctionParms
				break;
			}
			auto ArgExpr = ReadExpression();
			if (!ArgExpr || ArgExpr->Token == EX_EndFunctionParms) break;
			Expr->Children.Add(ArgExpr);
		}
		break;

	case EX_VirtualFunction:
	case EX_LocalVirtualFunction:
		Expr->NameValue = ReadScriptName();
		while (!bReadError && Offset < Script.Num())
		{
			if (Script.IsValidIndex(Offset) && Script[Offset] == (uint8)EX_EndFunctionParms)
			{
				Read<uint8>();
				break;
			}
			auto ArgExpr = ReadExpression();
			if (!ArgExpr || ArgExpr->Token == EX_EndFunctionParms) break;
			Expr->Children.Add(ArgExpr);
		}
		break;

	case EX_CallMulticastDelegate:
		// FuncPtr (signature) + args + EX_EndFunctionParms
		Expr->FunctionRef = ReadFunction();
		while (!bReadError && Offset < Script.Num())
		{
			if (Script.IsValidIndex(Offset) && Script[Offset] == (uint8)EX_EndFunctionParms)
			{
				Read<uint8>();
				break;
			}
			auto ArgExpr = ReadExpression();
			if (!ArgExpr || ArgExpr->Token == EX_EndFunctionParms) break;
			Expr->Children.Add(ArgExpr);
		}
		break;

	// ── Assignments ──────────────────────────────────────────────────────
	case EX_Let:
		// PropertyRef (type hint) + destination + source
		Expr->PropertyRef = ReadProperty();
		Expr->Children.Add(ReadExpression()); // destination
		Expr->Children.Add(ReadExpression()); // source
		break;

	case EX_LetObj:
	case EX_LetBool:
	case EX_LetDelegate:
	case EX_LetMulticastDelegate:
	case EX_LetWeakObjPtr:
		Expr->Children.Add(ReadExpression()); // destination
		Expr->Children.Add(ReadExpression()); // source
		break;

	case EX_LetValueOnPersistentFrame:
		Expr->PropertyRef = ReadProperty();
		Expr->Children.Add(ReadExpression()); // value
		break;

	// ── Control Flow ─────────────────────────────────────────────────────
	case EX_Jump:
		Expr->JumpTarget = ReadSkipCount();
		break;

	case EX_JumpIfNot:
		Expr->JumpTarget = ReadSkipCount();
		Expr->Children.Add(ReadExpression()); // condition
		break;

	case EX_Return:
		Expr->Children.Add(ReadExpression()); // return value (often EX_Nothing)
		break;

	case EX_PushExecutionFlow:
		Expr->JumpTarget = ReadSkipCount();
		break;

	case EX_PopExecutionFlowIfNot:
		Expr->Children.Add(ReadExpression()); // condition
		break;

	case EX_ComputedJump:
		Expr->Children.Add(ReadExpression()); // index expression
		break;

	case EX_SwitchValue:
	{
		// NumCases(uint16) + EndOffset(uint32) + IndexTerm + N×(CaseVal+SkipOff+Result) + Default
		uint16 NumCases = Read<uint16>();
		Expr->IntValue   = (int32)NumCases;
		Expr->JumpTarget = ReadSkipCount(); // end offset
		Expr->Children.Add(ReadExpression()); // index expression
		for (uint16 i = 0; i < NumCases; ++i)
		{
			Expr->Children.Add(ReadExpression()); // case value
			uint32 SkipOff = ReadSkipCount();
			(void)SkipOff;
			Expr->Children.Add(ReadExpression()); // result expression
		}
		Expr->Children.Add(ReadExpression()); // default
		break;
	}

	case EX_Assert:
	{
		uint16 LineNum  = Read<uint16>();
		uint8  DbgMode  = Read<uint8>();
		(void)LineNum; (void)DbgMode;
		Expr->Children.Add(ReadExpression()); // condition
		break;
	}

	case EX_Skip:
		Expr->JumpTarget = ReadSkipCount();
		Expr->Children.Add(ReadExpression());
		break;

	// ── Context Chains ───────────────────────────────────────────────────
	case EX_Context:
	case EX_Context_FailSilent:
	{
		Expr->ContextObject = ReadExpression();           // target object
		uint32 SkipOff = ReadSkipCount();                 // null-skip offset
		(void)SkipOff;
		Expr->FieldRef = ReadField();                     // r-value property
		Expr->Children.Add(ReadExpression());             // operation inside context
		break;
	}

	case EX_ClassContext:
	{
		Expr->Children.Add(ReadExpression()); // class expression
		uint32 SkipOff = ReadSkipCount();
		(void)SkipOff;
		Expr->FieldRef = ReadField();
		Expr->Children.Add(ReadExpression()); // operation
		break;
	}

	case EX_InterfaceContext:
		Expr->Children.Add(ReadExpression()); // interface expression only (UE5 format)
		break;

	// ── Casts ────────────────────────────────────────────────────────────
	case EX_DynamicCast:       // 0x2E
	case EX_MetaCast:          // 0x13
	case EX_ObjToInterfaceCast: // 0x52
	case EX_CrossInterfaceCast: // 0x54
	case EX_InterfaceToObjCast: // 0x55
		Expr->ClassRef = ReadClass();
		Expr->Children.Add(ReadExpression());
		break;

	case EX_Cast:  // 0x38 — UE5 uniform cast (replaced EX_PrimitiveCast)
		Expr->ByteValue = Read<uint8>();
		Expr->Children.Add(ReadExpression());
		break;

	// ── Delegate Operations ───────────────────────────────────────────────
	case EX_BindDelegate:
		// FName + delegate expression + target object
		Expr->NameValue = ReadScriptName();
		Expr->Children.Add(ReadExpression()); // delegate variable
		Expr->Children.Add(ReadExpression()); // target object
		break;

	case EX_AddMulticastDelegate:
	case EX_RemoveMulticastDelegate:
		Expr->Children.Add(ReadExpression()); // multicast delegate
		Expr->Children.Add(ReadExpression()); // delegate to add/remove
		break;

	case EX_ClearMulticastDelegate:
		Expr->Children.Add(ReadExpression()); // multicast delegate
		break;

	case EX_InstanceDelegate:
		Expr->NameValue = ReadScriptName();
		break;

	// ── Collections ───────────────────────────────────────────────────────
	case EX_SetArray:
	{
		// Target array property expression + elements until EX_EndArray
		Expr->Children.Add(ReadExpression()); // target array
		while (!bReadError && Offset < Script.Num())
		{
			if (Script.IsValidIndex(Offset) && Script[Offset] == (uint8)EX_EndArray)
			{
				Read<uint8>();
				break;
			}
			auto ElemExpr = ReadExpression();
			if (!ElemExpr || ElemExpr->Token == EX_EndArray) break;
			Expr->Children.Add(ElemExpr);
		}
		break;
	}

	case EX_ArrayConst:
	{
		Expr->PropertyRef = ReadProperty(); // inner property type
		int32 Count = Read<int32>();
		Expr->IntValue = Count;
		for (int32 i = 0; i < Count; ++i)
		{
			Expr->Children.Add(ReadExpression());
		}
		// EX_EndArrayConst
		if (Offset < Script.Num() && Script[Offset] == (uint8)EX_EndArrayConst)
		{
			Read<uint8>();
		}
		break;
	}

	case EX_SetSet:
	{
		// Target set property + count + elements + EX_EndSet
		Expr->Children.Add(ReadExpression()); // set property
		int32 Count = Read<int32>();
		Expr->IntValue = Count;
		for (int32 i = 0; i < Count; ++i)
		{
			Expr->Children.Add(ReadExpression());
		}
		if (Offset < Script.Num() && Script[Offset] == (uint8)EX_EndSet)
		{
			Read<uint8>();
		}
		break;
	}

	case EX_SetMap:
	{
		// Target map property + count + key/value pairs + EX_EndMap
		Expr->Children.Add(ReadExpression()); // map property
		int32 Count = Read<int32>();
		Expr->IntValue = Count;
		for (int32 i = 0; i < Count; ++i)
		{
			Expr->Children.Add(ReadExpression()); // key
			Expr->Children.Add(ReadExpression()); // value
		}
		if (Offset < Script.Num() && Script[Offset] == (uint8)EX_EndMap)
		{
			Read<uint8>();
		}
		break;
	}

	case EX_SetConst:
	{
		Expr->PropertyRef = ReadProperty();
		int32 Count = Read<int32>();
		Expr->IntValue = Count;
		for (int32 i = 0; i < Count; ++i)
		{
			Expr->Children.Add(ReadExpression());
		}
		if (Offset < Script.Num() && Script[Offset] == (uint8)EX_EndSetConst)
		{
			Read<uint8>();
		}
		break;
	}

	case EX_MapConst:
	{
		// Bug 2 fix: value is FProperty* not generic FField*. Both fields read 8 bytes
		// identically but semantic type is important for downstream pin-type resolution.
		Expr->PropertyRef      = ReadProperty(); // key property   (FProperty*)
		Expr->ValuePropertyRef = ReadProperty(); // value property (FProperty*) — was ReadField()
		int32 Count = Read<int32>();
		Expr->IntValue = Count;
		for (int32 i = 0; i < Count; ++i)
		{
			Expr->Children.Add(ReadExpression()); // key
			Expr->Children.Add(ReadExpression()); // value
		}
		if (Offset < Script.Num() && Script[Offset] == (uint8)EX_EndMapConst)
		{
			Read<uint8>();
		}
		break;
	}

	case EX_ArrayGetByRef:
		Expr->Children.Add(ReadExpression()); // array expression
		Expr->Children.Add(ReadExpression()); // index expression
		break;

	// ── Struct Literal ────────────────────────────────────────────────────
	case EX_StructConst:
	{
		Expr->StructRef = Cast<UScriptStruct>(ReadObject());
		int32 StructSize = Read<int32>();
		(void)StructSize;
		while (!bReadError && Offset < Script.Num())
		{
			if (Script.IsValidIndex(Offset) && Script[Offset] == (uint8)EX_EndStructConst)
			{
				Read<uint8>();
				break;
			}
			auto MemberExpr = ReadExpression();
			if (!MemberExpr || MemberExpr->Token == EX_EndStructConst) break;
			Expr->Children.Add(MemberExpr);
		}
		break;
	}

	// ── Delegate / Interface ─────────────────────────────────────────────
	case EX_SkipOffsetConst:
		Expr->JumpTarget = ReadSkipCount();
		break;

	case EX_InstrumentationEvent:
	{
		// Bug 1 fix: NO EX_InstrumentationEvent variant in UE 5.1 reads any extra data.
		// EvType == 2 is EScriptInstrumentation::Instance which carries NO extra bytes.
		// The old phantom FName read (sizeof(FScriptName) bytes) was corrupting stream position.
		uint8 EvType = Read<uint8>();
		Expr->ByteValue = EvType;
		break;
	}

	case (EExprToken)0x10:  // EX_BitFieldProperty — not in UE5.1 enum; raw opcode 0x10
		Expr->PropertyRef = ReadProperty();
		break;

	case EX_DeprecatedOp4A:
		// 0x4A — no data, deprecated
		break;

	case EX_EndParmValue:
		// end optional params — no data
		break;

	default:
	{
		uint8 RawToken = (uint8)Expr->Token;

		// EX_Vector3fConst = 0x41 (UE5 new — wire format is 3×double = 24 bytes).
		// Confirmed by ScriptDisassembler.cpp: ReadFVECTOR reads 3 doubles then casts to FVector3f.
		// The name says "float vector" but the compiler stores the components as doubles on the wire.
		if (RawToken == 0x41)
		{
			double X = Read<double>();
			double Y = Read<double>();
			double Z = Read<double>();
			Expr->Vector3fValue = FVector3f((float)X, (float)Y, (float)Z);
			Expr->VectorValue   = FVector(X, Y, Z);
			break;
		}

		// Unknown tokens above 0x74 — skip 12 bytes (heuristic)
		if (RawToken > 0x74)
		{
			Read<int32>();
			Read<uint64>();
			UE_LOG(LogBytecodeReader, Warning,
				TEXT("Unknown token 0x%02X at offset %d — skipping 12 bytes"),
				RawToken, Expr->StartOffset);
		}
		else
		{
			UE_LOG(LogBytecodeReader, Error,
				TEXT("Unhandled known token 0x%02X at offset %d — aborting function"),
				RawToken, Expr->StartOffset);
			bReadError = true;
		}
		break;
	}
	} // end switch

	Expr->EndOffset = Offset;
	return Expr;
}

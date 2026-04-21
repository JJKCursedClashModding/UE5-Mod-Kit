#pragma once
#include "CoreMinimal.h"
#include "EScriptPhaseStartMode.generated.h"

UENUM(BlueprintType)
enum class EScriptPhaseStartMode : uint8 {
    Top,
    ScriptSelect,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameBattleLogConditionType.generated.h"

UENUM(BlueprintType)
enum class EGameBattleLogConditionType : uint8 {
    None,
    Success_GreaterThanEquals,
    Success_LessThanEquals,
    Failure_GreaterThanEquals,
    Failure_LessThanEquals,
    Invalid = 255,
};


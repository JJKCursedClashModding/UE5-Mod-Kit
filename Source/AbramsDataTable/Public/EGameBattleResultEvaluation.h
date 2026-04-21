#pragma once
#include "CoreMinimal.h"
#include "EGameBattleResultEvaluation.generated.h"

UENUM(BlueprintType)
enum class EGameBattleResultEvaluation : uint8 {
    None,
    C,
    B,
    A,
    S,
    Invalid = 255,
};


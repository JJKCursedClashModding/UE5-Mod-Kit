#pragma once
#include "CoreMinimal.h"
#include "EGameFreeBattleFixedCursedEnergy.generated.h"

UENUM(BlueprintType)
enum class EGameFreeBattleFixedCursedEnergy : uint8 {
    None,
    Low,
    Middle,
    High,
    Max,
};


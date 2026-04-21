#pragma once
#include "CoreMinimal.h"
#include "EGameBattleDrawType.generated.h"

UENUM(BlueprintType)
enum class EGameBattleDrawType : uint8 {
    Normal,
    ForceGauge,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameBattleWidgetHPGaugeRateType.generated.h"

UENUM()
enum class EGameBattleWidgetHPGaugeRateType : int8 {
    None = -1,
    Afford = 0,
    Medium,
    Pinch,
    Dead,
};


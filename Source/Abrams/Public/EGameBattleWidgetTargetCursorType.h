#pragma once
#include "CoreMinimal.h"
#include "EGameBattleWidgetTargetCursorType.generated.h"

UENUM()
enum class EGameBattleWidgetTargetCursorType {
    None = -1,
    OutOfAttackRange = 0,
    Invincible,
    Dead,
    Max,
};


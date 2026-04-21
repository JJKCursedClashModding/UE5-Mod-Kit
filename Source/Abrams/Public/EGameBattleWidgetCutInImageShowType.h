#pragma once
#include "CoreMinimal.h"
#include "EGameBattleWidgetCutInImageShowType.generated.h"

UENUM(BlueprintType)
enum class EGameBattleWidgetCutInImageShowType : uint8 {
    None = 0,
    Center = 1,
    Left,
    Right = 4,
    Up = 8,
    Down = 16,
    All = 127,
};


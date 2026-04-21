#pragma once
#include "CoreMinimal.h"
#include "EGameBattleLogTargetType.generated.h"

UENUM(BlueprintType)
enum class EGameBattleLogTargetType : uint8 {
    None,
    Ally,
    Myself,
    Enemy,
    Invalid = 255,
};


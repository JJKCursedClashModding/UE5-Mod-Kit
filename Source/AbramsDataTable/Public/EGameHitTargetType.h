#pragma once
#include "CoreMinimal.h"
#include "EGameHitTargetType.generated.h"

UENUM(BlueprintType)
enum class EGameHitTargetType : uint8 {
    None,
    EnemyOnly,
    AllyOnly,
    All,
    Invalid = 255,
};


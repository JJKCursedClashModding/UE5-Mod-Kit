#pragma once
#include "CoreMinimal.h"
#include "EGameVsEnemyMatchingType.generated.h"

UENUM(BlueprintType)
enum class EGameVsEnemyMatchingType : uint8 {
    None,
    FreeMatching,
    ConditionMatching,
};


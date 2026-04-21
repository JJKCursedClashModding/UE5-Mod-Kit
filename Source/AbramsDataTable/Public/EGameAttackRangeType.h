#pragma once
#include "CoreMinimal.h"
#include "EGameAttackRangeType.generated.h"

UENUM(BlueprintType)
enum class EGameAttackRangeType : uint8 {
    None,
    Short,
    Long,
    Invalid = 255,
};


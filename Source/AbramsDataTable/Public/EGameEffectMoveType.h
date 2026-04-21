#pragma once
#include "CoreMinimal.h"
#include "EGameEffectMoveType.generated.h"

UENUM(BlueprintType)
enum class EGameEffectMoveType : uint8 {
    None,
    Straight,
    Target,
    Location,
    Invalid = 255,
};


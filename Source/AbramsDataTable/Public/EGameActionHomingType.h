#pragma once
#include "CoreMinimal.h"
#include "EGameActionHomingType.generated.h"

UENUM(BlueprintType)
enum class EGameActionHomingType : uint8 {
    None,
    EightWay,
    Curve,
    Warp,
    WarpMove,
    Invalid = 255,
};


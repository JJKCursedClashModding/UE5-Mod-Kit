#pragma once
#include "CoreMinimal.h"
#include "EGameEasingType.generated.h"

UENUM(BlueprintType)
enum class EGameEasingType : uint8 {
    None,
    EaseIn,
    EaseOut,
    EaseInOut,
    Invalid = 255,
};


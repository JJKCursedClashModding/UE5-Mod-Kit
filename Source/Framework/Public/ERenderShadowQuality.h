#pragma once
#include "CoreMinimal.h"
#include "ERenderShadowQuality.generated.h"

UENUM(BlueprintType)
enum class ERenderShadowQuality : uint8 {
    None = 0,
    Low = 1,
    Middle,
    High,
    Invalid = 255,
};


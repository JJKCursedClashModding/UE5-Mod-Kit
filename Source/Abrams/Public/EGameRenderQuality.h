#pragma once
#include "CoreMinimal.h"
#include "EGameRenderQuality.generated.h"

UENUM(BlueprintType)
enum class EGameRenderQuality : uint8 {
    None = 0,
    Low = 1,
    Middle,
    High,
    Invalid = 255,
};


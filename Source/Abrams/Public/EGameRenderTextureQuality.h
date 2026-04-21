#pragma once
#include "CoreMinimal.h"
#include "EGameRenderTextureQuality.generated.h"

UENUM(BlueprintType)
enum class EGameRenderTextureQuality : uint8 {
    None = 0,
    Low = 1,
    Middle,
    High,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameRenderAntiAliasing.generated.h"

UENUM(BlueprintType)
enum class EGameRenderAntiAliasing : uint8 {
    None,
    TAA,
    TSR,
    Invalid = 255,
};


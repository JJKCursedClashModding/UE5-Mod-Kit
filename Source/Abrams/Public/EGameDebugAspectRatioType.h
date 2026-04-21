#pragma once
#include "CoreMinimal.h"
#include "EGameDebugAspectRatioType.generated.h"

UENUM(BlueprintType)
enum class EGameDebugAspectRatioType : uint8 {
    Default,
    Fixed_16_9,
    Fixed_16_10,
};


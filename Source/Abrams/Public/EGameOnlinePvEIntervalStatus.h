#pragma once
#include "CoreMinimal.h"
#include "EGameOnlinePvEIntervalStatus.generated.h"

UENUM(BlueprintType)
enum class EGameOnlinePvEIntervalStatus : uint8 {
    SelectItemWaiting,
    SelectItem,
    UpdateBindingVows,
    End,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameWarpAdjustTargetSimulateType.generated.h"

UENUM(BlueprintType)
enum class EGameWarpAdjustTargetSimulateType : uint8 {
    None,
    DeviationOnlySimulate,
    BlowSimulate,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EIntervalPvEPhaseStartMode.generated.h"

UENUM(BlueprintType)
enum class EIntervalPvEPhaseStartMode : uint8 {
    Interval_Offline,
    Interval_Online,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetImpactTimingResult.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetImpactTimingResult : uint8 {
    Bad,
    Good,
    Perfect,
    Miss,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerPerformanceType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerPerformanceType : uint8 {
    None,
    Appearance,
    Result,
    Result_Personal,
    StoryDemo,
    SuperCursedEnergy,
    TagCombo,
};


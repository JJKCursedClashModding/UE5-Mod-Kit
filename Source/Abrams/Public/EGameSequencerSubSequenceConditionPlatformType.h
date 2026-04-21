#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerSubSequenceConditionPlatformType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerSubSequenceConditionPlatformType : uint8 {
    None,
    PS4,
    PS5,
    Switch = 4,
    XB1 = 8,
    XSX = 16,
    PC = 32,
    All = 63,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterVoicePriority.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterVoicePriority : uint8 {
    Lowest,
    Lower,
    Low,
    StandardLowest,
    StandardLower,
    StandardLow,
    Standard,
    StandardHigh,
    StandardHigher,
    StandardHighest,
    High,
    Higher,
    Highest,
    Invalid = 255,
};


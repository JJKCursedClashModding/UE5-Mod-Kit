#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUniquePairType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerUniquePairType : uint8 {
    None,
    Appearance,
    Result,
    Invalid = 255,
};


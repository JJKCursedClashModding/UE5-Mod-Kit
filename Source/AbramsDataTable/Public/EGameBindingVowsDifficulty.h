#pragma once
#include "CoreMinimal.h"
#include "EGameBindingVowsDifficulty.generated.h"

UENUM(BlueprintType)
enum class EGameBindingVowsDifficulty : uint8 {
    None,
    Low,
    Middle,
    High,
    Invalid = 255,
};


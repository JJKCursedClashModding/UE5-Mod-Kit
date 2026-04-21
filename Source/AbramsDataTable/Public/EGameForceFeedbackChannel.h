#pragma once
#include "CoreMinimal.h"
#include "EGameForceFeedbackChannel.generated.h"

UENUM(BlueprintType)
enum class EGameForceFeedbackChannel : uint8 {
    None,
    Left,
    Right,
    All,
    Invalid = 255,
};


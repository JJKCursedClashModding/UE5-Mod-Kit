#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCountState.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterCountState : uint8 {
    Count,
    Wait,
    Fade,
    None,
};


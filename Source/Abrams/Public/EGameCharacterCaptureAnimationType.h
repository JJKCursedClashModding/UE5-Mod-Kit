#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCaptureAnimationType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterCaptureAnimationType : uint8 {
    None,
    Idle,
    Enter,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCameraMode.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterCameraMode : uint8 {
    Free,
    Target,
    Shoot,
    Fixed,
    Invalid = 255,
};


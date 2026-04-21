#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterFacialPartsEyes.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterFacialPartsEyes : uint8 {
    None,
    Up,
    Down,
    Left,
    Right,
    UpLeft,
    UpRight,
    DownLeft,
    DownRight,
    Invalid = 255,
};


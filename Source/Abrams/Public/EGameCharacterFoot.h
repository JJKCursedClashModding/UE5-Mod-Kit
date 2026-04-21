#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterFoot.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterFoot : uint8 {
    Left,
    Right,
    LeftHand,
    RightHand,
    Back_Left,
    Back_Right,
    Back_LeftHand,
    Back_RightHand,
    Invalid = 255,
};


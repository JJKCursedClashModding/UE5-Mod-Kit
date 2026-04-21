#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterFacial.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterFacial : uint8 {
    None,
    Default,
    Damage,
    Pinch,
    Surprised,
    Dead,
    Attack_01,
    Invalid = 255,
};


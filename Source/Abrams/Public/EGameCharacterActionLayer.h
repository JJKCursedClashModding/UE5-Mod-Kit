#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterActionLayer.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterActionLayer : uint8 {
    Default,
    Attack,
    Damage,
    Invalid = 255,
};


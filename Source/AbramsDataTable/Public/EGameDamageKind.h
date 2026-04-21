#pragma once
#include "CoreMinimal.h"
#include "EGameDamageKind.generated.h"

UENUM(BlueprintType)
enum class EGameDamageKind : uint8 {
    None,
    Melee,
    Projectile,
    Throwing,
    Invalid = 255,
};


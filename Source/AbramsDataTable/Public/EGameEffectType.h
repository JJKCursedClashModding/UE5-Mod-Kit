#pragma once
#include "CoreMinimal.h"
#include "EGameEffectType.generated.h"

UENUM(BlueprintType)
enum class EGameEffectType : uint8 {
    None,
    Projectile,
    Invalid = 255,
};


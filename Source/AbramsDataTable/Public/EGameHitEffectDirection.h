#pragma once
#include "CoreMinimal.h"
#include "EGameHitEffectDirection.generated.h"

UENUM(BlueprintType)
enum class EGameHitEffectDirection : uint8 {
    None,
    HitNormal,
    MovementDirection,
    AttackerDirection,
    ActorDirection,
    Invalid = 255,
};


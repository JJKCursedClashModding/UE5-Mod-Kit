#pragma once
#include "CoreMinimal.h"
#include "EGameHitEffectLocationType.generated.h"

UENUM(BlueprintType)
enum class EGameHitEffectLocationType : uint8 {
    None,
    ImpactPoint,
    Receiver,
    HitComponent,
    Invalid = 255,
};


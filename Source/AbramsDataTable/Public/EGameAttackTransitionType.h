#pragma once
#include "CoreMinimal.h"
#include "EGameAttackTransitionType.generated.h"

UENUM(BlueprintType)
enum class EGameAttackTransitionType : uint8 {
    None,
    InputHit,
    InputHitWithoutGuard,
    InputHitWithoutJustGuard,
    Input,
    InputTiming,
    AutoHit,
    AutoHitWithoutGuard,
    AutoHitWithoutJustGuard,
    Auto,
    OnGround,
    Invalid = 255,
};


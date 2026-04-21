#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterAttackVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterAttackVoiceType : uint8 {
    Action,
    Weak,
    Weak_Medium,
    Medium,
    Heavy,
    Finish,
    Projectile,
    Charge,
    Invalid = 255,
};


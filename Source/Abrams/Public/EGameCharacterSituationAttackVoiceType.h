#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSituationAttackVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSituationAttackVoiceType : uint8 {
    DefenselessAttack,
    GuardBreakAttack,
    BoundAttack,
    Invalid = 255,
};


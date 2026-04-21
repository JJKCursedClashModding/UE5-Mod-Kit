#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterActionVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterActionVoiceType : uint8 {
    None,
    DefaultAction,
    Attack,
    NormalAttack,
    SituationAttack,
    System,
    Damage,
    SpecialDamage,
    Down,
    Guard,
    Unique,
    Invalid = 255,
};


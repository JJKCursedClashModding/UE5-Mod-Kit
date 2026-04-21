#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSpecialDamageVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSpecialDamageVoiceType : uint8 {
    None,
    THUNDER,
    RESTRAINT,
    ASSAULT,
    TRAP,
    SEALED,
    HAIRPIN,
    RESONANCE,
    ASSIST,
    PULL,
    BOOGIEWOOGIE,
    ROT_TECHNIQUE,
    SPEED_DOWN,
    CONSUME_CURSEDENERGY,
    Invalid = 255,
};


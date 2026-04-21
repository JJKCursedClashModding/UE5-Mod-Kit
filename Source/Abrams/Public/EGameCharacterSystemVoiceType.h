#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSystemVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSystemVoiceType : uint8 {
    CursedEnergyLevelUp_2,
    CursedEnergyLevelUp_3,
    CursedEnergyLevelUp_Max UMETA(Hidden),
    TagCombo_Attacker,
    LinkCombo_Receiver,
    CursedEnergyShortage,
    Kill,
    FirstHit,
    Invalid = 255,
};


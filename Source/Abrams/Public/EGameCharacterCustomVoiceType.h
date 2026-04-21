#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCustomVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterCustomVoiceType : uint8 {
    Default,
    NormalAttack,
    CursedEnergyAttack,
    Pinch,
};


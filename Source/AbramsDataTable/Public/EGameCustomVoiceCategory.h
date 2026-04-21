#pragma once
#include "CoreMinimal.h"
#include "EGameCustomVoiceCategory.generated.h"

UENUM(BlueprintType)
enum class EGameCustomVoiceCategory : uint8 {
    None,
    NormalAttack,
    CursedEnergyAttack,
    Invalid = 255,
};


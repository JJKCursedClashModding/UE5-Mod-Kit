#pragma once
#include "CoreMinimal.h"
#include "EGameDamageAdaptType.generated.h"

UENUM(BlueprintType)
enum class EGameDamageAdaptType : uint8 {
    None,
    CursedEnergyAttack_1,
    CursedEnergyAttack_2,
    ExtraAttack,
    Invalid = 255,
};


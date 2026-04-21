#pragma once
#include "CoreMinimal.h"
#include "EGameAttackType.generated.h"

UENUM(BlueprintType)
enum class EGameAttackType : uint8 {
    None,
    NormalAttack,
    CursedEnergyAttack_1,
    CursedEnergyAttack_2,
    SuperCursedEnergyAttack,
    SpecialTagCombo,
    Debuff,
    BindingVows,
    Invalid = 255,
};


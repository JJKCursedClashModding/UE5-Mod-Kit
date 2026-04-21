#pragma once
#include "CoreMinimal.h"
#include "EGameAttackTransitionKind.generated.h"

UENUM(BlueprintType)
enum class EGameAttackTransitionKind : uint8 {
    None,
    NormalAttack_1,
    NormalAttack_1_Auto,
    NormalAttack_1_1,
    NormalAttack_1_1_Auto,
    NormalAttack_2,
    NormalAttack_2_Auto,
    NormalAttack_2_1,
    NormalAttack_2_1_Auto,
    NormalAttack_3,
    NormalAttack_3_Auto,
    NormalAttack_3_1,
    NormalAttack_3_1_Auto,
    CursedEnergyAttack_1,
    CursedEnergyAttack_1_Auto,
    CursedEnergyAttack_2,
    CursedEnergyAttack_2_Auto,
    SuperCursedEnergyAttack,
    ExtraAttack_1,
    ExtraAttack_2,
    Invalid = 255,
};


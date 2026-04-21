#pragma once
#include "CoreMinimal.h"
#include "EGameCommandListWidgetAttackType.generated.h"

UENUM(BlueprintType)
enum class EGameCommandListWidgetAttackType : uint8 {
    NormalAttack_1,
    NormalAttack_1_1,
    NormalAttack_2,
    NormalAttack_2_1,
    NormalAttack_3,
    NormalAttack_3_1,
    CursedEnergyAttack_1,
    CursedEnergyAttack_2,
    SuperCursedEnergyAttack,
    ExtraAttack_CP_050,
    ExtraAttack_CP_170,
    NormalAttack_3_1_CP_210,
};


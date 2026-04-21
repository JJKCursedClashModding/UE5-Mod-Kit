#pragma once
#include "CoreMinimal.h"
#include "EGameCommandListWidgetAttackCategoryType.generated.h"

UENUM()
enum class EGameCommandListWidgetAttackCategoryType : int32 {
    NormalAttack,
    CursedEnergyAttack_Human,
    CursedEnergyAttack_Cursed,
    CursedEnergyAttack_Physical,
    CursedEnergyAttack_CP_020,
    SuperCursedEnergyAttack,
};


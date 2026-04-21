#pragma once
#include "CoreMinimal.h"
#include "EGameVsEnemyRecoverySelectMenu.generated.h"

UENUM(BlueprintType)
enum class EGameVsEnemyRecoverySelectMenu : uint8 {
    None,
    SmallHPHeal_1P,
    SmallHPHeal_2P,
    LargeHPHeal_1P,
    LargeHPHeal_2P,
    CostHeal,
    Exit,
};


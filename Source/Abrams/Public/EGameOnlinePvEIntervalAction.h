#pragma once
#include "CoreMinimal.h"
#include "EGameOnlinePvEIntervalAction.generated.h"

UENUM(BlueprintType)
enum class EGameOnlinePvEIntervalAction : uint8 {
    None,
    SmallHPHeal_1P,
    LargeHPHeal_1P,
    SmallHPHeal_2P,
    LargeHPHeal_2P,
    CostHeal,
    UpdateBindingVows,
    Invalid = 255,
};


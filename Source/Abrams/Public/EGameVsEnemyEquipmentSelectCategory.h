#pragma once
#include "CoreMinimal.h"
#include "EGameVsEnemyEquipmentSelectCategory.generated.h"

UENUM(BlueprintType)
enum class EGameVsEnemyEquipmentSelectCategory : uint8 {
    None,
    All,
    CursedTools,
    CursedObjects,
    Extras,
    Max,
};


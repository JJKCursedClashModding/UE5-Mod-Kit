#pragma once
#include "CoreMinimal.h"
#include "EGameDebrisObjectHideCondition.generated.h"

UENUM(BlueprintType)
enum class EGameDebrisObjectHideCondition : uint8 {
    None,
    All,
    Only,
};


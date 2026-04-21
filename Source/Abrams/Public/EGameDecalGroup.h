#pragma once
#include "CoreMinimal.h"
#include "EGameDecalGroup.generated.h"

UENUM(BlueprintType)
enum class EGameDecalGroup : uint8 {
    Default,
    Destructible,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EApplicationRegion.generated.h"

UENUM(BlueprintType)
enum class EApplicationRegion : uint8 {
    JP,
    EU,
    US,
    ASIA,
    Invalid = 255,
};


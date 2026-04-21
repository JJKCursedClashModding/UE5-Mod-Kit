#pragma once
#include "CoreMinimal.h"
#include "EGamePvEMode.generated.h"

UENUM(BlueprintType)
enum class EGamePvEMode : uint8 {
    None,
    Normal,
    Survival,
    Invalid = 255,
};


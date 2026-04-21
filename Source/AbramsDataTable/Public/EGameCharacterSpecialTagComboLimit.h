#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSpecialTagComboLimit.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSpecialTagComboLimit : uint8 {
    None,
    Common,
    Unique,
    Both,
    Invalid = 255,
};


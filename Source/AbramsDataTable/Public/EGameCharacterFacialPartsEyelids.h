#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterFacialPartsEyelids.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterFacialPartsEyelids : uint8 {
    None,
    Pattern_01,
    Pattern_02,
    Invalid = 255,
};


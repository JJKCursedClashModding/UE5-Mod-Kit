#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterFacialPartsBrow.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterFacialPartsBrow : uint8 {
    None,
    Pattern_01,
    Pattern_02,
    Invalid = 255,
};


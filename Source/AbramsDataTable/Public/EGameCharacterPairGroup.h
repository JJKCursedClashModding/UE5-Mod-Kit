#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterPairGroup.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterPairGroup : uint8 {
    None,
    JujutsuSorcerers,
    CursedSpirits,
    CursedWombDeathPaintings,
    Independent,
    Invalid = 255,
};


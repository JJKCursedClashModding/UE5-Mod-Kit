#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterGroup.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterGroup : uint8 {
    None,
    JujutsuSorcerers,
    CursedSpirits,
    CurseUsers,
    CursedWombDeathPaintings,
    CursedObjects,
    Invalid = 255,
};


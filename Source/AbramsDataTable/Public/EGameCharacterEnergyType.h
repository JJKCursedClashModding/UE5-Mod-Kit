#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterEnergyType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterEnergyType : uint8 {
    None,
    Cursed,
    Physical,
    Invalid = 255,
};


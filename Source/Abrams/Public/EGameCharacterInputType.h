#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterInputType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterInputType : uint8 {
    Playable,
    Playable_2P,
    Network,
    AI,
    Log,
    NonPlayable,
    Invalid = 255,
};


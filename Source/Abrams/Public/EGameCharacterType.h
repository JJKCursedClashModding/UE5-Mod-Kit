#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterType : uint8 {
    Playable,
    Playable_2P,
    Network,
    AI,
    Log,
    NonPlayable,
    Invalid = 255,
};


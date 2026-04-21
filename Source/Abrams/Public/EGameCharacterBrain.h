#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterBrain.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterBrain : uint8 {
    Playable,
    Training,
    AI,
    AI_PvE,
    AI_Arcade,
    Tutorial,
    Replay,
    Invalid = 255,
};


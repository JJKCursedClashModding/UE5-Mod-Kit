#pragma once
#include "CoreMinimal.h"
#include "EGameBattleTeam.generated.h"

UENUM(BlueprintType)
enum class EGameBattleTeam : uint8 {
    A,
    B,
    C,
    D,
    E,
    Playable = A,
    Enemy = B,
    Invalid = 255,
};


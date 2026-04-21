#pragma once
#include "CoreMinimal.h"
#include "EGameBattleMode.generated.h"

UENUM(BlueprintType)
enum class EGameBattleMode : uint8 {
    Test,
    Demo,
    Story,
    Free,
    PvP,
    PvESolo,
    PvETag,
    Replay,
    VisualLobby,
    Arcade,
    Invalid = 255,
};


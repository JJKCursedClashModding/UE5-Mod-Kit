#pragma once
#include "CoreMinimal.h"
#include "EMainMenuTopPhaseStartMode.generated.h"

UENUM(BlueprintType)
enum class EMainMenuTopPhaseStartMode : uint8 {
    Story,
    VsPlayer,
    VsEnemy,
    Lobby,
    FreeBattle,
    Collection,
    Shop,
    Arcade,
    Invalid = 255,
};


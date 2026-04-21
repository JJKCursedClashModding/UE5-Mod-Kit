#pragma once
#include "CoreMinimal.h"
#include "EGameMainMenuType.generated.h"

UENUM()
enum class EGameMainMenuType : int32 {
    Invalid = -1,
    VsPlayer = 0,
    VsEnemy,
    Lobby,
    Story,
    Arcade,
    FreeBattle,
    Shop,
    Collection,
    Default = Story,
    LoopMin = VsPlayer,
    LoopMax = Collection,
    Store,
    Exit,
};


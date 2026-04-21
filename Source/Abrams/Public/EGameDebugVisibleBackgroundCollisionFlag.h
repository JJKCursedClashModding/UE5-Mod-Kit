#pragma once
#include "CoreMinimal.h"
#include "EGameDebugVisibleBackgroundCollisionFlag.generated.h"

UENUM()
enum class EGameDebugVisibleBackgroundCollisionFlag {
    None,
    UCX_Destructible,
    UCX_GameGround,
    UCX_GameBackground = 4,
    UCX_GameRoof = 8,
    UCX_GameTransprency = 16,
    UCX_GameDestructibleRoof = 32,
    UCX_Other = 64,
    NoTransprency = 111,
    All = -1,
};


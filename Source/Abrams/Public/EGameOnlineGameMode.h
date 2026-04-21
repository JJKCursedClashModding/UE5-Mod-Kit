#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineGameMode.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineGameMode : uint8 {
    FreeMatch,
    RankMatch,
    LobbyMatch,
    NormalMode,
    SurvivalMode,
    VisualLobby,
    DebugMatch,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineLobbyPlayStyleType.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineLobbyPlayStyleType : uint8 {
    None,
    Anything,
    RankMatch,
    FreeMatch,
    PvE,
    LobbyMatch,
    LobbyPlay,
};


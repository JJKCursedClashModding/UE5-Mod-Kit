#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetBattleTitleType.generated.h"

UENUM()
enum class EGameWidgetBattleTitleType : int32 {
    PvPLobbyMatch,
    PvPFreeMatch,
    PvPRankMatch,
    PvERush,
    PvESurvival,
    Free,
    Arcade,
    Invalid,
};


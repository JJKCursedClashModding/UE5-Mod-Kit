#pragma once
#include "CoreMinimal.h"
#include "EGameBattlePauseMenuWidgetHideFlag.generated.h"

UENUM()
enum class EGameBattlePauseMenuWidgetHideFlag {
    None,
    ReturnBattle = 4,
    Retry = 8,
    CommandList = 16,
    Config = 32,
    MainMenu = 64,
    StoryMissionSelect = 128,
    Lobby = 256,
    FreeBattle = 512,
    Replay = 1024,
    PvE = 2048,
    Arcade = 4096,
    Invalid = -1,
};


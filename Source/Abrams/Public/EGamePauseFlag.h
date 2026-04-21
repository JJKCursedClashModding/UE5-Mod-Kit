#pragma once
#include "CoreMinimal.h"
#include "EGamePauseFlag.generated.h"

UENUM()
enum class EGamePauseFlag : uint32 {
    None,
    StoryDemoPauseMenu,
    BattlePauseMenu,
    BattleNetworkError = 4,
    BattleResult = 8,
    StoryDemoShortCredit = 16,
    DebugMenu = 32,
    DebugCamera = 64,
    ModalDialog = 128,
    Hardware = 256,
    FrameAdvance = 512,
    Battle = 14,
    StoryDemo = 17,
};


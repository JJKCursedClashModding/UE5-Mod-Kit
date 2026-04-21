#pragma once
#include "CoreMinimal.h"
#include "EGameBattlePauseMenu.generated.h"

UENUM(BlueprintType)
enum class EGameBattlePauseMenu : uint8 {
    None,
    Retry,
    StoryMissionSelect,
    MainMenu,
    Lobby,
};


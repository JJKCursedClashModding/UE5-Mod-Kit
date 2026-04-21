#pragma once
#include "CoreMinimal.h"
#include "EGameStoryMissionSelectMenu.generated.h"

UENUM(BlueprintType)
enum class EGameStoryMissionSelectMenu : uint8 {
    None,
    Back,
    MainMenu,
    BattleSetting,
    CorrelationDiagram,
    ChangeChapter,
};


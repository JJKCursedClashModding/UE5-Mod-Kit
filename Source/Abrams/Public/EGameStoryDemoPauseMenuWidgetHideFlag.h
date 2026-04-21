#pragma once
#include "CoreMinimal.h"
#include "EGameStoryDemoPauseMenuWidgetHideFlag.generated.h"

UENUM()
enum class EGameStoryDemoPauseMenuWidgetHideFlag {
    None,
    ReturnDemo = 2,
    Skip = 4,
    StoryMissionSelect = 8,
    StoryCorrelationDiagram = 16,
    Collection = 32,
    Config = 64,
    All = -1,
};


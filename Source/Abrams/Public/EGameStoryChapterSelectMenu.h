#pragma once
#include "CoreMinimal.h"
#include "EGameStoryChapterSelectMenu.generated.h"

UENUM(BlueprintType)
enum class EGameStoryChapterSelectMenu : uint8 {
    None,
    Back,
    MainMenu,
    MissionSelect,
    CorrelationDiagram,
    Store,
};


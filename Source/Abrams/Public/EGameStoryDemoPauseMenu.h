#pragma once
#include "CoreMinimal.h"
#include "EGameStoryDemoPauseMenu.generated.h"

UENUM(BlueprintType)
enum class EGameStoryDemoPauseMenu : uint8 {
    None,
    Skip,
    MissionSelect,
    CorrelationDiagram,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameBattleWidgetFinishType.generated.h"

UENUM(BlueprintType)
enum class EGameBattleWidgetFinishType : uint8 {
    Normal,
    StoryMission,
    Wave,
    PvEMission,
    PvENormalMode,
    PvESurvivalMode,
    PvEExtraMission,
};


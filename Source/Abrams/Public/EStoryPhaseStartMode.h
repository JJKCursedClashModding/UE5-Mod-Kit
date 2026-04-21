#pragma once
#include "CoreMinimal.h"
#include "EStoryPhaseStartMode.generated.h"

UENUM(BlueprintType)
enum class EStoryPhaseStartMode : uint8 {
    Top,
    ChapterSelect,
    MissionSelect,
    CorrelationDiagram,
    DlcChapterSelect,
    DlcMissionSelect,
    Invalid = 255,
};


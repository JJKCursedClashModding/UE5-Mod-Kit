#pragma once
#include "CoreMinimal.h"
#include "EGameItemType.generated.h"

UENUM(BlueprintType)
enum class EGameItemType : uint8 {
    None,
    Money,
    ShortStory,
    Costume,
    Title,
    Nickname,
    Emblem,
    Plate,
    CursedTools,
    CursedObjects,
    Extras,
    CustomVoice,
    SituationOverviewPose,
    StoryDemoMovie,
    Character,
    Invalid = 255,
};


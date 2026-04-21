#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerWidgetType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerWidgetType : uint8 {
    None,
    StoryDemoLogo_01,
    StoryDemoLogo_02,
    StoryDemoSubtitle,
    StoryDemoCenterSubtitle,
    FramePause,
};


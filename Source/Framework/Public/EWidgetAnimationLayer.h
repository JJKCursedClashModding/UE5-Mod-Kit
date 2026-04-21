#pragma once
#include "CoreMinimal.h"
#include "EWidgetAnimationLayer.generated.h"

UENUM()
enum class EWidgetAnimationLayer : uint32 {
    Layer00,
    Layer01,
    Layer02,
    Layer03,
    Max,
    Default = Layer01,
    Transition = Layer01,
    Idle = Layer00,
    CustomTrack = Layer02,
};


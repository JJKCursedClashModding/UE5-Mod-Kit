#pragma once
#include "CoreMinimal.h"
#include "EGameSceneCaptureTraceMode.generated.h"

UENUM(BlueprintType)
enum class EGameSceneCaptureTraceMode : uint8 {
    None,
    Actor,
    Camera,
    LevelSequenceCamera,
    Disable,
    Component,
};


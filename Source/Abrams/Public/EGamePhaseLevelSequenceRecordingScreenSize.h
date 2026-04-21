#pragma once
#include "CoreMinimal.h"
#include "EGamePhaseLevelSequenceRecordingScreenSize.generated.h"

UENUM(BlueprintType)
enum class EGamePhaseLevelSequenceRecordingScreenSize : uint8 {
    X_3840_Y_2160,
    X_2560_Y_1440,
    X_1920_Y_1080,
    X_1280_Y_720,
    X_3840_Y_2400,
    X_2560_Y_1600,
    X_1920_Y_1200,
    X_1280_Y_800,
};


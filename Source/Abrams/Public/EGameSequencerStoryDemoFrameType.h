#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerStoryDemoFrameType.generated.h"

UENUM()
enum class EGameSequencerStoryDemoFrameType : int32 {
    None,
    Line,
    Recollection,
    Report,
};


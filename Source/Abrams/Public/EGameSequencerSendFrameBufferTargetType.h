#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerSendFrameBufferTargetType.generated.h"

UENUM()
enum class EGameSequencerSendFrameBufferTargetType : int32 {
    None,
    ScreenBreak,
    Pause,
    PostProcess,
};


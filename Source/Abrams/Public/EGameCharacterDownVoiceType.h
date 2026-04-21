#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterDownVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterDownVoiceType : uint8 {
    Bounded,
    Down,
    DownEnd,
    BreakFall,
    Dead,
    Revival,
    Revival_Pinch,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerSoundType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerSoundType : uint8 {
    Bgm,
    Se,
    Voice,
};


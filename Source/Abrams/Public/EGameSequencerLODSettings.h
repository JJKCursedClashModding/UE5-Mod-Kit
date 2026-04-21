#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerLODSettings.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerLODSettings : uint8 {
    Enable,
    ForceZero,
    ForceOne,
    Default = Enable,
};


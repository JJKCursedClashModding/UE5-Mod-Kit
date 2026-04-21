#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionSoundDecisionType.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionSoundDecisionType : uint8 {
    None,
    Play,
    Pause,
};


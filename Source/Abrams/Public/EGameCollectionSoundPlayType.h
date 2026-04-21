#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionSoundPlayType.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionSoundPlayType : uint8 {
    None,
    Default,
    Repeat,
    Random,
};


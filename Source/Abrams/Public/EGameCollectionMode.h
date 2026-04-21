#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionMode.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionMode : uint8 {
    None,
    Record,
    Replay,
    Archive,
    Sound,
    Cancel,
};


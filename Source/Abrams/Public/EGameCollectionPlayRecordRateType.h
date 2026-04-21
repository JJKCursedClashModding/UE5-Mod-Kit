#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionPlayRecordRateType.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionPlayRecordRateType : uint8 {
    None,
    PvP,
    PvE,
};


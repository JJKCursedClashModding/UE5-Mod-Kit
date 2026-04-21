#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionPlayRecordItemType.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionPlayRecordItemType : uint8 {
    None,
    Integer,
    Floating,
    Text,
};


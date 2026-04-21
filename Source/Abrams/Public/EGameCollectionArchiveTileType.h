#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionArchiveTileType.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionArchiveTileType : uint8 {
    None,
    Default,
    Detail,
    ListText,
    ListImage,
};


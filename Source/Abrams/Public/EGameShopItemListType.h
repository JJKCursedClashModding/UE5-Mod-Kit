#pragma once
#include "CoreMinimal.h"
#include "EGameShopItemListType.generated.h"

UENUM(BlueprintType)
enum class EGameShopItemListType : uint8 {
    None,
    Thumbnail,
    TwoLineLabel,
    Label,
};


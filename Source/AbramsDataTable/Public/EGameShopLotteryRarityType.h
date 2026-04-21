#pragma once
#include "CoreMinimal.h"
#include "EGameShopLotteryRarityType.generated.h"

UENUM(BlueprintType)
enum class EGameShopLotteryRarityType : uint8 {
    None,
    Bronze,
    Silver,
    Gold,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameShopCharacterAnimationType.generated.h"

UENUM(BlueprintType)
enum class EGameShopCharacterAnimationType : uint8 {
    None,
    Idle,
    Purchased,
    PurchasedToIdle,
};


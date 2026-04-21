#pragma once
#include "CoreMinimal.h"
#include "EGameShopMenuSelectType.generated.h"

UENUM(BlueprintType)
enum class EGameShopMenuSelectType : uint8 {
    None,
    SelectItem,
    OpenPurchaseDialog,
    PurchaseDialogYes,
    PurchaseDialogNo,
    SelectLottery,
    LotteryDialogYes,
    LotteryDialogNo,
    LotteryAnimation,
    LotteryResult,
    Cancel,
};


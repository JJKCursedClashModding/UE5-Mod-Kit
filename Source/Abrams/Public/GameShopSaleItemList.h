#pragma once
#include "CoreMinimal.h"
#include "GameShopSaleItemList.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FGameShopSaleItemList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> SaleItemList;
    
    ABRAMS_API FGameShopSaleItemList();
};


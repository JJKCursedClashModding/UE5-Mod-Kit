#pragma once
#include "CoreMinimal.h"
#include "GameWidgetPaginationListView.h"
#include "GameShopSaleItemPaginationListWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopSaleItemPaginationListWidgetBase : public UGameWidgetPaginationListView {
    GENERATED_BODY()
public:
    UGameShopSaleItemPaginationListWidgetBase();

};


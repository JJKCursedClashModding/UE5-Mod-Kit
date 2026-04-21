#pragma once
#include "CoreMinimal.h"
#include "GameWidgetRecyclerListView.h"
#include "GameShopSaleItemRecyclerListWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopSaleItemRecyclerListWidgetBase : public UGameWidgetRecyclerListView {
    GENERATED_BODY()
public:
    UGameShopSaleItemRecyclerListWidgetBase();

};


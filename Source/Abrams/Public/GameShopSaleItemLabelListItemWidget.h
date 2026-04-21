#pragma once
#include "CoreMinimal.h"
#include "GameShopSaleItemListItemWidgetBase.h"
#include "GameShopSaleItemLabelListItemWidget.generated.h"

class UBorder;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopSaleItemLabelListItemWidget : public UGameShopSaleItemListItemWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ItemSetNameLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* PriceLabelBorder;
    
public:
    UGameShopSaleItemLabelListItemWidget();

};


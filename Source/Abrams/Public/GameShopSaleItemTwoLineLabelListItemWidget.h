#pragma once
#include "CoreMinimal.h"
#include "GameShopSaleItemListItemWidgetBase.h"
#include "GameShopSaleItemTwoLineLabelListItemWidget.generated.h"

class UBorder;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopSaleItemTwoLineLabelListItemWidget : public UGameShopSaleItemListItemWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ItemNameFirstLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ItemNameSecondLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* PriceLabelBorder;
    
public:
    UGameShopSaleItemTwoLineLabelListItemWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameShopItemDescriptionTextWidget.generated.h"

class UGameItemDescriptionTextWidget;
class UGameWidgetRichTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopItemDescriptionTextWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameItemDescriptionTextWidget* DescriptionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetRichTextBlock* ItemPriceText;
    
public:
    UGameShopItemDescriptionTextWidget();

};


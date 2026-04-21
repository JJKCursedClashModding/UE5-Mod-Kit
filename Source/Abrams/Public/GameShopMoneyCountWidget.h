#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameShopMoneyCountWidget.generated.h"

class UGameWidgetRichTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopMoneyCountWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* HaveMoneyCountText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* PurchasedMoneyCountText;
    
public:
    UGameShopMoneyCountWidget();

};


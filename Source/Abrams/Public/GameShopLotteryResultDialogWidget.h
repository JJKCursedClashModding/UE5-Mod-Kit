#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameShopLotteryResultDialogWidget.generated.h"

class UGameWidgetButton;
class UGameWidgetImage;
class UGameWidgetRichTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopLotteryResultDialogWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ItemImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* ResultMessageText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* CloseButton;
    
public:
    UGameShopLotteryResultDialogWidget();

};


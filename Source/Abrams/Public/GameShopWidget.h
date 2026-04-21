#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameShopWidget.generated.h"

class UGameItemThumbnailWidget;
class UGameShopCharacterImageWidget;
class UGameShopItemCategoryListWidget;
class UGameShopItemDescriptionTextWidget;
class UGameShopLotteryWidget;
class UGameShopPurchaseConfirmDialogWidget;
class UGameWidgetRichTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopCharacterImageWidget* CharacterImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* HaveMoneyCountText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListWidget* ItemCategoryList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameItemThumbnailWidget* ItemThumbnail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemDescriptionTextWidget* ItemDescriptionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopPurchaseConfirmDialogWidget* PurchaseConfirmDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopLotteryWidget* LotteryWindow;
    
public:
    UGameShopWidget();

};


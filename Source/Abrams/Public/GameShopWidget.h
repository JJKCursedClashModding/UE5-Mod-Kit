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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameShopCharacterImageWidget* CharacterImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetRichTextBlock* HaveMoneyCountText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameShopItemCategoryListWidget* ItemCategoryList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameItemThumbnailWidget* ItemThumbnail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameShopItemDescriptionTextWidget* ItemDescriptionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameShopPurchaseConfirmDialogWidget* PurchaseConfirmDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameShopLotteryWidget* LotteryWindow;
    
public:
    UGameShopWidget();

};


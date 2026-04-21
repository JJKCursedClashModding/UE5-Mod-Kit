#pragma once
#include "CoreMinimal.h"
#include "EGameItemType.h"
#include "GameShopSaleItemList.h"
#include "GameWidgetTabWindow.h"
#include "GameShopItemCategoryListWidget.generated.h"

class UGameInputGuideButtonWidget;
class UGameShopItemCategoryListItemWidget;
class UGameShopSaleItemLabelListWidget;
class UGameShopSaleItemThumbnailListWidget;
class UGameShopSaleItemTwoLineLabelListWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopItemCategoryListWidget : public UGameWidgetTabWindow {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameItemType> CategorySortOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameInputGuideButtonWidget* InputGuideLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameInputGuideButtonWidget* InputGuideRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* MoneyButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* ShortStoryButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CostumeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* TitleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* NicknameButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* EmblemButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* PlateButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CursedToolsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CursedObjectsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* ExtrasButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CustomVoiceButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* SituationOverviewPoseButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* StoryDemoMovieButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopSaleItemThumbnailListWidget* ThumbnailList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopSaleItemLabelListWidget* LabelList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopSaleItemTwoLineLabelListWidget* TwoLineLabelList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<EGameItemType, FGameShopSaleItemList> CategorySaleItemListMap;
    
public:
    UGameShopItemCategoryListWidget();

};


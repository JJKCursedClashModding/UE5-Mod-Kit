#pragma once
#include "CoreMinimal.h"
#include "GameWidgetTabWindow.h"
#include "GameCollectionArchiveSelectWidget.generated.h"

class UGameInputGuideButtonWidget;
class UGameShopItemCategoryListItemWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionArchiveSelectWidget : public UGameWidgetTabWindow {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameInputGuideButtonWidget* InputGuideLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameInputGuideButtonWidget* InputGuideRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CursedToolsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CursedObjectsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* ExtrasButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CostumeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* SituationOverviewPoseButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* PlateButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* TitleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* NicknameButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* EmblemButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* StoryDemoMovieButton;
    
public:
    UGameCollectionArchiveSelectWidget();

};


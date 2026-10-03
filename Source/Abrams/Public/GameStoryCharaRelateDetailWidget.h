#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryCharaRelateDetailWidget.generated.h"

class UCanvasPanel;
class UGameStoryCharaRelateDetailGaugeWidget;
class UGameStoryCharaRelateDetailIconWidget;
class UGameStoryCharaRelateMissionListItemData;
class UGameStoryCharaRelateMissionListViewWidget;
class UGameStoryCharaRelateRewardViewWidget;
class UGameStoryCharaRelateShortStoryListItemData;
class UGameStoryCharaRelateShortStoryListViewWidget;
class UGameWidgetButton;
class UGameWidgetInputImageButton;
class UGameWidgetStoryCharaRelateTabButton;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryCharaRelateDetailWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateDetailGaugeWidget* ToSecondCharacterGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateDetailGaugeWidget* FromSecondCharacterGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateDetailIconWidget* CharacterIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateDetailIconWidget* SecondCharacterIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ChangeListViewText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ChangeRewardViewText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ListCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetInputImageButton* ChangeListModeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetStoryCharaRelateTabButton* MissionTabButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetStoryCharaRelateTabButton* ShortStoryTabButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetButton* LeftButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetButton* RightButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateMissionListViewWidget* MissionListViewWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateShortStoryListViewWidget* ShortStoryListViewWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateRewardViewWidget* RewardViewWidget;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameStoryCharaRelateMissionListItemData*> MissionListItemDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameStoryCharaRelateShortStoryListItemData*> ShortStoryListItemDataArray;
    
public:
    UGameStoryCharaRelateDetailWidget();

};


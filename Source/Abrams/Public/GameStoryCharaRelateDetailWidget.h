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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaRelateDetailGaugeWidget* ToSecondCharacterGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaRelateDetailGaugeWidget* FromSecondCharacterGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaRelateDetailIconWidget* CharacterIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaRelateDetailIconWidget* SecondCharacterIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ChangeListViewText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ChangeRewardViewText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ListCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImageButton* ChangeListModeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetStoryCharaRelateTabButton* MissionTabButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetStoryCharaRelateTabButton* ShortStoryTabButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* LeftButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* RightButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaRelateMissionListViewWidget* MissionListViewWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaRelateShortStoryListViewWidget* ShortStoryListViewWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaRelateRewardViewWidget* RewardViewWidget;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameStoryCharaRelateMissionListItemData*> MissionListItemDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameStoryCharaRelateShortStoryListItemData*> ShortStoryListItemDataArray;
    
public:
    UGameStoryCharaRelateDetailWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameRankSystemRewardWidget.generated.h"

class UCanvasPanel;
class UGameRankSystemRewardListViewWidget;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankSystemRewardWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TotalResultScoreText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* CompletePanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankSystemRewardListViewWidget* RewardListView;
    
public:
    UGameRankSystemRewardWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameRankingWidgetBase.h"
#include "GameRankingPvEWidget.generated.h"

class UGameRankingListViewWidget;
class UGameRankingTypeSelectButtonWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankingPvEWidget : public UGameRankingWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingListViewWidget* NormalModeScoreRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingListViewWidget* SurvivalModeScoreRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingListViewWidget* HighestTotalDamageRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingListViewWidget* AchievedTaskCountRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingTypeSelectButtonWidget* NormalModeScoreRankingSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingTypeSelectButtonWidget* SurvivalModeScoreRankingSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingTypeSelectButtonWidget* HighestTotalDamageSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingTypeSelectButtonWidget* AchievedTaskCountSelectButton;
    
public:
    UGameRankingPvEWidget();

};


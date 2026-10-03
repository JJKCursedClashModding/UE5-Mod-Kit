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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingListViewWidget* NormalModeScoreRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingListViewWidget* SurvivalModeScoreRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingListViewWidget* HighestTotalDamageRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingListViewWidget* AchievedTaskCountRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingTypeSelectButtonWidget* NormalModeScoreRankingSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingTypeSelectButtonWidget* SurvivalModeScoreRankingSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingTypeSelectButtonWidget* HighestTotalDamageSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingTypeSelectButtonWidget* AchievedTaskCountSelectButton;
    
public:
    UGameRankingPvEWidget();

};


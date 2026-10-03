#pragma once
#include "CoreMinimal.h"
#include "GameRankingWidgetBase.h"
#include "GameRankingPvPWidget.generated.h"

class UGameRankingListViewWidget;
class UGameRankingTypeSelectButtonWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankingPvPWidget : public UGameRankingWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingListViewWidget* ScoreRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingListViewWidget* BattleWinCountRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingListViewWidget* BattleCountRankingListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingTypeSelectButtonWidget* ScoreRankingSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingTypeSelectButtonWidget* BattleWinCountSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingTypeSelectButtonWidget* BattleCountSelectButton;
    
public:
    UGameRankingPvPWidget();

};


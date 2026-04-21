#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameRankSystemWidget.generated.h"

class UGameRankSystemManualWidget;
class UGameRankSystemRankPanelWidget;
class UGameRankSystemRewardWidget;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankSystemWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankSystemRewardWidget* RewardWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankSystemRankPanelWidget* RankPanelWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* BattleCountText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* WinCountText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankSystemManualWidget* RankSystemManualWidget;
    
public:
    UGameRankSystemWidget();

};


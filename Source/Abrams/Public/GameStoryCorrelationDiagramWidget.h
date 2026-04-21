#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryCorrelationDiagramWidget.generated.h"

class UGameStoryCharaGraphWidget;
class UGameStoryCharaRelateWidget;
class UGameStoryEarnedRewardListWidget;
class UGameStoryEarnedRewardNotifyWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryCorrelationDiagramWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaGraphWidget* CharaGraphWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharaRelateWidget* CharaRelateWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryEarnedRewardListWidget* EarnedRewardListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryEarnedRewardNotifyWidget* EarnedRewardNotifyWidget;
    
public:
    UGameStoryCorrelationDiagramWidget();

};


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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaGraphWidget* CharaGraphWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateWidget* CharaRelateWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryEarnedRewardListWidget* EarnedRewardListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryEarnedRewardNotifyWidget* EarnedRewardNotifyWidget;
    
public:
    UGameStoryCorrelationDiagramWidget();

};


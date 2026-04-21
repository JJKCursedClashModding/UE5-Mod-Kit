#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryEarnedRewardListWidget.generated.h"

class UGameStoryEarnedRewardListItemData;
class UGameStoryEarnedRewardListViewWidget;
class UGameWidgetStoryEarnedRewardCloseButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryEarnedRewardListWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryEarnedRewardListViewWidget* ListViewWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetStoryEarnedRewardCloseButton* CloseButton;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameStoryEarnedRewardListItemData*> EarnedRewardListItemDataArray;
    
public:
    UGameStoryEarnedRewardListWidget();

};


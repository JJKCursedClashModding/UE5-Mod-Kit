#pragma once
#include "CoreMinimal.h"
#include "GameRankingListViewItemWidgetBase.h"
#include "GameRankingListViewItemWidget.generated.h"

class UGameWidgetTextBlock;
class UOverlay;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankingListViewItemWidget : public UGameRankingListViewItemWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* IntegerText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* PercentText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* On;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Off;
    
public:
    UGameRankingListViewItemWidget();

};


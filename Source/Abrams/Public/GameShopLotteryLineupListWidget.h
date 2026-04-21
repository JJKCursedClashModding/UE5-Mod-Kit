#pragma once
#include "CoreMinimal.h"
#include "GameWidgetPaginationListView.h"
#include "GameShopLotteryLineupListWidget.generated.h"

class UGameShopLotteryLineupListItemData;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopLotteryLineupListWidget : public UGameWidgetPaginationListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UGameShopLotteryLineupListItemData*> LineupItemDataList;
    
public:
    UGameShopLotteryLineupListWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameWidgetScrollListItem.h"
#include "GameRankingListViewItemWidgetBase.generated.h"

class UGamePlayerRankWidget;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankingListViewItemWidgetBase : public UGameWidgetButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGamePlayerRankWidget* PlayerRankIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* PlayerRankNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* RankNumberText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* PlayerNameText;
    
public:
    UGameRankingListViewItemWidgetBase();


    // Fix for true pure virtual functions not being implemented
};


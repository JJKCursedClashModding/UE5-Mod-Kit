#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameWidgetScrollListItem.h"
#include "GameRewardMessageListItemWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetRichTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRewardMessageListItemWidget : public UGameWidgetBase, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ItemCategoryImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* RewardMessageText;
    
public:
    UGameRewardMessageListItemWidget();


    // Fix for true pure virtual functions not being implemented
};


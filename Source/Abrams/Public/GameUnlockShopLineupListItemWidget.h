#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameWidgetScrollListItem.h"
#include "GameUnlockShopLineupListItemWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameUnlockShopLineupListItemWidget : public UGameWidgetBase, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ItemCategoryImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* UnlockMessageText;
    
public:
    UGameUnlockShopLineupListItemWidget();


    // Fix for true pure virtual functions not being implemented
};


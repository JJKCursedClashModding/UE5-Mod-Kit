#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameWidgetScrollListItem.h"
#include "GameUnlockDlcContentListItemWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameUnlockDlcContentListItemWidget : public UGameWidgetBase, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* UnlockMessageText;
    
public:
    UGameUnlockDlcContentListItemWidget();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "WidgetListItem.h"
#include "GameWidgetButton.h"
#include "DebugLevelSequencerListItemWidget.generated.h"

class UDebugWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UDebugLevelSequencerListItemWidget : public UGameWidgetButton, public IWidgetListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetTextBlock* Text;
    
public:
    UDebugLevelSequencerListItemWidget();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameWidgetScrollListItem.h"
#include "DebugScriptListItemWidget.generated.h"

class UDebugWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UDebugScriptListItemWidget : public UGameWidgetButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetTextBlock* Text;
    
public:
    UDebugScriptListItemWidget();


    // Fix for true pure virtual functions not being implemented
};


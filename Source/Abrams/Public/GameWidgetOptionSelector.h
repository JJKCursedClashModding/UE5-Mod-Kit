#pragma once
#include "CoreMinimal.h"
#include "WidgetOptionBoxBase.h"
#include "GameWidgetOptionSelector.generated.h"

class UPanelWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetOptionSelector : public UWidgetOptionBoxBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* ButtonPanel;
    
public:
    UGameWidgetOptionSelector();

};


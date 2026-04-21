#pragma once
#include "CoreMinimal.h"
#include "WidgetListView.h"
#include "WidgetComboBoxListView.generated.h"

class UCanvasPanelSlot;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetComboBoxListView : public UWidgetListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanelSlot* RootSlot;
    
public:
    UWidgetComboBoxListView();

};


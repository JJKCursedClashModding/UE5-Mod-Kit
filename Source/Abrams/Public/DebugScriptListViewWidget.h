#pragma once
#include "CoreMinimal.h"
#include "GameWidgetScrollListView.h"
#include "DebugScriptListViewWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UDebugScriptListViewWidget : public UGameWidgetScrollListView {
    GENERATED_BODY()
public:
    UDebugScriptListViewWidget();

};


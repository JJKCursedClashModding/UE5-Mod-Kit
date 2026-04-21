#pragma once
#include "CoreMinimal.h"
#include "WidgetComboBoxListView.h"
#include "DebugWidgetComboBoxListView.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetComboBoxListView : public UWidgetComboBoxListView {
    GENERATED_BODY()
public:
    UDebugWidgetComboBoxListView();

};


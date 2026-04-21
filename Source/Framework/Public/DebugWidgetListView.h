#pragma once
#include "CoreMinimal.h"
#include "WidgetListView.h"
#include "DebugWidgetListView.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetListView : public UWidgetListView {
    GENERATED_BODY()
public:
    UDebugWidgetListView();

};


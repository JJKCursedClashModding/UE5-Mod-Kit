#pragma once
#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "WidgetListItem.h"
#include "WidgetListViewDesignerPreviewContent.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWidgetListViewDesignerPreviewContent : public UWidgetBase, public IWidgetListItem {
    GENERATED_BODY()
public:
    UWidgetListViewDesignerPreviewContent();


    // Fix for true pure virtual functions not being implemented
};


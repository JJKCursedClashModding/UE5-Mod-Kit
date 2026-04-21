#pragma once
#include "CoreMinimal.h"
#include "WidgetActivatable.h"
#include "WidgetBase.h"
#include "WidgetEnterable.h"
#include "WidgetInputReceive.h"
#include "WidgetLocalization.h"
#include "WidgetMouseInputReceive.h"
#include "WidgetSelectable.h"
#include "WidgetTransition.h"
#include "WidgetTransitionable.h"
#include "WindowBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UWindowBase : public UWidgetBase, public IWidgetEnterable, public IWidgetInputReceive, public IWidgetLocalization, public IWidgetMouseInputReceive, public IWidgetSelectable, public IWidgetTransition, public IWidgetTransitionable, public IWidgetActivatable {
    GENERATED_BODY()
public:
    UWindowBase();


    // Fix for true pure virtual functions not being implemented
};


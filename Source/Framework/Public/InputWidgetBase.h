#pragma once
#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "WidgetFocusable.h"
#include "WidgetHoverable.h"
#include "WidgetMouseInputReceive.h"
#include "WidgetSelectable.h"
#include "WidgetTransitionable.h"
#include "InputWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UInputWidgetBase : public UWidgetBase, public IWidgetFocusable, public IWidgetHoverable, public IWidgetMouseInputReceive, public IWidgetSelectable, public IWidgetTransitionable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsWidgetFocusable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsWidgetHoverable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNavigationEnabled;
    
public:
    UInputWidgetBase();


    // Fix for true pure virtual functions not being implemented
};


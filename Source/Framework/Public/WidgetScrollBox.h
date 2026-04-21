#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "Components/ScrollBox.h"
#include "WidgetHoverable.h"
#include "WidgetMouseInputReceive.h"
#include "WidgetSelectable.h"
#include "WidgetWorldTickable.h"
#include "WidgetScrollBox.generated.h"

UCLASS(Abstract, Blueprintable)
class FRAMEWORK_API UWidgetScrollBox : public UScrollBox, public IWidgetHoverable, public IWidgetMouseInputReceive, public IWidgetSelectable, public IWidgetWorldTickable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScrollBarStyle CustomBarStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUserScrollEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoHiddenEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReverseScrollBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavigationValue;
    
public:
    UWidgetScrollBox();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "InputWidgetBase.h"
#include "WidgetEnterable.h"
#include "WidgetButton.generated.h"

class UImage;
class UWidgetProgressBar;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetButton : public UInputWidgetBase, public IWidgetEnterable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonStyle ButtonStyle;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ButtonImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDecisionButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetProgressBar* HoldProgressBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldTime;
    
public:
    UWidgetButton();


    // Fix for true pure virtual functions not being implemented
};


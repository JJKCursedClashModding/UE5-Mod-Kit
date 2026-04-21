#pragma once
#include "CoreMinimal.h"
#include "WidgetInputReceive.h"
#include "WidgetSlider.h"
#include "DebugWidgetSlider.generated.h"

class UWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetSlider : public UWidgetSlider, public IWidgetInputReceive {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetTextBlock* ValueText;
    
public:
    UDebugWidgetSlider();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "WidgetInputReceive.h"
#include "WidgetSlider.h"
#include "GameWidgetSlider.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetSlider : public UWidgetSlider, public IWidgetInputReceive {
    GENERATED_BODY()
public:
    UGameWidgetSlider();


    // Fix for true pure virtual functions not being implemented
};


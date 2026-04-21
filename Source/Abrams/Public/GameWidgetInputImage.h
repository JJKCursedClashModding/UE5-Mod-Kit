#pragma once
#include "CoreMinimal.h"
#include "WidgetInputImage.h"
#include "GameWidgetInputGuide.h"
#include "GameWidgetInputImage.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetInputImage : public UWidgetInputImage, public IGameWidgetInputGuide {
    GENERATED_BODY()
public:
    UGameWidgetInputImage();


    // Fix for true pure virtual functions not being implemented
};


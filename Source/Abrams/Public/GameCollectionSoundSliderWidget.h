#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCollectionSoundSliderWidget.generated.h"

class UGameWidgetProgressBar;
class UGameWidgetSlider;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionSoundSliderWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TimeText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetSlider* SoundSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetProgressBar* SoundProgressBar;
    
public:
    UGameCollectionSoundSliderWidget();

};


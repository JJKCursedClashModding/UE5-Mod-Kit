#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameWidgetInputGuide.h"
#include "GameInputGuideButtonWidget.generated.h"

class UGameHoldGaugeWidget;
class UGameWidgetAutonomousButton;
class UGameWidgetInputGuideText;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameInputGuideButtonWidget : public UGameWidgetBase, public IGameWidgetInputGuide {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* InputGuideText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetAutonomousButton* InputGuideButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameHoldGaugeWidget* HoldGauge;
    
public:
    UGameInputGuideButtonWidget();


    // Fix for true pure virtual functions not being implemented
};


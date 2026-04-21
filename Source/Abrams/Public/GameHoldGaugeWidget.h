#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameHoldGaugeWidget.generated.h"

class UGameWidgetProgressBar;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameHoldGaugeWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetProgressBar* HoldGauge;
    
public:
    UGameHoldGaugeWidget();

};


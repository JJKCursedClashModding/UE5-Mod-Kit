#pragma once
#include "CoreMinimal.h"
#include "GameWidgetInputImageButton.h"
#include "GameWidgetMappingInputReceive.h"
#include "GameStoryDemoFooterButtonWidget.generated.h"

class UGameHoldGaugeWidget;
class UPanelWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryDemoFooterButtonWidget : public UGameWidgetInputImageButton, public IGameWidgetMappingInputReceive {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* RootPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameHoldGaugeWidget* HoldGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float PanelScale;
    
public:
    UGameStoryDemoFooterButtonWidget();


    // Fix for true pure virtual functions not being implemented
};


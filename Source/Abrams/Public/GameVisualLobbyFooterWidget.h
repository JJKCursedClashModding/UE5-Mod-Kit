#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameVisualLobbyFooterWidget.generated.h"

class UCanvasPanel;
class UGameHoldGaugeWidget;
class UGameWidgetInputGuideText;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyFooterWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* WidgetDispSwitchText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* CameraModeSwitchText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* StartBattleCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameHoldGaugeWidget* HoldGauge;
    
public:
    UGameVisualLobbyFooterWidget();

};


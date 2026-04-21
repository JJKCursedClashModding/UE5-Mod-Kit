#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetGaugeThreshold.h"
#include "GameWidgetBattleTeamColorParameter.h"
#include "GameWidgetColorParameter.h"
#include "GameWindowBase.h"
#include "GameBattleWidget.generated.h"

class UGameBattleAlertWidget;
class UGameBattleHUDWidget;
class UGameBattleMarkerWidget;
class UGameBattleOverlayWidget;
class UGameBattlePostProcessEffectWidget;
class UGameWidgetDynamicMaterialRetainerBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetColorParameter DefaultColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetBattleTeamColorParameter BattleTeamColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameBattleWidgetGaugeThreshold> HPGaugeThresholdArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleAlertWidget* AlertWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleHUDWidget* HUDWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleMarkerWidget* MarkerWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleOverlayWidget* OverlayWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePostProcessEffectWidget* PostProcessEffectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetDynamicMaterialRetainerBox* StartDissolve;
    
public:
    UGameBattleWidget();

};


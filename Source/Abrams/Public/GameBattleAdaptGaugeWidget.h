#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleAdaptGaugeWidget.generated.h"

class UGameWidgetNiagaraEffect;
class UGameWidgetProgressBar;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleAdaptGaugeWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetProgressBar* AdaptGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetNiagaraEffect* TipImage;
    
public:
    UGameBattleAdaptGaugeWidget();

};


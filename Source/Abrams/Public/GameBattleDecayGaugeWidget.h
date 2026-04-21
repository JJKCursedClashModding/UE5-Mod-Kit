#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleDecayGaugeWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetProgressBar;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleDecayGaugeWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetProgressBar* DecayGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LevelThresholdImage1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LevelThresholdImage2;
    
public:
    UGameBattleDecayGaugeWidget();

};


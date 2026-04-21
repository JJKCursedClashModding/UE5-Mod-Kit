#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleIceFormationGaugeWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetProgressBar;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleIceFormationGaugeWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetProgressBar* IceFormationGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LevelThresholdImage1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LevelThresholdImage2;
    
public:
    UGameBattleIceFormationGaugeWidget();

};


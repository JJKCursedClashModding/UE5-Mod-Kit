#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleCursedEnergyGaugeWidget.generated.h"

class UGameBattleCursedEnergyGaugeItemWidget;
class UGameWidgetImage;
class UGameWidgetNiagaraEffect;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleCursedEnergyGaugeWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem5;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem6;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem7;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem8;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LevelThresholdImage1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LevelThresholdImage2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LevelThresholdImage3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetNiagaraEffect* GaugeEF;
    
public:
    UGameBattleCursedEnergyGaugeWidget();

};


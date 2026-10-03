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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem5;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem6;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem7;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyGaugeItemWidget* GaugeItem8;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* LevelThresholdImage1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* LevelThresholdImage2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* LevelThresholdImage3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetNiagaraEffect* GaugeEF;
    
public:
    UGameBattleCursedEnergyGaugeWidget();

};


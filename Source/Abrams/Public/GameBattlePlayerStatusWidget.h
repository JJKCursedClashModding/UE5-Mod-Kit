#pragma once
#include "CoreMinimal.h"
#include "GameBattleCharacterStatusWidget.h"
#include "GameBattlePlayerStatusWidget.generated.h"

class UGameBattleDashGaugeWidget;
class UGameBattleDecayGaugeWidget;
class UGameBattleIceFormationGaugeWidget;
class UGameWidgetNiagaraEffect;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattlePlayerStatusWidget : public UGameBattleCharacterStatusWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleDashGaugeWidget* DashGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleDecayGaugeWidget* DecayGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleIceFormationGaugeWidget* IceFormationGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* LinkComboBonusText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetNiagaraEffect* FX_RankUp_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetNiagaraEffect* FX_RankUp_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetNiagaraEffect* FX_RankUp_3_Max;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetNiagaraEffect* FX_RankMax_Loop;
    
public:
    UGameBattlePlayerStatusWidget();

};


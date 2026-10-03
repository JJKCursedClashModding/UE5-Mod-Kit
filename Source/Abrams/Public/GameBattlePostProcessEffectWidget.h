#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattlePostProcessEffectWidget.generated.h"

class UGameBattleCursedEnergyLevelDownEffectWidget;
class UGameBattleCursedEnergyLevelUpEffectWidget;
class UGameBattleDeadEffectWidget;
class UGameBattlePlayerTeamPinchEffectWidget;
class UGameBattleTagComboDamageEffectWidget;
class UGameBattleTimeUpNotifyEffectWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattlePostProcessEffectWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleDeadEffectWidget* DeadEffectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleTagComboDamageEffectWidget* TagComboDamageEffectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattlePlayerTeamPinchEffectWidget* PlayerTeamPinchEffectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleTimeUpNotifyEffectWidget* TimeUpNotifyEffectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyLevelUpEffectWidget* CursedEnergyLevelUpEffectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCursedEnergyLevelDownEffectWidget* CursedEnergyLevelDownEffectWidget;
    
public:
    UGameBattlePostProcessEffectWidget();


    // Fix for true pure virtual functions not being implemented
};


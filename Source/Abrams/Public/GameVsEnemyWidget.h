#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsEnemyWidget.generated.h"

class UGameRankingPvEWidget;
class UGameVsEnemyBattleModeWidget;
class UGameVsEnemyBattlePartnerWidget;
class UGameVsEnemyCharacterSettingsWidget;
class UGameVsEnemyHelpMatchDialogWidget;
class UGameVsEnemyMatchingSettingsWidget;
class UGameVsEnemyTopWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyBattleModeWidget* BattleModeWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyBattlePartnerWidget* BattlePartnerWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyCharacterSettingsWidget* CharacterSettingsWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingPvEWidget* RankingWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyTopWidget* TopWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyMatchingSettingsWidget* MatchingSettingsWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyHelpMatchDialogWidget* HelpMatchDialogWidget;
    
public:
    UGameVsEnemyWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleOverlayWidget.generated.h"

class UGameBattleCornerCutInWidget;
class UGameBattleCutInWidget;
class UGameBattleFinishWidget;
class UGameBattleNotifyWidget;
class UGameBattleStartMissionWaveWidget;
class UGameBattleStartNormalWidget;
class UGameBattleTagComboChanceWidget;
class UGameBattleTagComboHitWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleOverlayWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleStartNormalWidget* StartNormalWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleStartMissionWaveWidget* StartMissionWaveWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleStartMissionWaveWidget* StartMissionBossWaveWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishNormalWinWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishNormalLoseWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishSpecialWinWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishSpecialLoseWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishTimeUpWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishPvEMissionWinWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishPvEModeWinWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishPvEWaveWinWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishMissionLoseWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleFinishWidget* FinishStoryMissionWinWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCutInWidget* CutInWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCornerCutInWidget* CornerCutInWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleTagComboChanceWidget* TagComboChanceWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleTagComboHitWidget* TagComboHitWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleNotifyWidget* NotifyWidget;
    
    UGameBattleOverlayWidget();


    // Fix for true pure virtual functions not being implemented
};


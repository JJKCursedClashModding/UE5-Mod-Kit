#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleHUDWidget.generated.h"

class UGameBattleBindingVowsListWidget;
class UGameBattleButtonGuideRootWidget;
class UGameBattleCrosshairWidget;
class UGameBattleDamageComboWidget;
class UGameBattleDomainExpansionGaugeWidget;
class UGameBattleExtrasItemWidget;
class UGameBattleForceGaugeWidget;
class UGameBattleMissionOrderWidget;
class UGameBattleMissionTaskListWidget;
class UGameBattleOperationMessageWidget;
class UGameBattleOperationWidget;
class UGameBattlePlayerStatusWidget;
class UGameBattlePracticeTaskListWidget;
class UGameBattleRadarWidget;
class UGameBattleReplayFooterWidget;
class UGameBattleSymbolChatMessageWidget;
class UGameBattleSymbolChatWidget;
class UGameBattleTalkWidget;
class UGameBattleTeamMemberStatusWidget;
class UGameBattleTimeLimitWidget;
class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleHUDWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleTimeLimitWidget* TimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleRadarWidget* Radar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleForceGaugeWidget* PlayerTeamForceGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleDamageComboWidget* DamageCombo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleForceGaugeWidget* RivalTeamForceGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePlayerStatusWidget* PlayerStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCrosshairWidget* Crosshair;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleTeamMemberStatusWidget* TeamMemberStatus_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleTeamMemberStatusWidget* TeamMemberStatus_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleDomainExpansionGaugeWidget* PlayerTeamDomainExpansionGauge1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleDomainExpansionGaugeWidget* PlayerTeamDomainExpansionGauge2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleDomainExpansionGaugeWidget* RivalTeamDomainExpansionGauge1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleDomainExpansionGaugeWidget* RivalTeamDomainExpansionGauge2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleOperationWidget* OperationMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleOperationMessageWidget* OperationMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSymbolChatMessageWidget* SymbolChatMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSymbolChatWidget* SymbolChatMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleMissionOrderWidget* MissionOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleMissionTaskListWidget* MissionTaskList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePracticeTaskListWidget* PracticeTaskList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleBindingVowsListWidget* BindingVowsList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleButtonGuideRootWidget* ButtonGuide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleTalkWidget* Talk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleExtrasItemWidget* ExtrasItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Grunge_UpperLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleReplayFooterWidget* ReplayFooter;
    
public:
    UGameBattleHUDWidget();


    // Fix for true pure virtual functions not being implemented
};


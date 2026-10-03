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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleTimeLimitWidget* TimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleRadarWidget* Radar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleForceGaugeWidget* PlayerTeamForceGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleDamageComboWidget* DamageCombo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleForceGaugeWidget* RivalTeamForceGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattlePlayerStatusWidget* PlayerStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCrosshairWidget* Crosshair;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleTeamMemberStatusWidget* TeamMemberStatus_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleTeamMemberStatusWidget* TeamMemberStatus_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleDomainExpansionGaugeWidget* PlayerTeamDomainExpansionGauge1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleDomainExpansionGaugeWidget* PlayerTeamDomainExpansionGauge2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleDomainExpansionGaugeWidget* RivalTeamDomainExpansionGauge1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleDomainExpansionGaugeWidget* RivalTeamDomainExpansionGauge2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleOperationWidget* OperationMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleOperationMessageWidget* OperationMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleSymbolChatMessageWidget* SymbolChatMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleSymbolChatWidget* SymbolChatMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleMissionOrderWidget* MissionOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleMissionTaskListWidget* MissionTaskList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattlePracticeTaskListWidget* PracticeTaskList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleBindingVowsListWidget* BindingVowsList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleButtonGuideRootWidget* ButtonGuide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleTalkWidget* Talk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleExtrasItemWidget* ExtrasItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Grunge_UpperLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleReplayFooterWidget* ReplayFooter;
    
public:
    UGameBattleHUDWidget();


    // Fix for true pure virtual functions not being implemented
};


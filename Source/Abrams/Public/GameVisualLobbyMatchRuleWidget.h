#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyMatchRuleWidget.generated.h"

class UGameVisualLobbyMatchRuleCPUSetupWidget;
class UGameWidgetVisualLobbyMatchRuleTeamOptionBox;
class UGameWidgetVisualLobbyTextOptionBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyMatchRuleWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor GrayDownColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyMatchRuleTeamOptionBox* CharacterTeamOptionBox_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyMatchRuleTeamOptionBox* CharacterTeamOptionBox_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyMatchRuleTeamOptionBox* CharacterTeamOptionBox_03;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyMatchRuleTeamOptionBox* CharacterTeamOptionBox_04;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyTextOptionBox* TimeLimitOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyTextOptionBox* ResultCostDifferenceOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyTextOptionBox* PauseMenuEnabledOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyMatchRuleCPUSetupWidget* CPUSetupWidget;
    
public:
    UGameVisualLobbyMatchRuleWidget();

};


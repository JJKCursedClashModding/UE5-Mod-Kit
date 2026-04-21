#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyBattleModeSelectWidget.generated.h"

class UGameVisualLobbyBattleModeSelectTopWidget;
class UGameVisualLobbyMatchRuleWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyBattleModeSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyBattleModeSelectTopWidget* TopWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyMatchRuleWidget* LobbyMatchRuleWidget;
    
public:
    UGameVisualLobbyBattleModeSelectWidget();

};


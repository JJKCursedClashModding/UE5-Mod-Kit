#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyMatchRuleCPUSetupWidget.generated.h"

class UGameWidgetVisualLobbyTextOptionBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyMatchRuleCPUSetupWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyTextOptionBox* CharacterOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyTextOptionBox* LevelOptionBox;
    
public:
    UGameVisualLobbyMatchRuleCPUSetupWidget();

};


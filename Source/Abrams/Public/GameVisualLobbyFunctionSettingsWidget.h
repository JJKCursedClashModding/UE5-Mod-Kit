#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyFunctionSettingsWidget.generated.h"

class UGameWidgetVisualLobbyTextOptionBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyFunctionSettingsWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVisualLobbyTextOptionBox* WidgetDispSwitchEnabledOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVisualLobbyTextOptionBox* CameraModeSwitchEnabledOptionBox;
    
public:
    UGameVisualLobbyFunctionSettingsWidget();

};


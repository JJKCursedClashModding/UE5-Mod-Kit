#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyMenuWidget.generated.h"

class UGameVisualLobbyBattleModeSelectWidget;
class UGameVisualLobbyCharacterSelectWidget;
class UGameVisualLobbyFunctionSettingsWidget;
class UGameVisualLobbyRoomInfoWidget;
class UGameVisualLobbyTopMenuWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyMenuWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyTopMenuWidget* TopMenu;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyRoomInfoWidget* RoomInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyCharacterSelectWidget* CharacterSelect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyBattleModeSelectWidget* BattleModeSelect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyFunctionSettingsWidget* FunctionSettings;
    
public:
    UGameVisualLobbyMenuWidget();

};


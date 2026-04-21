#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyBattleModeSelectTopWidget.generated.h"

class UGameWidgetVisualLobbyBattleModeSelectTopButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyBattleModeSelectTopWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyBattleModeSelectTopButton* FreeMatchButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyBattleModeSelectTopButton* RankMatchButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyBattleModeSelectTopButton* NormalModeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyBattleModeSelectTopButton* SurvivalModeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyBattleModeSelectTopButton* LobbyMatchButton;
    
public:
    UGameVisualLobbyBattleModeSelectTopWidget();

};


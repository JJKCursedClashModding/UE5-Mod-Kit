#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLobbyWidget.generated.h"

class UGameLobbyCharacterIconWidget;
class UGameLobbyTopWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLobbyWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameLobbyTopWidget* TopWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameLobbyCharacterIconWidget* CharacterIconWidget;
    
public:
    UGameLobbyWidget();

};


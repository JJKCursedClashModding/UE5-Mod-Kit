#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLobbyTopWidget.generated.h"

class UGameWidgetButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLobbyTopWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* CreateSessionButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* FindSessionButton;
    
public:
    UGameLobbyTopWidget();

};


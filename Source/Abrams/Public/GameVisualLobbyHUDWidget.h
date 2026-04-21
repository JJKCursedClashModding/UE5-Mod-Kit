#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyHUDWidget.generated.h"

class UGameChatMessageWidget;
class UGameVisualLobbyChatGuideWidget;
class UGameVisualLobbyFooterWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyHUDWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameChatMessageWidget* ChatMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyFooterWidget* Footer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyChatGuideWidget* ChatGuide;
    
public:
    UGameVisualLobbyHUDWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLobbyFindWidget.generated.h"

class UGameWidgetButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLobbyFindWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* FindFriendButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* FindIdButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* FindConditionsButton;
    
public:
    UGameLobbyFindWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLobbyFindSessionWidget.generated.h"

class UGameLobbyFindSessionListViewWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLobbyFindSessionWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameLobbyFindSessionListViewWidget* FindSessionList;
    
public:
    UGameLobbyFindSessionWidget();

};


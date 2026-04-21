#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLobbyFindConditionsWidget.generated.h"

class UGameWidgetLobbyTextOptionBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLobbyFindConditionsWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* PlayerMaxCountOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* PasswordOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* ConditionsRankOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* ConditionsPlayStyleOptionBox;
    
public:
    UGameLobbyFindConditionsWidget();

};


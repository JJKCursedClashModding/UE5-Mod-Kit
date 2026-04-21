#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLobbyCreateWidget.generated.h"

class UGameWidgetLobbyTextOptionBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLobbyCreateWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* PlayStyleOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* PlayerMaxCountOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* PasswordOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* ConditionFriendOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* ConditionRankUpperLimitOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* ConditionRankLowerLimitOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* AutomaticEntryOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* TagOptionBox_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* TagOptionBox_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetLobbyTextOptionBox* TagOptionBox_03;
    
public:
    UGameLobbyCreateWidget();

};


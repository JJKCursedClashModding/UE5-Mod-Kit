#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "DebugSandboxWidget.generated.h"

class UGameWidgetButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UDebugSandboxWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* ExitButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* SituationOverviewButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* AutoSaveButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* LoadingButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* PvEIntervalButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* LobbyChatButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* SituationOverviewChatButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* LobbyFindSessionButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* ResultButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* ResultChangeRankPointButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* ResultMissionScoreListButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* CharaRelateLevelButton;
    
public:
    UDebugSandboxWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnSituationOverviewChat();
    
    UFUNCTION(BlueprintCallable)
    void OnSituationOverviewButton();
    
    UFUNCTION(BlueprintCallable)
    void OnResultMissionScoreList();
    
    UFUNCTION(BlueprintCallable)
    void OnResultChangeRankPoint();
    
    UFUNCTION(BlueprintCallable)
    void OnResult();
    
    UFUNCTION(BlueprintCallable)
    void OnPvEInterval();
    
    UFUNCTION(BlueprintCallable)
    void OnLobbyFindSession();
    
    UFUNCTION(BlueprintCallable)
    void OnLobbyChat();
    
    UFUNCTION(BlueprintCallable)
    void OnLoading();
    
    UFUNCTION(BlueprintCallable)
    void OnExit();
    
    UFUNCTION(BlueprintCallable)
    void OnCharaRelateLevel();
    
    UFUNCTION(BlueprintCallable)
    void OnAutoSave();
    
};


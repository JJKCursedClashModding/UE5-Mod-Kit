#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameDialogWidget.generated.h"

class UGameAutoSaveDescriptionDialogWidget;
class UGameCharaRelateLevelDialogWidget;
class UGameConfigNotifyMessageDialogWidget;
class UGameNotifyMessageDialogWidget;
class UGamePenaltyDialogWidget;
class UGamePopupDialogWidgetBase;
class UGameProgressDialogWidget;
class UGameRewardDialogWidget;
class UGameStoreNotifyMessageDialogWidget;
class UGameSystemDialogWidget;
class UGameUnlockDlcContentDialogWidget;
class UGameUnlockShopLineupDialogWidget;
class UGameUserNameDialogWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameDialogWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameSystemDialogWidget* SystemDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameProgressDialogWidget* ProgressDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRewardDialogWidget* RewardDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameUnlockShopLineupDialogWidget* UnlockShopLineupDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharaRelateLevelDialogWidget* CharaRelateLevelDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameAutoSaveDescriptionDialogWidget* AutoSaveDescriptionDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameUserNameDialogWidget* UserNameDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameUnlockDlcContentDialogWidget* UnlockDlcContentDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGamePenaltyDialogWidget* PenaltyDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameNotifyMessageDialogWidget* NotifyMessageDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoreNotifyMessageDialogWidget* StoreNotifyMessageDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameConfigNotifyMessageDialogWidget* ConfigNotifyMessageDialog;
    
public:
    UGameDialogWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnDialogClosed(UGamePopupDialogWidgetBase* InDialogWidget);
    
};


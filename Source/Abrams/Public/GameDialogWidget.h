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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameSystemDialogWidget* SystemDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameProgressDialogWidget* ProgressDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRewardDialogWidget* RewardDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameUnlockShopLineupDialogWidget* UnlockShopLineupDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCharaRelateLevelDialogWidget* CharaRelateLevelDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameAutoSaveDescriptionDialogWidget* AutoSaveDescriptionDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameUserNameDialogWidget* UserNameDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameUnlockDlcContentDialogWidget* UnlockDlcContentDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGamePenaltyDialogWidget* PenaltyDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameNotifyMessageDialogWidget* NotifyMessageDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoreNotifyMessageDialogWidget* StoreNotifyMessageDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameConfigNotifyMessageDialogWidget* ConfigNotifyMessageDialog;
    
public:
    UGameDialogWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnDialogClosed(UGamePopupDialogWidgetBase* InDialogWidget);
    
};


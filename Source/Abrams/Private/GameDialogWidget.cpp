#include "GameDialogWidget.h"

UGameDialogWidget::UGameDialogWidget() {
    this->SystemDialog = NULL;
    this->ProgressDialog = NULL;
    this->RewardDialog = NULL;
    this->UnlockShopLineupDialog = NULL;
    this->CharaRelateLevelDialog = NULL;
    this->AutoSaveDescriptionDialog = NULL;
    this->UserNameDialog = NULL;
    this->UnlockDlcContentDialog = NULL;
    this->PenaltyDialog = NULL;
    this->NotifyMessageDialog = NULL;
    this->StoreNotifyMessageDialog = NULL;
    this->ConfigNotifyMessageDialog = NULL;
}

void UGameDialogWidget::OnDialogClosed(UGamePopupDialogWidgetBase* InDialogWidget) {
}



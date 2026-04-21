#include "GameEditableTextWidget.h"

UGameEditableTextWidget::UGameEditableTextWidget() {
    this->TitleText = NULL;
    this->EditableText = NULL;
}

void UGameEditableTextWidget::OnCommit(const FText& InText, TEnumAsByte<ETextCommit::Type> InCommitMethod) {
}



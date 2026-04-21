#include "WidgetEditableText.h"

UWidgetEditableText::UWidgetEditableText() {
    this->IsReadOnly = false;
    this->IsPassword = false;
    this->MinimumDesiredWidth = 0.00f;
    this->IsCaretMovedWhenGainFocus = true;
    this->SelectAllTextWhenFocused = false;
    this->RevertTextOnEscape = false;
    this->SelectAllTextOnCommit = false;
    this->AllowContextMenu = true;
    this->KeyboardType = EVirtualKeyboardType::Default;
    this->Justification = ETextJustify::Left;
    this->MaxCharacters = -1;
    this->bNumberOnly = false;
    this->EditableText = NULL;
    this->BackgroundImage = NULL;
}

void UWidgetEditableText::SetJustification(TEnumAsByte<ETextJustify::Type> InJustification) {
}

void UWidgetEditableText::OnTextChanged(const FText& InText) {
}

void UWidgetEditableText::OnCommit(const FText& InText, TEnumAsByte<ETextCommit::Type> InCommitMethod) {
}



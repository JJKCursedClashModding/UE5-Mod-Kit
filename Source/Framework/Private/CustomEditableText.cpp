#include "CustomEditableText.h"
#include "Layout/Clipping.h"

UCustomEditableText::UCustomEditableText() {
    this->Clipping = EWidgetClipping::ClipToBounds;
    this->IsReadOnly = false;
    this->IsPassword = false;
    this->MinimumDesiredWidth = 0.00f;
    this->IsCaretMovedWhenGainFocus = true;
    this->SelectAllTextWhenFocused = false;
    this->RevertTextOnEscape = false;
    this->ClearKeyboardFocusOnCommit = true;
    this->SelectAllTextOnCommit = false;
    this->AllowContextMenu = true;
    this->KeyboardType = EVirtualKeyboardType::Default;
    this->VirtualKeyboardTrigger = EVirtualKeyboardTrigger::OnFocusByPointer;
    this->VirtualKeyboardDismissAction = EVirtualKeyboardDismissAction::TextChangeOnDismiss;
    this->Justification = ETextJustify::Left;
    this->OverflowPolicy = ETextOverflowPolicy::Clip;
}

void UCustomEditableText::SetTextOverflowPolicy(ETextOverflowPolicy InOverflowPolicy) {
}

void UCustomEditableText::SetText(FText InText) {
}

void UCustomEditableText::SetMinimumDesiredWidth(float InMinDesiredWidth) {
}

void UCustomEditableText::SetJustification(TEnumAsByte<ETextJustify::Type> InJustification) {
}

void UCustomEditableText::SetIsReadOnly(bool InbIsReadyOnly) {
}

void UCustomEditableText::SetIsPassword(bool InbIsPassword) {
}

void UCustomEditableText::SetHintText(FText InHintText) {
}

void UCustomEditableText::SetFontOutlineMaterial(UMaterialInterface* InMaterial) {
}

void UCustomEditableText::SetFontMaterial(UMaterialInterface* InMaterial) {
}

void UCustomEditableText::SetFont(FSlateFontInfo InFontInfo) {
}

FText UCustomEditableText::GetText() const {
    return FText::GetEmpty();
}

TEnumAsByte<ETextJustify::Type> UCustomEditableText::GetJustification() const {
    return ETextJustify::Left;
}

FText UCustomEditableText::GetHintText() const {
    return FText::GetEmpty();
}

FSlateFontInfo UCustomEditableText::GetFont() const {
    return FSlateFontInfo{};
}



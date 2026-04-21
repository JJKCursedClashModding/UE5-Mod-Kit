#include "InputWidgetBase.h"
#include "Components/SlateWrapperTypes.h"

UInputWidgetBase::UInputWidgetBase() {
    this->Visibility = ESlateVisibility::HitTestInvisible;
    this->bIsFocusable = true;
    this->bIsWidgetFocusable = true;
    this->bIsWidgetHoverable = true;
    this->bIsNavigationEnabled = true;
}



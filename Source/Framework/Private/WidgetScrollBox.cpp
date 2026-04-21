#include "WidgetScrollBox.h"
#include "Components/SlateWrapperTypes.h"

UWidgetScrollBox::UWidgetScrollBox() {
    this->bIsVariable = true;
    this->Visibility = ESlateVisibility::HitTestInvisible;
    this->AlwaysShowScrollbar = true;
    this->AlwaysShowScrollbarTrack = true;
    this->bUserScrollEnabled = false;
    this->bAutoHiddenEnabled = true;
    this->bReverseScrollBar = false;
    this->NavigationValue = 0.00f;
}



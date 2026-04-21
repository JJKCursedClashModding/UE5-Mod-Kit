#include "WidgetListViewBase.h"
#include "Layout/Clipping.h"

UWidgetListViewBase::UWidgetListViewBase() {
    this->Clipping = EWidgetClipping::ClipToBounds;
    this->FirstSelectIndex = 0;
    this->EntryWidgetClass = NULL;
    this->Orientation = Orient_Horizontal;
    this->SelectionMode = ESelectionMode::Single;
    this->ConsumeMouseWheel = EConsumeMouseWheel::WhenScrollingPossible;
    this->bClearSelectionOnClick = false;
    this->bReturnFocusToSelection = false;
    this->EntrySpacing = 0.00f;
    this->WheelScrollMultiplier = 1.00f;
    this->bEnableScrollAnimation = false;
    this->AllowOverscroll = true;
    this->bEnableRightClickScrolling = true;
    this->bEnableFixedLineOffset = false;
    this->FixedLineScrollOffset = 0.00f;
    this->bAllowDragging = true;
    this->bReverseScrollBar = false;
}



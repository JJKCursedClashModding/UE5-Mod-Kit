#include "WidgetOptionBoxBase.h"

UWidgetOptionBoxBase::UWidgetOptionBoxBase() {
    this->RightButton = NULL;
    this->LeftButton = NULL;
    this->Orientation = Orient_Horizontal;
    this->bLoopOptions = false;
    this->bLockFocus = false;
}



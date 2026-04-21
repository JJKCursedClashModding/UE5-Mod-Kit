#include "WidgetSlider.h"

UWidgetSlider::UWidgetSlider() {
    this->Orientation = Orient_Horizontal;
    this->MinValue = 0.00f;
    this->MaxValue = 1.00f;
    this->Value = 0.00f;
    this->StepSize = 0.01f;
    this->bLockFocus = false;
    this->CanvasPanel = NULL;
    this->BarImage = NULL;
    this->ThumbImage = NULL;
}



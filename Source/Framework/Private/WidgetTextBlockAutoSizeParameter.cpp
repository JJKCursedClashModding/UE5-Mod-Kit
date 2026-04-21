#include "WidgetTextBlockAutoSizeParameter.h"

FWidgetTextBlockAutoSizeParameter::FWidgetTextBlockAutoSizeParameter() {
    this->bAutoSize = false;
    this->AutoSizeType = EWidgetTextBlockAutoSizeType::Auto;
    this->MaxFontSize = 0;
    this->MinFontSize = 0;
}


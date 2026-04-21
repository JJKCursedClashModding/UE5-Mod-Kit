#include "GameWidgetTextBlock.h"

UGameWidgetTextBlock::UGameWidgetTextBlock() {
    this->bAutoLineBreak = false;
    this->bTextScroll = false;
    this->NotScrollingJustification = ETextJustify::Left;
    this->bForceOneLine = false;
    this->FontStyleType = EGameWidgetFontStyleType::Regular;
    this->FixedFontType = EGameWidgetFontLanguageType::Invalid;
    this->UseCaseType = EGameWidgetFontUseCaseType::None;
}



#include "GameWidgetRichTextBlock.h"

UGameWidgetRichTextBlock::UGameWidgetRichTextBlock() {
    this->bAutoLineBreak = false;
    this->bAutoLineBreakUseDesiredMaxSize = false;
    this->bTextScroll = false;
    this->NotScrollingJustification = ETextJustify::Left;
    this->bForceOneLine = false;
    this->DefaultStyleName = TEXT("Default");
    this->Decorator = NULL;
    this->FontStyleType = EGameWidgetFontStyleType::Regular;
    this->FixedFontType = EGameWidgetFontLanguageType::Invalid;
    this->bUseDecoratorFontStyle = false;
    this->UseCaseType = EGameWidgetFontUseCaseType::None;
}



#include "GameWidgetFontSettings.h"

FGameWidgetFontSettings::FGameWidgetFontSettings() {
    this->FontStyle = EGameWidgetFontStyleType::Thick;
    this->FontSize = 0;
    this->LetterSpacing = 0;
    this->LineHeightPercentage = 0.00f;
    this->ForceOverrideFont = NULL;
}


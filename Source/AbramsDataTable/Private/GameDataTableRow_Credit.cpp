#include "GameDataTableRow_Credit.h"

FGameDataTableRow_Credit::FGameDataTableRow_Credit() {
    this->LineNumber = 0;
    this->ContentType = EGameCreditContentType::None;
    this->Justify = ETextJustify::Left;
    this->FontSize = 0;
    this->LineHeightPercentage = 0.00f;
    this->LetterSpacing = 0;
    this->IsMain = false;
    this->IsShort = false;
    this->IsDlc1 = false;
    this->IsDlc2 = false;
}


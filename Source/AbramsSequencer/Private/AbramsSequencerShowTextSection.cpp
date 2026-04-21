#include "AbramsSequencerShowTextSection.h"

UAbramsSequencerShowTextSection::UAbramsSequencerShowTextSection() {
    this->bPlayKeep = false;
    this->bSupportJapanese = true;
    this->bSupportEnglish = true;
    this->bPlayVoice = true;
    this->bAutoLineBreak = false;
    this->AutoLineBreak_Width = 0.00f;
    this->Justification = ETextJustify::Left;
}



#include "AbramsSequencerPlayVoiceForUniquePairSection.h"

UAbramsSequencerPlayVoiceForUniquePairSection::UAbramsSequencerPlayVoiceForUniquePairSection() {
    this->SequencerType = EGameSequencerUniquePairType::None;
    this->bPlayKeep = true;
    this->bIsPlay2D = true;
    this->bSyncLocation = true;
    this->TargetCharacterType = EGameSequencerUniquePairBindingTagType::None;
    this->bFallbackPlayVoice = true;
    this->PlaySituationType = EGameSequencerUniquePairPlaySituationType::All;
    this->bCheckPlayVoiceOtherModule = true;
    this->CheckPlayVoiceAppendWaitSeconds = 0.00f;
}



#include "GameAnimNotify_PlayActionVoice.h"

UGameAnimNotify_PlayActionVoice::UGameAnimNotify_PlayActionVoice() {
    this->AttackVoiceType = EGameCharacterAttackVoiceType::Action;
    this->FixedVoicePatternIndex = 0;
    this->bSituationAttackVoiceCheckEnabled = true;
    this->bForcePlayEnabled = false;
}



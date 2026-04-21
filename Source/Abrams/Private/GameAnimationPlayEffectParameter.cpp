#include "GameAnimationPlayEffectParameter.h"

FGameAnimationPlayEffectParameter::FGameAnimationPlayEffectParameter() {
    this->bAttached = false;
    this->bAbsoluteLocationOffset = false;
    this->bAbsoluteRotation = false;
    this->bUpperBodyRotation = false;
    this->bStopOnHomingEnd = false;
    this->bStopOnDamage = false;
    this->PossessKey = 0;
}


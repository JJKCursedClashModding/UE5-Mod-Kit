#include "GameAnimNotify_PlayEffect.h"

UGameAnimNotify_PlayEffect::UGameAnimNotify_PlayEffect() {
    this->bAttached = true;
    this->bAbsoluteLocationOffset = false;
    this->bAbsoluteRotation = false;
    this->bUpperBodyRotation = false;
    this->bGroundAttributeEnabled = false;
    this->bStoppedDetachFromActorEnabled = false;
    this->bStopOnHomingEnd = false;
    this->bStopOnDamage = false;
    this->PossessKey = -1;
}



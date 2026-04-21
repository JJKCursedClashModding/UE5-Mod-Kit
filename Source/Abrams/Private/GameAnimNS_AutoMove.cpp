#include "GameAnimNS_AutoMove.h"

UGameAnimNS_AutoMove::UGameAnimNS_AutoMove() {
    this->Key = 0;
    this->EasingType = EEasingFunc::EaseOut;
    this->BlendExp = 2.00f;
    this->bFollowGround = true;
    this->bLookAtMoveDirection = false;
    this->bCancelOnTargetTop = false;
    this->bCancelOnTargetUnder = false;
    this->bFixedMoveDirection = false;
    this->bUseBodyRotation = false;
}



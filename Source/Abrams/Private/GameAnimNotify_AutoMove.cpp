#include "GameAnimNotify_AutoMove.h"

UGameAnimNotify_AutoMove::UGameAnimNotify_AutoMove() {
    this->Key = 0;
    this->SpeedInterpolateTime = 0.00f;
    this->EasingType = EEasingFunc::EaseOut;
    this->BlendExp = 2.00f;
    this->bFollowGround = true;
    this->bLookAtMoveDirection = false;
    this->bCancelOnTargetTop = false;
    this->bCancelOnTargetUnder = false;
    this->bFixedMoveDirection = false;
    this->bUseBodyRotation = false;
}



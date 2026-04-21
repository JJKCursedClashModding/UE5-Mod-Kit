#include "GameAnimNotify_AimOffsetTargetFollow.h"

UGameAnimNotify_AimOffsetTargetFollow::UGameAnimNotify_AimOffsetTargetFollow() {
    this->PitchRotationSpeed = 0.00f;
    this->PitchLimitAngleLower = 0.00f;
    this->PitchLimitAngleUpper = 0.00f;
    this->bIgnoreHomingInvalidate = false;
    this->bImmediateRotation = true;
    this->DeviationMoveSpeed = 0.00f;
}



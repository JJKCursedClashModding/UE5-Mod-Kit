#include "GameAnimNS_AimOffsetTargetFollow.h"

UGameAnimNS_AimOffsetTargetFollow::UGameAnimNS_AimOffsetTargetFollow() {
    this->PitchRotationSpeed = 0.00f;
    this->PitchLimitAngleLower = 0.00f;
    this->PitchLimitAngleUpper = 0.00f;
    this->bIgnoreHomingInvalidate = false;
    this->bImmediateRotation = true;
    this->DeviationMoveSpeed = 0.00f;
    this->StopFadeOutTime = -1.00f;
}



#include "GameAnimNS_LookAtTargetFollow.h"

UGameAnimNS_LookAtTargetFollow::UGameAnimNS_LookAtTargetFollow() {
    this->YawRotationSpeed = 0.00f;
    this->PitchRotationSpeed = 0.00f;
    this->PitchLimitAngleLower = 0.00f;
    this->PitchLimitAngleUpper = 0.00f;
    this->bIgnoreHomingInvalidate = false;
    this->bImmediateRotation = true;
    this->DeviationMoveSpeed = 0.00f;
    this->bBoundOnlyDeviationEnabled = false;
    this->bCalcCenterLocationEnabled = false;
}



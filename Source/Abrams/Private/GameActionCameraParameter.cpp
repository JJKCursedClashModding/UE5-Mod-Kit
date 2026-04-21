#include "GameActionCameraParameter.h"

FGameActionCameraParameter::FGameActionCameraParameter() {
    this->FOV = 0.00f;
    this->BaseLocationOwnerToTargetRate = 0.00f;
    this->bBaseLocationLock = false;
    this->BaseRotationType = EGameActionCameraDirectionType::OwnerToTarget;
    this->bBaseRotationLock = false;
    this->BlendInTime = 0.00f;
    this->BlendInType = VTBlend_Linear;
    this->BlendInExp = 0.00f;
    this->BlendOutTime = 0.00f;
    this->BlendOutType = VTBlend_Linear;
    this->BlendOutExp = 0.00f;
    this->bBeforeActionCameraBlend = false;
    this->bIgnoreBlockingObject = false;
    this->HiddenEffectTag = 0;
    this->CheckBlockingRadius = 0.00f;
}


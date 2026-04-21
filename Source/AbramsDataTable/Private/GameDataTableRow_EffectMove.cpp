#include "GameDataTableRow_EffectMove.h"

FGameDataTableRow_EffectMove::FGameDataTableRow_EffectMove() {
    this->EffectMoveType = EGameEffectMoveType::None;
    this->bHomingEnabled = false;
    this->Speed_Start = 0.00f;
    this->Speed_End = 0.00f;
    this->Speed_InterpolateTime = 0.00f;
    this->Speed_EasingType = EGameEasingType::None;
    this->Speed_Blend_Exp = 0.00f;
    this->Delay_Time = 0.00f;
    this->Fall_AngularVelocityZ = 0.00f;
    this->Limit_AngleXY = 0.00f;
    this->Limit_AngleZ = 0.00f;
    this->Homing_AngularVelocityXY = 0.00f;
    this->Homing_AngularVelocityZ = 0.00f;
    this->Homing_Time = 0.00f;
    this->bTilt = false;
    this->bAlongGroundEnabled = false;
    this->bAlongGroundDownEnabled = false;
    this->bIsStoppedOnAir = false;
    this->AlongGroundHeight = 0.00f;
    this->AlongGroundEffect_Height = 0.00f;
}


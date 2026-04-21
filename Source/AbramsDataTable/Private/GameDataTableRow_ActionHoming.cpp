#include "GameDataTableRow_ActionHoming.h"

FGameDataTableRow_ActionHoming::FGameDataTableRow_ActionHoming() {
    this->ActionHomingType = EGameActionHomingType::None;
    this->Inertia_Rate = 0.00f;
    this->Inertia_Time = 0.00f;
    this->Rotation_Yaw = 0.00f;
    this->Rotation_Time = 0.00f;
    this->Rotation_Angle_Limit = 0.00f;
    this->Rotation_Speed_Start = 0.00f;
    this->Rotation_Speed_End = 0.00f;
    this->Rotation_Speed_InterpolateTime = 0.00f;
    this->Rotation_Speed_EasingType = EGameEasingType::None;
    this->Rotation_Speed_Blend_Exp = 0.00f;
    this->Speed_Start = 0.00f;
    this->Speed_End = 0.00f;
    this->Speed_InterpolateTime = 0.00f;
    this->Speed_EasingType = EGameEasingType::None;
    this->Speed_Blend_Exp = 0.00f;
    this->HomingDistance = 0.00f;
    this->Homing_Delay_Time = 0.00f;
    this->Homing_Time_Min = 0.00f;
    this->Homing_Time_Max = 0.00f;
    this->bIgnoreHomingRange = false;
    this->Distance_Correct = 0.00f;
    this->RangeZ_Upper = 0.00f;
    this->RangeZ_Lower = 0.00f;
    this->AngleZ = 0.00f;
    this->WarpDistance = 0.00f;
    this->WarpTargetDistance = 0.00f;
    this->WarpDirectionAdjustPitch = 0.00f;
    this->WarpDirectionAdjustYaw = 0.00f;
    this->WarpAdjustTargetSimulateType = EGameWarpAdjustTargetSimulateType::None;
    this->bFollowGroundEnabled = false;
    this->FollowGroundCheckDistance = 0.00f;
    this->FollowGroundFallGravity = 0.00f;
    this->FollowGroundIgnoreStepDistance = 0.00f;
    this->bSuperArmorEnabled = false;
    this->bHyperArmorEnabled = false;
    this->bExternalForceEnabled = false;
    this->ExternalForceRange = 0.00f;
    this->ExternalForceStrength_Start = 0.00f;
    this->ExternalForceStrength_End = 0.00f;
    this->ExternalForceStrength_InterpolateTime = 0.00f;
    this->ExternalForceStrength_EasingType = EGameEasingType::None;
    this->ExternalForceStrength_Blend_Exp = 0.00f;
    this->ExternalForceGravityCorrect = 0.00f;
}


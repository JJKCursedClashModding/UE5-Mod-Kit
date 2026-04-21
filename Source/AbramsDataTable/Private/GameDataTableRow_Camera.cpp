#include "GameDataTableRow_Camera.h"

FGameDataTableRow_Camera::FGameDataTableRow_Camera() {
    this->GazeLocation_AttenuateRate = 0.00f;
    this->RotationPitch_AttenuateRate = 0.00f;
    this->RotationYaw_AttenuateRate = 0.00f;
    this->Distance_AttenuateRate = 0.00f;
    this->TargetCamera_Distance = 0.00f;
    this->FreeCamera_Distance = 0.00f;
    this->ShootCamera_Distance = 0.00f;
    this->TargetCamera_ActionDistance = 0.00f;
    this->TargetCamera_ActionDistanceChangeTime_Run = 0.00f;
    this->TargetCamera_ActionDistanceChangeTime_Dash = 0.00f;
    this->TargetCamera_ActionDistanceChangeTime_Jump = 0.00f;
    this->TargetCamera_ActionDistanceChangeTime_Step = 0.00f;
    this->TargetCamera_DownDistance = 0.00f;
    this->TargetCamera_DownDistanceChangeTime = 0.00f;
    this->TargetCamera_NormalDistanceChangeWaitTime = 0.00f;
    this->TargetCamera_NormalDistanceChangeTime = 0.00f;
    this->LimitAngleH_Min = 0.00f;
    this->LimitAngleHDistance_Min = 0.00f;
    this->LimitAngleH_Max = 0.00f;
    this->LimitAngleHDistance_Max = 0.00f;
    this->LimitAngleV_Min = 0.00f;
    this->LimitAngleV_Max = 0.00f;
    this->OwnerHeightScale = 0.00f;
    this->TargetCamera_OffsetAngleV = 0.00f;
    this->CameraModeChange_InterpolationTime = 0.00f;
}


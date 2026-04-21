#include "GameDataTableRow_ActionMove.h"

FGameDataTableRow_ActionMove::FGameDataTableRow_ActionMove() {
    this->Foreground_Angle = 0.00f;
    this->Foreground_Speed_Rate = 0.00f;
    this->Target_Speed_Distance = 0.00f;
    this->Target_Speed_Rate = 0.00f;
    this->ParallelAttack_Speed_Rate = 0.00f;
    this->Run_Rotation_Time = 0.00f;
    this->Run_Speed_Start = 0.00f;
    this->Run_Speed_End = 0.00f;
    this->Run_InterpolateTime = 0.00f;
    this->Run_EasingType = EGameEasingType::None;
    this->Run_Blend_Exp = 0.00f;
    this->Run_Rotation_Rate = 0.00f;
    this->Run_Inertia_Rate = 0.00f;
    this->Run_Inertia_Time = 0.00f;
    this->Run_Lean_Rate = 0.00f;
    this->Run_Lean_Max = 0.00f;
    this->Guard_Inertia_Rate = 0.00f;
    this->Guard_Inertia_RateZ = 0.00f;
    this->GuardAir_Inertia_Rate = 0.00f;
    this->GuardAir_Inertia_RateZ = 0.00f;
    this->GuardAir_Speed_Start = 0.00f;
    this->GuardAir_Speed_End = 0.00f;
    this->GuardAir_InterpolateTime = 0.00f;
    this->GuardAir_EasingType = EGameEasingType::None;
    this->GuardAir_Blend_Exp = 0.00f;
    this->Landing_Inertia_Rate = 0.00f;
    this->Landing_Inertia_RateZ = 0.00f;
    this->Rigidity_Landing = EGameActionRigidityType::None;
}


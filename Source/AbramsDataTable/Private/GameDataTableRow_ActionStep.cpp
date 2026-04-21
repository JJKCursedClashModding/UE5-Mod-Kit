#include "GameDataTableRow_ActionStep.h"

FGameDataTableRow_ActionStep::FGameDataTableRow_ActionStep() {
    this->CoolTime = 0.00f;
    this->Step_Time = 0.00f;
    this->Step_Speed_Start = 0.00f;
    this->Step_Speed_End = 0.00f;
    this->Step_InterpolateTime = 0.00f;
    this->Step_EasingType = EGameEasingType::None;
    this->Step_Blend_Exp = 0.00f;
    this->Step_Inertia_Rate = 0.00f;
    this->Step_Inertia_Time = 0.00f;
    this->Step_HomingInvalidateDistance = 0.00f;
    this->StepEnd_PlayRate = 0.00f;
    this->StepAir_Time = 0.00f;
    this->StepAir_Speed_Start = 0.00f;
    this->StepAir_Speed_End = 0.00f;
    this->StepAir_InterpolateTime = 0.00f;
    this->StepAir_EasingType = EGameEasingType::None;
    this->StepAir_Blend_Exp = 0.00f;
    this->StepAir_Inertia_Rate = 0.00f;
    this->StepAir_Inertia_Time = 0.00f;
    this->StepAir_HomingInvalidateDistance = 0.00f;
    this->StepAirEnd_PlayRate = 0.00f;
}


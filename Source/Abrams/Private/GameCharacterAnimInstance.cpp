#include "GameCharacterAnimInstance.h"

UGameCharacterAnimInstance::UGameCharacterAnimInstance() {
    this->LowerAttackSlotWeights = 1.00f;
    this->UpperAttackSlotWeights = 1.00f;
    this->UpperDamageSlotWeights = 1.00f;
    this->FacialSlotWeights = 0.00f;
    this->BrowSlotWeights = 0.00f;
    this->EyelidsSlotWeights = 0.00f;
    this->MouthSlotWeights = 0.00f;
    this->BlendMouthSlotWeights = 0.00f;
    this->EyesSlotWeights = 0.00f;
    this->AutoAimYaw = 0.00f;
    this->AutoAimPitch = 0.00f;
    this->AutoAimAlpha = 0.00f;
    this->LeftFootBendAlpha = 0.00f;
    this->RightFootBendAlpha = 0.00f;
}

void UGameCharacterAnimInstance::OnMontageStartedFunction(UAnimMontage* Montage) {
}

void UGameCharacterAnimInstance::OnMontageEndedFunction(UAnimMontage* Montage, bool bInterrupted) {
}



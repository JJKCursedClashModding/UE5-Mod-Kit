#include "GameCharacterPostProcessAnimInstance.h"

UGameCharacterPostProcessAnimInstance::UGameCharacterPostProcessAnimInstance() {
    this->AnimLOD = EGameActorPostProcessAnimLOD::High;
    this->AnimMode = EGameActorPostProcessAnimMode::Default;
    this->UniqueAlpha = 1.00f;
}



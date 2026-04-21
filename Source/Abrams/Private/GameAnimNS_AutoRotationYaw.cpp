#include "GameAnimNS_AutoRotationYaw.h"

UGameAnimNS_AutoRotationYaw::UGameAnimNS_AutoRotationYaw() {
    this->OffsetYaw = 0.00f;
    this->EasingType = EEasingFunc::Linear;
    this->BlendExp = 2.00f;
}



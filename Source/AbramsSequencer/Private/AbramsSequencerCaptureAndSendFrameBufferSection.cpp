#include "AbramsSequencerCaptureAndSendFrameBufferSection.h"

UAbramsSequencerCaptureAndSendFrameBufferSection::UAbramsSequencerCaptureAndSendFrameBufferSection() {
    this->SendTargetType = EGameSequencerSendFrameBufferTargetType::None;
    this->CaptureSource = SCS_SceneColorHDR;
    this->MaterialIndex = 0;
    this->bForceSetAspectRate = true;
    this->bKeepMaterial = false;
    this->TargetTexture = NULL;
}



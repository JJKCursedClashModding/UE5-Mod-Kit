#include "WidgetAnimationParameter.h"

FWidgetAnimationParameter::FWidgetAnimationParameter() {
    this->Layer = EWidgetAnimationLayer::Idle;
    this->StartAtTime = 0.00f;
    this->Speed = 0.00f;
    this->PlayMode = EUMGSequencePlayMode::Forward;
    this->bIsLoop = false;
    this->bIsInputBlock = false;
}


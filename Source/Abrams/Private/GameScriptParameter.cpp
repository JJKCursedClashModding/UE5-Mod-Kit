#include "GameScriptParameter.h"

UGameScriptParameter::UGameScriptParameter() {
    this->DefaultAutoWaitTime = 2.50f;
    this->MessageAutoWaitTime = 2.50f;
    this->VoiceAutoWaitTime = 1.00f;
    this->DuckingVolume = 0.70f;
    this->DuckingFadeTime = 0.10f;
    this->DuckingEasingType = EEasingFunc::Linear;
    this->DuckingBlendExp = 2.00f;
}



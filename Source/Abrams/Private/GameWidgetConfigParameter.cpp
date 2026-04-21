#include "GameWidgetConfigParameter.h"

UGameWidgetConfigParameter::UGameWidgetConfigParameter() {
    this->Brightness = 0.00f;
    this->bMinimapRotateEnabled = false;
    this->bForceFeedbackEnabled = false;
    this->bButtonGuideEnabled = false;
    this->bCameraShakeEnabled = false;
    this->bSpecialTagComboAssistEnabled = false;
    this->bActionCameraEnabled = false;
    this->MasterVolume = 0.00f;
    this->BgmVolume = 0.00f;
    this->SeVolume = 0.00f;
    this->VoiceVolume = 0.00f;
    this->bSubtitlesEnabled = false;
    this->bVsyncEnabled = false;
    this->FrameRate = EApplicationFrameRate::Invalid;
    this->RenderQuality = EGameRenderQuality::Invalid;
    this->AntiAliasing = EGameRenderAntiAliasing::Invalid;
    this->ShadowQuality = ERenderShadowQuality::Invalid;
    this->TextureQuality = EGameRenderTextureQuality::Invalid;
}



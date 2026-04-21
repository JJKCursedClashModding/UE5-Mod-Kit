#include "GameStoryDemoImage.h"

UGameStoryDemoImage::UGameStoryDemoImage() {
    this->FrameMaterial = NULL;
    this->LineTopFrameMaterial = NULL;
    this->LineBottomFrameMaterial = NULL;
    this->LineLeftFrameMaterial = NULL;
    this->LineRightFrameMaterial = NULL;
    this->LineVerticalFrameMaterial = NULL;
    this->LineHorizontalFrameMaterial = NULL;
    this->LineRadiationFrameMaterial = NULL;
    this->RecollectionFrameMaterial = NULL;
    this->ReportFrameMaterial = NULL;
    this->BackgroundMaterial = NULL;
    this->VerticalSpeedLineEffectMaterial = NULL;
    this->HorizontalLineEffectMaterial = NULL;
    this->FrameRetainerBox = NULL;
    this->DemoPanel = NULL;
    this->ShakePanel = NULL;
    this->SpeedLineEffectImage = NULL;
    this->ConcentrationLineEffectImage = NULL;
    this->BackgroundImage = NULL;
    this->CharacterImage_01 = NULL;
    this->CharacterImage_02 = NULL;
    this->CharacterImage_03 = NULL;
    this->CharacterImage_04 = NULL;
    this->CharacterImage_05 = NULL;
    this->CharacterZoomImage_01 = NULL;
    this->bScrollTop = false;
    this->bScrollBottom = false;
    this->bScrollLeft = false;
    this->bScrollRight = false;
    this->bOppositeMask = false;
    this->bRotateMask = false;
    this->bFadeBackground = false;
    this->BackgroundColorType = EGameStoryDemoImageBackgroundFadeColorType::Invalid;
    this->NormalMaskTexture = NULL;
    this->HazyMaskTexture = NULL;
    this->OppositeNormalMaskTexture = NULL;
    this->OppositeHazyMaskTexture = NULL;
    this->CharacterBaseScale = 1.00f;
}



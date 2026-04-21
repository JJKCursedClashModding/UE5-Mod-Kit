#include "GameDataTableRow_EffectColorCorrect.h"

FGameDataTableRow_EffectColorCorrect::FGameDataTableRow_EffectColorCorrect() {
    this->Radius = 0.00f;
    this->Height = 0.00f;
    this->bCheckUpperOnly = false;
    this->bCheckLowerOnly = false;
    this->bCheckCharacterLocation = false;
    this->bCheckCameraLocation = false;
    this->Culling_ScaleRate = 0.00f;
    this->FadeInTime = 0.00f;
    this->FadeOutTime = 0.00f;
    this->ForceCorrectTime = 0.00f;
    this->DelayCorrectTime = 0.00f;
    this->bColorCorrectEnabled = false;
    this->bCullingEnabled = false;
    this->bUseAttackCollisionEnabled = false;
    this->PostProcessMaterial_Weight = 0.00f;
    this->PostProcessMaterial_Time = 0.00f;
    this->CrossFadeTime = 0.00f;
}


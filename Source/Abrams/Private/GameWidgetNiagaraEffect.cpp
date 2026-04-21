#include "GameWidgetNiagaraEffect.h"

UGameWidgetNiagaraEffect::UGameWidgetNiagaraEffect() {
    this->bIsVolatile = true;
    this->NiagaraSystemReference = NULL;
    this->bAutoActivate = true;
    this->bIsIgnoreTimeDilation = true;
    this->bTickWhenPaused = false;
    this->bFakeDepthScale = false;
    this->FakeDepthScaleDistance = 1000.00f;
    this->bShowDebugSystemInWorld = false;
    this->bDisableWarnings = false;
    this->bUsePeriod = false;
    this->TimePeriod = 1.00f;
    this->NiagaraActor = NULL;
    this->NiagaraComponent = NULL;
}



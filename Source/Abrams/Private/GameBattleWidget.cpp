#include "GameBattleWidget.h"

UGameBattleWidget::UGameBattleWidget() {
    this->HPGaugeThresholdArray.AddDefaulted(4);
    this->AlertWidget = NULL;
    this->HUDWidget = NULL;
    this->MarkerWidget = NULL;
    this->OverlayWidget = NULL;
    this->PostProcessEffectWidget = NULL;
    this->StartDissolve = NULL;
}



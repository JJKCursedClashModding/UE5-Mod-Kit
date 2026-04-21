#include "GameBattleWidgetGaugeThreshold.h"

FGameBattleWidgetGaugeThreshold::FGameBattleWidgetGaugeThreshold() {
    this->Rate = 0.00f;
    this->RateType = EGameBattleWidgetHPGaugeRateType::Afford;
    this->HPGaugeNiagaraSystem = NULL;
}


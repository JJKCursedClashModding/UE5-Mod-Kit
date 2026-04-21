#include "GameBattlePlayerInfoWidget.h"

UGameBattlePlayerInfoWidget::UGameBattlePlayerInfoWidget() {
    this->ClampRectTop = 0.00f;
    this->ClampRectBottom = 0.00f;
    this->ClampRectLeft = 0.00f;
    this->ClampRectRight = 0.00f;
    this->HPGauge = NULL;
    this->DamageGauge = NULL;
    this->CursedEnergyLevel = NULL;
    this->CursedEnergyGauge = NULL;
    this->DecayGauge = NULL;
    this->AdaptGauge = NULL;
    this->AdaptDownDamageGauge = NULL;
    this->PlayerIndexText = NULL;
    this->PlayerName = NULL;
    this->DebuffIconList = NULL;
    this->BuffIconList = NULL;
    this->PlayerTeamCanvas = NULL;
    this->RivalTeamCanvas = NULL;
}



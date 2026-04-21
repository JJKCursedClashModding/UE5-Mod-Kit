#include "GameBattleRadarWidget.h"

UGameBattleRadarWidget::UGameBattleRadarWidget() {
    this->RangeRadius = 2500.00f;
    this->ArrowIconAreaRate = 1.00f;
    this->RadarCanvas = NULL;
    this->PlayerArrow = NULL;
    this->CharacterArrow1 = NULL;
    this->CharacterArrow2 = NULL;
    this->CharacterArrow3 = NULL;
    this->CharacterArrow4 = NULL;
    this->CharacterArrow5 = NULL;
    this->PlayerTargetLine = NULL;
    this->PlayerTeamTargetLine1 = NULL;
    this->PlayerTeamTargetLine2 = NULL;
    this->RivalTeamTargetLine1 = NULL;
    this->RivalTeamTargetLine2 = NULL;
    this->RivalTeamTargetLine3 = NULL;
    this->RivalTeamTargetLine4 = NULL;
    this->RivalTeamTargetLine5 = NULL;
    this->PlayerDomainExpansionEffect = NULL;
    this->DomainExpansionEffect1 = NULL;
    this->DomainExpansionEffect2 = NULL;
    this->DomainExpansionEffect3 = NULL;
    this->DomainExpansionEffect4 = NULL;
    this->DomainExpansionEffect5 = NULL;
    this->PlayerTagComboChanceEffect = NULL;
    this->TagComboChanceEffect1 = NULL;
    this->TagComboChanceEffect2 = NULL;
    this->TagComboChanceEffect3 = NULL;
    this->TagComboChanceEffect4 = NULL;
    this->TagComboChanceEffect5 = NULL;
    this->RadarBg_Scroll_Font = NULL;
    this->RadarGauge = NULL;
    this->RadarGaugeFrame = NULL;
    this->VisibilityAreaCanvas = NULL;
    this->MiniMapImage = NULL;
    this->TargetCursorImage = NULL;
}



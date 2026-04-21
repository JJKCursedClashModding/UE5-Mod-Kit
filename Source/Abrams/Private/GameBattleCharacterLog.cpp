#include "GameBattleCharacterLog.h"

FGameBattleCharacterLog::FGameBattleCharacterLog() {
    this->RankPoint = 0;
    this->BattleTeam = EGameBattleTeam::Playable;
    this->NormalAttackVoiceIndex = 0;
    this->CursedEnergyAttackVoiceIndex = 0;
    this->bSpecialTagComboAssistEnabled = false;
}


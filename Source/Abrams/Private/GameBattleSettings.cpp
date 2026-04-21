#include "GameBattleSettings.h"

FGameBattleSettings::FGameBattleSettings() {
    this->BattleMode = EGameBattleMode::Test;
    this->BattlePair = EGameBattlePair::Pair_1vs1;
    this->BattleDrawType = EGameBattleDrawType::Normal;
    this->TimeLimit = 0.00f;
    this->bTimeLimitInfinity = false;
    this->bPauseMenuEnabled = false;
}


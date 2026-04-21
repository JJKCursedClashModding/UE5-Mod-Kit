#include "GameOnlineCharacterSelectSettings.h"

FGameOnlineCharacterSelectSettings::FGameOnlineCharacterSelectSettings() {
    this->Status = EGameOnlineCharacterSelectStatus::Selecting;
    this->BattlePair = EGameBattlePair::Pair_1vs1;
    this->Time = 0.00f;
    this->bPartnerCPU = false;
}


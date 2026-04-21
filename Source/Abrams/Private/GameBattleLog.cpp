#include "GameBattleLog.h"

FGameBattleLog::FGameBattleLog() {
    this->OnlineGameMode = EGameOnlineGameMode::FreeMatch;
    this->PlayableCharacterIndex = EGameCharacterIndex::Index_1P;
    this->BattleResultType = EGameBattleResultType::Win_TeamA;
}


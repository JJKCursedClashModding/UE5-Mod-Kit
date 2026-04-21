#include "GameVisualLobbyMatchCharacterInfo.h"

FGameVisualLobbyMatchCharacterInfo::FGameVisualLobbyMatchCharacterInfo() {
    this->Team = EGameBattleTeam::Playable;
    this->bCPU = false;
    this->CPULevel = 0;
}


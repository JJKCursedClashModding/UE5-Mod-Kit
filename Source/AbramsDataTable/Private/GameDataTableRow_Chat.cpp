#include "GameDataTableRow_Chat.h"

FGameDataTableRow_Chat::FGameDataTableRow_Chat() {
    this->ChatCategory = EGameChatCategory::None;
    this->ChatLabel = EGameChatLabel::None;
    this->bUseBattleEnabled = false;
    this->bUseLobbyEnabled = false;
    this->bUseVsEnabled = false;
    this->bUseBattleResultEnabled = false;
    this->bUseBattleIntervalEnabled = false;
}


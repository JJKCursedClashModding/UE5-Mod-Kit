#include "GameOnlineCreateSessionSettings.h"

FGameOnlineCreateSessionSettings::FGameOnlineCreateSessionSettings() {
    this->NumPublicConnections = 0;
    this->GameMode = EGameOnlineGameMode::FreeMatch;
    this->bSameRegionOnly = false;
    this->RankPoint = 0;
    this->bSolo = false;
    this->bOpenRank = false;
    this->PvEHelpType = EGameOnlinePvEHelpType::Helper;
    this->RiskValue = 0;
    this->RiskValueMin = 0;
    this->RiskValueMax = 0;
    this->Rank = EGameRankPointClass::None;
    this->RankMin = EGameRankPointClass::None;
    this->RankMax = EGameRankPointClass::None;
    this->PlayStyle = EGameOnlineLobbyPlayStyleType::None;
    this->RecruitMessages[0] = 0;
    this->RecruitMessages[1] = 0;
    this->RecruitMessages[2] = 0;
    this->bFriendOnly = false;
    this->bAutomaticEntry = false;
}


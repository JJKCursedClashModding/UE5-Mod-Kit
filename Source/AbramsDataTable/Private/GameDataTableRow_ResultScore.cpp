#include "GameDataTableRow_ResultScore.h"

FGameDataTableRow_ResultScore::FGameDataTableRow_ResultScore() {
    this->ResultScore = EGameResultScore::None;
    this->Threshold = 0.00f;
    this->Threshold_Story = 0.00f;
    this->Threshold_PvE_Normal = 0.00f;
    this->Threshold_PvE_Survival = 0.00f;
    this->Threshold_Arcade = 0.00f;
    this->UpperLimit = 0;
    this->Score = 0;
}


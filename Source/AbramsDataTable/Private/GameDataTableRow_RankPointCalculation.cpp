#include "GameDataTableRow_RankPointCalculation.h"

FGameDataTableRow_RankPointCalculation::FGameDataTableRow_RankPointCalculation() {
    this->Result_Win = 0;
    this->Result_Lose = 0;
    this->Result_Draw = 0;
    this->Evaluation_S = 0;
    this->Evaluation_A = 0;
    this->Evaluation_B = 0;
    this->Evaluation_C = 0;
    this->ForceGaugeRate = 0;
    this->RankGapThreshold = 0;
    this->RankGapRate = 0.00f;
}


#include "GameDataTableRow_AttackSet.h"

FGameDataTableRow_AttackSet::FGameDataTableRow_AttackSet() {
    this->AttackRangeType = EGameAttackRangeType::None;
    this->bCursedEnergyAttack = false;
    this->bRecoverCursedEnergyDisabled = false;
    this->Inherit_Inertia_Rate = 0.00f;
    this->Inherit_Inertia_RateZ = 0.00f;
}


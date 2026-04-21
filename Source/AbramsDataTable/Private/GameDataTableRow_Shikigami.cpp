#include "GameDataTableRow_Shikigami.h"

FGameDataTableRow_Shikigami::FGameDataTableRow_Shikigami() {
    this->ActionControllerType = EGameShikigamiActionControllerType::None;
    this->SummonCursedEnergyLevel = 0;
    this->HitPoint = 0.00f;
    this->DownValue = 0.00f;
    this->OrderCoolTime = 0.00f;
    this->SummonCoolTime = 0.00f;
    this->bIsInstanceDeathEnabled = false;
    this->bImmortalityEnabled = false;
    this->AutoAttackDistance_Owner = 0.00f;
    this->AutoAttackDistance_Target = 0.00f;
}


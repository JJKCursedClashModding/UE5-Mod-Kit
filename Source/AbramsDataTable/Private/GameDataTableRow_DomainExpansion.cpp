#include "GameDataTableRow_DomainExpansion.h"

FGameDataTableRow_DomainExpansion::FGameDataTableRow_DomainExpansion() {
    this->CastingTime = 0.00f;
    this->Duration = 0.00f;
    this->CursedEnergyDisabledTime = 0.00f;
    this->HitTargetType = EGameHitTargetType::None;
    this->bFinishOtherDomainExpansion = false;
    this->bTargetCharacterBind = false;
    this->bTeamMemberUniqueBind = false;
    this->bAdjustGroundLocation = false;
    this->SetActionType_Enemy = EGameCharacterActionType::None;
    this->SetActionType_Ally = EGameCharacterActionType::None;
}


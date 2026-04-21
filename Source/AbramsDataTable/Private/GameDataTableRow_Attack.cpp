#include "GameDataTableRow_Attack.h"

FGameDataTableRow_Attack::FGameDataTableRow_Attack() {
    this->AttackTransitionType = EGameAttackTransitionType::None;
    this->AutoTransitionKind = EGameAttackTransitionKind::None;
    this->AutoTransitionKind_CursedEnergy = EGameAttackTransitionKind::None;
    this->AutoComboFixedCursedEnergyLevel = 0;
    this->CharacterFacial = EGameCharacterFacial::None;
    this->CursedEnergy_Add = 0.00f;
    this->CursedEnergyCalcType = EGameCursedEnergyCalcType::None;
    this->BlendInTime_Idle = 0.00f;
    this->BlendInTime_Fall = 0.00f;
    this->ContinuousUseAttackVoiceType = EGameCharacterAttackVoiceType::Action;
    this->bSuperArmorEnabled = false;
    this->bHyperArmorEnabled = false;
    this->TargetChangeType = EGameTargetChangeType::None;
    this->bUpdateHomingLocation = false;
    this->bTargetOnlyHitAttackTransitionEnabled = false;
    this->bChangeLastHitNotTargetEnabled = false;
    this->AttackActionType = EGameAttackActionType::None;
    this->AttackTiming = 0.00f;
    this->DistanceDelayAttackTiming = 0.00f;
    this->AttackAvoidType = EGameAttackAvoidType::None;
    this->SimpleDomainCounterReceiveType = EGameSimpleDomainCounterReceiveType::None;
    this->SimpleDomainCounterReceiveDelayTime = 0.00f;
}


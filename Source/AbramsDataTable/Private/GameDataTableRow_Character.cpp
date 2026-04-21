#include "GameDataTableRow_Character.h"

FGameDataTableRow_Character::FGameDataTableRow_Character() {
    this->CharacterGroup = EGameCharacterGroup::None;
    this->CharacterPairGroup = EGameCharacterPairGroup::None;
    this->DamageRate_AutoCombo = 0.00f;
    this->LinkComboCursedEnergyExpRate = 0.00f;
    this->AutoAttackDash_NextActionType = EGameCharacterActionType::None;
    this->AutoAttackDash_Distance = 0.00f;
    this->ActionControllerType = EGameCharacterActionControllerType::None;
    this->AIType = EGameCharacterAIType::None;
    this->AutoAimLimitAngleYaw = 0.00f;
    this->AutoAimLimitAnglePitch = 0.00f;
    this->SituationAttackVoicePlayDistance = 0.00f;
    this->PvEAllyWeights = 0.00f;
    this->StoryCharaGraphPlacementIndex = 0;
    this->OverrideJustGuard_HitSlow_Attacker = 0.00f;
    this->OverrideJustGuard_HitSlow_Time_Attacker = 0.00f;
}


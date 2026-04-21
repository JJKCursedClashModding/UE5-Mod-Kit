#include "GameDataTableRow_MissionCharacter.h"

FGameDataTableRow_MissionCharacter::FGameDataTableRow_MissionCharacter() {
    this->VariationIndex = 0;
    this->PoseIndex = 0;
    this->MaterialPattern = 0;
    this->bDamageMaterialEnabled = false;
    this->bSpecialTagComboSoloEnabled = false;
    this->HitPoint = 0.00f;
    this->Cost = 0;
    this->CursedEnergyLevel = 0;
    this->bResetCursedEnergyLevelEnabled = false;
    this->TensionLevel = 0;
    this->PassionGauge = 0.00f;
    this->UniqueMode = 0;
    this->CharacterSpecialTagComboLimit = EGameCharacterSpecialTagComboLimit::None;
    this->Damage_Rate = 0.00f;
    this->AutoCombo_Damage_Rate = 0.00f;
    this->Armor_Damage_Rate = 0.00f;
    this->Down_Damage_Rate = 0.00f;
    this->GuardDurability_Damage_Rate = 0.00f;
    this->Destructible_Attack_Rate = 0.00f;
    this->CursedEnergyExp_Add_Attacker_Rate = 0.00f;
    this->CursedEnergyExp_Add_Receiver_Rate = 0.00f;
    this->TensionGauge_Add_Attacker_Rate = 0.00f;
    this->PassionGauge_Add_Attacker_Rate = 0.00f;
    this->Operation = EGameCharacterOperation::None;
    this->AILevel = 0;
}


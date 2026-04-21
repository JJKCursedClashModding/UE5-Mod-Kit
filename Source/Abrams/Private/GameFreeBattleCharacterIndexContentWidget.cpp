#include "GameFreeBattleCharacterIndexContentWidget.h"

UGameFreeBattleCharacterIndexContentWidget::UGameFreeBattleCharacterIndexContentWidget() {
    this->TeamCharacterWidget = NULL;
    this->TeamNameText = NULL;
    this->CharacterNameText = NULL;
    this->PlayableOptionBox = NULL;
    this->AILevelOptionBox = NULL;
    this->RandomImage = NULL;
    this->NameBackImage_PlayerTeam = NULL;
    this->NameBackImage_RivalTeam = NULL;
    this->CharacterIndex = EGameCharacterIndex::Index_1P;
}



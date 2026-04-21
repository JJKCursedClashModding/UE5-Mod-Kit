#include "GameOnlinePvEIntervalAction.h"

FGameOnlinePvEIntervalAction::FGameOnlinePvEIntervalAction() {
    this->CharacterIndex = EGameCharacterIndex::Index_1P;
    this->Action = EGameOnlinePvEIntervalAction::None;
    this->bDecide = false;
    this->bEnd = false;
}


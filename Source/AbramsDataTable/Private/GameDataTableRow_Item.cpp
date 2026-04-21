#include "GameDataTableRow_Item.h"

FGameDataTableRow_Item::FGameDataTableRow_Item() {
    this->ItemType = EGameItemType::None;
    this->SortingOrder = 0;
    this->SellPrice = 0;
    this->PossessionMax = 0;
    this->InitialPossession = 0;
    this->UserProgressFlag = 0;
}


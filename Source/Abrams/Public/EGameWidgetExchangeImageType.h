#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetExchangeImageType.generated.h"

UENUM()
enum class EGameWidgetExchangeImageType : int8 {
    None,
    Character_CutIn_Image_Left,
    Character_CutIn_Image_Right,
    Character_CutIn_Image_Center,
    Character_OutGame_Image,
    Character_OutGame_Icon,
    Character_CharacterSelect_Icon,
    Character_Icon_Normal,
    Character_Icon_Attack,
    Character_Icon_Damage,
    Character_Icon_Pinch,
    Character_Icon_CursedEnergyMax,
    Character_PvEInterval_Left,
    Character_PvEInterval_Right,
    Character_Arcade_Pair,
    Character_CommandList_Image,
    ItemThumbnailWatermark_Costume,
    Stage,
    Character_CutIn_Image_Up,
    Character_CutIn_Image_Down,
    Max,
};


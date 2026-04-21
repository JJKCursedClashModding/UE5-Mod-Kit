#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCaptureType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterCaptureType : uint8 {
    None,
    CharacterSelect,
    StoryCharacterSelect,
    VsAlly,
    VsEnemy,
    FreeBattle,
    PvEEquipment,
    PvEGrowth,
    Customize,
    Archive,
    FreeBattleImage,
    CP_270_TagCombo,
    Max,
    Invalid = 255,
};


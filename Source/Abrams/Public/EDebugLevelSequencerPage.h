#pragma once
#include "CoreMinimal.h"
#include "EDebugLevelSequencerPage.generated.h"

UENUM(BlueprintType)
enum class EDebugLevelSequencerPage : uint8 {
    Top,
    Load,
    MapSelect,
    CharacterSelect,
    LevelSequenceSelect,
    Max,
};


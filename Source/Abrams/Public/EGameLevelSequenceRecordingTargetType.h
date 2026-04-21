#pragma once
#include "CoreMinimal.h"
#include "EGameLevelSequenceRecordingTargetType.generated.h"

UENUM()
enum class EGameLevelSequenceRecordingTargetType : uint32 {
    None,
    Appearance,
    Appearance_B,
    Result = 32,
    ResultUnique = 128,
    SuperCursedEnergy = 32768,
    TagCombo = 1048576,
    TagComboUnique = 33554432,
    All = 4294967295,
};

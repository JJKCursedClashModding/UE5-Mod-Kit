#pragma once
#include "CoreMinimal.h"
#include "EGameMissionDifficulty.generated.h"

UENUM(BlueprintType)
enum class EGameMissionDifficulty : uint8 {
    None,
    Grade4,
    Grade3,
    Grade2,
    Grade1,
    SpecialGrade1,
    SpecialGrade2,
    SpecialGrade3,
    Invalid = 255,
};


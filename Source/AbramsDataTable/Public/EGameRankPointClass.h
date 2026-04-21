#pragma once
#include "CoreMinimal.h"
#include "EGameRankPointClass.generated.h"

UENUM(BlueprintType)
enum class EGameRankPointClass : uint8 {
    None,
    Grade4,
    Grade3,
    SemiGrade2,
    Grade2,
    SemiGrade1,
    Grade1,
    SpecialGrade,
    Max,
    Invalid = 255,
};


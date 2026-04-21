#pragma once
#include "CoreMinimal.h"
#include "EGameEmblemGradeType.generated.h"

UENUM(BlueprintType)
enum class EGameEmblemGradeType : uint8 {
    None,
    Grade1,
    Grade2,
    Grade3,
    Grade4,
    Invalid = 255,
};


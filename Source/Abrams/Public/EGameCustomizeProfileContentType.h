#pragma once
#include "CoreMinimal.h"
#include "EGameCustomizeProfileContentType.generated.h"

UENUM(BlueprintType)
enum class EGameCustomizeProfileContentType : uint8 {
    None,
    Age,
    Birth,
    Place,
    Grade,
    Technique,
    Skill,
    Hobby,
    Like,
    Dislike,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameRankPointGrade.generated.h"

UENUM(BlueprintType)
enum class EGameRankPointGrade : uint8 {
    None,
    Vermilion,
    Bronze,
    Silver,
    Gold,
    Platinum,
    Invalid = 255,
};


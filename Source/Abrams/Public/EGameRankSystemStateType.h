#pragma once
#include "CoreMinimal.h"
#include "EGameRankSystemStateType.generated.h"

UENUM(BlueprintType)
enum class EGameRankSystemStateType : uint8 {
    None,
    Back,
    RankSystem,
    RankSystemManual,
    PvPRanking,
};


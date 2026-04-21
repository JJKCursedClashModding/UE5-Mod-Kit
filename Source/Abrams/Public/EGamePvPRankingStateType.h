#pragma once
#include "CoreMinimal.h"
#include "EGamePvPRankingStateType.generated.h"

UENUM(BlueprintType)
enum class EGamePvPRankingStateType : uint8 {
    None,
    Back,
    Ranking,
    Filter,
    RankSystem,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineLeaderboardType.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineLeaderboardType : uint8 {
    RankMatchScore,
    RankMatchWinCount,
    RankMatchBattleCount,
    NormalModeScore,
    SurvivalModeScore,
    MaxDamage,
    TaskCompleteCount,
    Test,
    Invalid = 255,
};


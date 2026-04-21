#pragma once
#include "CoreMinimal.h"
#include "EGameVsEnemyBattleMode.generated.h"

UENUM(BlueprintType)
enum class EGameVsEnemyBattleMode : uint8 {
    None,
    Back,
    NormalMode,
    SurvivalMode,
    CharacterSettings,
    Ranking,
};


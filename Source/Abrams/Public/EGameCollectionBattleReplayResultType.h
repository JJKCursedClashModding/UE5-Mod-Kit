#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionBattleReplayResultType.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionBattleReplayResultType : uint8 {
    None,
    Win,
    Lose,
    TimeOver,
};


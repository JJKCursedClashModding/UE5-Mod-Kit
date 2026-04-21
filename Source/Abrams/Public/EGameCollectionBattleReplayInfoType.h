#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionBattleReplayInfoType.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionBattleReplayInfoType : uint8 {
    None,
    BattleReplay,
    SaveCountMessage,
};


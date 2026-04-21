#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionPlayRecordCommonType.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionPlayRecordCommonType : uint8 {
    None,
    TotalPlayTime,
    PvPTotalBattleCount,
    PvPTotalBattleWin,
    PvPMaxPlayCharacter,
    PvPMaxPlayerRank,
    PvETotalBattleCount,
    PvETotalBattleClear,
    PvEMaxPlayCharacter,
    PvEMaxRiskValue,
    StoryRelationComplete,
    TotalMoney,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameShopLineupUnlockConditionsType.generated.h"

UENUM(BlueprintType)
enum class EGameShopLineupUnlockConditionsType : uint8 {
    None,
    Default,
    StoryCharaRelateThreshold,
    StoryMissionClearRank,
    StoryAllMissionClearRank,
    StoryChapterAllMissionClearRank,
    StoryAllChapterClear,
    PvERiskValueThreshold,
    PvEModePlayCount,
    PvEModeClearCount,
    PvEModeClearRankCount,
    PvENormalModeClearCount,
    PvESurvivalModeClearCount,
    PvETaskClearCount,
    PvEBindingVowsEquipmentCount,
    PvEGrowthCharaLevelThreshold,
    PvEGrowthAnyCharaLevelThreshold,
    PvPBattleCount,
    PvPBattleWinCount,
    PvPBattleWinResultRankThreshold,
    UseCharacterCount,
    StageSelectCount,
    Invalid = 255,
};


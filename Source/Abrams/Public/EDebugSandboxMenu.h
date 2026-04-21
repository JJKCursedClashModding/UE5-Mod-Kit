#pragma once
#include "CoreMinimal.h"
#include "EDebugSandboxMenu.generated.h"

UENUM(BlueprintType)
enum class EDebugSandboxMenu : uint8 {
    None,
    Exit,
    SituationOverview,
    AutoSave,
    Loading,
    PvEInterval,
    LobbyChat,
    SituationOverviewChat,
    LobbyFindSession,
    Result,
    ResultChangeRankPoint,
    ResultMissionScoreList,
    CharaRelateLevel,
};


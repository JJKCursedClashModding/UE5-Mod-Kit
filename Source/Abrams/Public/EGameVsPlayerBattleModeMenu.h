#pragma once
#include "CoreMinimal.h"
#include "EGameVsPlayerBattleModeMenu.generated.h"

UENUM(BlueprintType)
enum class EGameVsPlayerBattleModeMenu : uint8 {
    None,
    Back,
    Solo,
    RankTag,
    FreeTag,
    Ranking,
    RankSystem,
};


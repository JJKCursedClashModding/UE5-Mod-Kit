#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineStatus.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineStatus : uint8 {
    Idle,
    PvPRankMatch,
    PvPFreeMatch,
    PvE,
};


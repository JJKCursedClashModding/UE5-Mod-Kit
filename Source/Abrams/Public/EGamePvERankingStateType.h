#pragma once
#include "CoreMinimal.h"
#include "EGamePvERankingStateType.generated.h"

UENUM(BlueprintType)
enum class EGamePvERankingStateType : uint8 {
    None,
    Back,
    Ranking,
    Filter,
};


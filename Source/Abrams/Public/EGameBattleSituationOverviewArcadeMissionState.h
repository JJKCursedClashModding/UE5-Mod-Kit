#pragma once
#include "CoreMinimal.h"
#include "EGameBattleSituationOverviewArcadeMissionState.generated.h"

UENUM(BlueprintType)
enum class EGameBattleSituationOverviewArcadeMissionState : uint8 {
    Invalid,
    Normal,
    Clear,
    Next,
};


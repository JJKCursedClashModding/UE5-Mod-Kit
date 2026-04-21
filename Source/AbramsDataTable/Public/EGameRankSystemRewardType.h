#pragma once
#include "CoreMinimal.h"
#include "EGameRankSystemRewardType.generated.h"

UENUM(BlueprintType)
enum class EGameRankSystemRewardType : uint8 {
    None,
    Money,
    Costume,
    Nickname,
    Plate,
    SituationOverviewPose,
    Invalid = 255,
};


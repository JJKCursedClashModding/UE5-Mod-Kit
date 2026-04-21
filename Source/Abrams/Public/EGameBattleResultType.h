#pragma once
#include "CoreMinimal.h"
#include "EGameBattleResultType.generated.h"

UENUM(BlueprintType)
enum class EGameBattleResultType : uint8 {
    Win_TeamA,
    Win_TeamB,
    Timeover,
    Invalid = 255,
};


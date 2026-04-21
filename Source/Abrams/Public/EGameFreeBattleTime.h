#pragma once
#include "CoreMinimal.h"
#include "EGameFreeBattleTime.generated.h"

UENUM(BlueprintType)
enum class EGameFreeBattleTime : uint8 {
    None,
    Time,
    Unlimited,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameFreeBattlePlayable.generated.h"

UENUM(BlueprintType)
enum class EGameFreeBattlePlayable : uint8 {
    None,
    Player,
    CPU,
};


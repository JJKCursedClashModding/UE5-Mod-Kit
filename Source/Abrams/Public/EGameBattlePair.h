#pragma once
#include "CoreMinimal.h"
#include "EGameBattlePair.generated.h"

UENUM()
enum class EGameBattlePair : uint32 {
    Pair_1vs1,
    Pair_1vs2,
    Pair_1vs3,
    Pair_1vs4,
    Pair_1vs5,
    Pair_2vs1,
    Pair_2vs2,
    Pair_2vs3,
    Pair_2vs4,
    Pair_3vs1,
    Pair_3vs2,
    Pair_3vs3,
    Invalid = 255,
};


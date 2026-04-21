#pragma once
#include "CoreMinimal.h"
#include "EGameFreeBattleCategory.generated.h"

UENUM()
enum class EGameFreeBattleCategory : uint32 {
    None,
    Battle,
    DefaultGauge,
    CharacterGauge = 4,
    All = 4294967295,
};

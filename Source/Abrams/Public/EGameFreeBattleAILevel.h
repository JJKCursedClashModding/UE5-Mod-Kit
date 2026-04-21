#pragma once
#include "CoreMinimal.h"
#include "EGameFreeBattleAILevel.generated.h"

UENUM(BlueprintType)
enum class EGameFreeBattleAILevel : uint8 {
    None,
    NoWork,
    Weak,
    Normal,
    Strong,
};


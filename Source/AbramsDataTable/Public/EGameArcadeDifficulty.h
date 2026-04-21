#pragma once
#include "CoreMinimal.h"
#include "EGameArcadeDifficulty.generated.h"

UENUM(BlueprintType)
enum class EGameArcadeDifficulty : uint8 {
    None,
    Easy,
    Normal,
    Hard,
    Invalid = 255,
};


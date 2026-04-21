#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerBreakType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerBreakType : uint8 {
    None,
    SpecialAttackFinish,
};


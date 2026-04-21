#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUniquePairPlaySituationType.generated.h"

UENUM()
enum class EGameSequencerUniquePairPlaySituationType : int32 {
    None,
    All,
    CommonOnly,
    UniqueOnly,
};


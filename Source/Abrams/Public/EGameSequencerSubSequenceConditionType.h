#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerSubSequenceConditionType.generated.h"

UENUM()
enum class EGameSequencerSubSequenceConditionType : int32 {
    None,
    FirstCharacterId,
    SecondCharacterId,
    ThirdCharacterId,
    FourthCharacterId,
    Platform,
};


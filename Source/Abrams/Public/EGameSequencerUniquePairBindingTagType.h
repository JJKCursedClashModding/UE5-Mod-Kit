#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUniquePairBindingTagType.generated.h"

UENUM()
enum class EGameSequencerUniquePairBindingTagType : int32 {
    None,
    FirstCharacter,
    FirstCharacterSupport,
    SecondCharacter,
    SecondCharacterSupport,
    ThirdCharacter,
    NoBindingNPC,
};


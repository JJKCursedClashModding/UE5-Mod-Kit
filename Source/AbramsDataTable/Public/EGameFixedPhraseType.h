#pragma once
#include "CoreMinimal.h"
#include "EGameFixedPhraseType.generated.h"

UENUM(BlueprintType)
enum class EGameFixedPhraseType : uint8 {
    None,
    Greeting,
    Communication,
    Thought,
    Tactics,
    Other,
    Invalid = 255,
};


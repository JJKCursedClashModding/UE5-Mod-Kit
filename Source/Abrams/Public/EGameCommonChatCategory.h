#pragma once
#include "CoreMinimal.h"
#include "EGameCommonChatCategory.generated.h"

UENUM(BlueprintType)
enum class EGameCommonChatCategory : uint8 {
    Conversation,
    Tactics,
    Unique,
    Stamp,
    LoopMin = Conversation,
    LoopMax = Stamp,
    Invalid,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameCommonChatIconCategory.generated.h"

UENUM(BlueprintType)
enum class EGameCommonChatIconCategory : uint8 {
    None,
    Conversation,
    Tactics,
    Unique,
    Provocation,
    Respect,
    Stamp,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameChatCategory.generated.h"

UENUM(BlueprintType)
enum class EGameChatCategory : uint8 {
    None,
    Conversation,
    Tactics,
    Unique,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameChatInputKey.generated.h"

UENUM(BlueprintType)
enum class EGameChatInputKey : uint8 {
    None,
    Chat_Left,
    Chat_Right,
    Chat_Up,
    Chat_Down,
};


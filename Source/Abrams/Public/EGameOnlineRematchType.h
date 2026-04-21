#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineRematchType.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineRematchType : uint8 {
    Retry,
    Close,
    RecreateSession,
    RejoinSession,
    ReturnToLobby,
    Invalid = 255,
};


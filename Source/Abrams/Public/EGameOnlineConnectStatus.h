#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineConnectStatus.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineConnectStatus : uint8 {
    Disconnect,
    Connecting,
    Connected,
    Invalid = 255,
};


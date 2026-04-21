#pragma once
#include "CoreMinimal.h"
#include "EMatchingPhaseStartMode.generated.h"

UENUM(BlueprintType)
enum class EMatchingPhaseStartMode : uint8 {
    Top,
    RecreateSession,
    RejoinSession,
    RestartSession,
    LobbyMatch,
    Invalid = 255,
};


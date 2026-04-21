#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSelectType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSelectType : uint8 {
    None,
    OnlinePvP,
    OnlinePvPSolo,
    OnlinePvE,
    OfflinePvE,
    Lobby,
    Arcade,
};


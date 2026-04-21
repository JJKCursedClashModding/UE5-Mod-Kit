#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSelectPlayerInfoShowTextFlags.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSelectPlayerInfoShowTextFlags : uint8 {
    None,
    ShowPlayerName,
    ShowPlayerIndex,
    ShowPlayerRank = 4,
    ShowPlayerRiskValue = 8,
    ShowPlayerLevel = 16,
};


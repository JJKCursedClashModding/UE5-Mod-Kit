#pragma once
#include "CoreMinimal.h"
#include "EGameCustomizeCardTileType.generated.h"

UENUM(BlueprintType)
enum class EGameCustomizeCardTileType : uint8 {
    None,
    Title,
    TopNickname,
    BottomNickname,
    Emblem,
    Plate,
    LoopMin = Title,
    LoopMax = Plate,
};


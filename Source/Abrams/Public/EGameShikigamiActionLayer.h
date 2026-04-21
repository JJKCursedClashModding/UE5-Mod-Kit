#pragma once
#include "CoreMinimal.h"
#include "EGameShikigamiActionLayer.generated.h"

UENUM(BlueprintType)
enum class EGameShikigamiActionLayer : uint8 {
    Default,
    Release,
    Summon,
    Invalid = 255,
};


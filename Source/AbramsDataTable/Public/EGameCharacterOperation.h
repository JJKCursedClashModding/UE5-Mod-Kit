#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterOperation.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterOperation : uint8 {
    None,
    Normal,
    Onslaught,
    Cooperation,
    Carefully,
    Escape,
    Berserker,
    Shooter,
    Unique_1,
    Unique_2,
    Invalid = 255,
};


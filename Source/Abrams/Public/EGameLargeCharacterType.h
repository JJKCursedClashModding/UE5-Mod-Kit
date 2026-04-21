#pragma once
#include "CoreMinimal.h"
#include "EGameLargeCharacterType.generated.h"

UENUM(BlueprintType)
enum class EGameLargeCharacterType : uint8 {
    None,
    Normal,
    BlowEnabled,
    Invalid = 255,
};


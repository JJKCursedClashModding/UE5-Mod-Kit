#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterFacialPartsMouth.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterFacialPartsMouth : uint8 {
    None,
    Close_01,
    Open_01,
    Open_02,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterIndex : uint8 {
    Index_1P,
    Index_2P,
    Index_3P,
    Index_4P,
    Index_5P,
    Index_6P,
    Max = Index_6P,
    Invalid = 255,
};


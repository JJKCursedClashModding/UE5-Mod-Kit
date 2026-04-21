#pragma once
#include "CoreMinimal.h"
#include "EGameNullifiesEffectType.generated.h"

UENUM(BlueprintType)
enum class EGameNullifiesEffectType : uint8 {
    None,
    Small,
    Middle,
    Large,
    Invalid = 255,
};


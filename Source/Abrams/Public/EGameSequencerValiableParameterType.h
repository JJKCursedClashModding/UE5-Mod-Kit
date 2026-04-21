#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerValiableParameterType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerValiableParameterType : uint8 {
    None,
    Bool,
    Scalar,
    Vector2D = 4,
    Vector = 8,
    Color = 16,
    Transform = 32,
    All = 63,
};


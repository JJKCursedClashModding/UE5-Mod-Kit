#pragma once
#include "CoreMinimal.h"
#include "EGameGroundEffectType.generated.h"

UENUM(BlueprintType)
enum class EGameGroundEffectType : uint8 {
    None,
    Normal,
    Brake,
    Upper,
    Step,
    Impact,
    Invalid = 255,
};


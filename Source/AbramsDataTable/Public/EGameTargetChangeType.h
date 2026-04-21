#pragma once
#include "CoreMinimal.h"
#include "EGameTargetChangeType.generated.h"

UENUM(BlueprintType)
enum class EGameTargetChangeType : uint8 {
    None,
    AttackActivate,
    Always,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameActionRigidityType.generated.h"

UENUM(BlueprintType)
enum class EGameActionRigidityType : uint8 {
    None,
    Light,
    Normal,
    Heavy,
    Invalid = 255,
};


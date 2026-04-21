#pragma once
#include "CoreMinimal.h"
#include "EGameEffectGroundCheckTargetType.generated.h"

UENUM(BlueprintType)
enum class EGameEffectGroundCheckTargetType : uint8 {
    None,
    Possessor,
    Own,
    Invalid = 255,
};


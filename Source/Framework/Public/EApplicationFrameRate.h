#pragma once
#include "CoreMinimal.h"
#include "EApplicationFrameRate.generated.h"

UENUM(BlueprintType)
enum class EApplicationFrameRate : uint8 {
    Variable30,
    Variable60,
    Variable85,
    Variable120,
    Variable144,
    Variable240,
    Fixed30,
    Fixed60,
    Unlimited,
    Invalid = 255,
};


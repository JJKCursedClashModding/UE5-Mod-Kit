#pragma once
#include "CoreMinimal.h"
#include "EDebugPlayCreditType.generated.h"

UENUM(BlueprintType)
enum class EDebugPlayCreditType : uint8 {
    Default,
    Short,
    Dlc1,
    Dlc2,
};


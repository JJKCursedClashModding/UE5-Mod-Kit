#pragma once
#include "CoreMinimal.h"
#include "EGameDebugLODSettingsType.generated.h"

UENUM(BlueprintType)
enum class EGameDebugLODSettingsType : uint8 {
    Default,
    ForceZero,
    ForceOne,
    Max,
};


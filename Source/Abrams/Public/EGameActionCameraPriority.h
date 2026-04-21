#pragma once
#include "CoreMinimal.h"
#include "EGameActionCameraPriority.generated.h"

UENUM(BlueprintType)
enum class EGameActionCameraPriority : uint8 {
    Battle,
    System,
    Max,
};


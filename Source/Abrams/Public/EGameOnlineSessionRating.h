#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineSessionRating.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineSessionRating : uint8 {
    Lower,
    Low,
    Middle,
    High,
    Higher,
    Open,
};


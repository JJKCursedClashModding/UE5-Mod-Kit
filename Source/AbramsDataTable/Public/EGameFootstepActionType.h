#pragma once
#include "CoreMinimal.h"
#include "EGameFootstepActionType.generated.h"

UENUM(BlueprintType)
enum class EGameFootstepActionType : uint8 {
    None,
    Run,
    Dash,
    Invalid = 255,
};


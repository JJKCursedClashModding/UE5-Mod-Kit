#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSelectInputType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSelectInputType : uint8 {
    None,
    Disable,
    Enable,
    SelectOnly,
    Partner,
};


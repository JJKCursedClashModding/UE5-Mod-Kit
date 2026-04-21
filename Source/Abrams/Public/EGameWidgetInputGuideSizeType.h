#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetInputGuideSizeType.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetInputGuideSizeType : uint8 {
    Invalid,
    Normal,
    Small,
    Tiny,
};


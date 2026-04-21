#pragma once
#include "CoreMinimal.h"
#include "EDebugWidgetLanguage.generated.h"

UENUM(BlueprintType)
enum class EDebugWidgetLanguage : uint8 {
    Ja,
    En,
    Invalid = 255,
};


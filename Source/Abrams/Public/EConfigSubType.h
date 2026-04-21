#pragma once
#include "CoreMinimal.h"
#include "EConfigSubType.generated.h"

UENUM(BlueprintType)
enum class EConfigSubType : uint8 {
    Brightness,
    KeyConfig,
    Tutorial,
    Max,
    Invalid = 255,
};


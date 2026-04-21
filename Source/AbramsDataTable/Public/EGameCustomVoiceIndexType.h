#pragma once
#include "CoreMinimal.h"
#include "EGameCustomVoiceIndexType.generated.h"

UENUM(BlueprintType)
enum class EGameCustomVoiceIndexType : uint8 {
    None,
    Default,
    TypeA,
    TypeB,
    Invalid = 255,
};


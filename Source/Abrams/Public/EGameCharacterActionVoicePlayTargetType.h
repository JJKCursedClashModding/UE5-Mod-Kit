#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterActionVoicePlayTargetType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterActionVoicePlayTargetType : uint8 {
    Owner,
    AllyOnly,
    All,
    Invalid = 255,
};


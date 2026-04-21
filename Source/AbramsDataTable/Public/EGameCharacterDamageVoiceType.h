#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterDamageVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterDamageVoiceType : uint8 {
    None,
    Weak,
    Medium,
    Heavy,
    LargeHeavy,
    Blow,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterDefaultActionVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterDefaultActionVoiceType : uint8 {
    BattleStart,
    Dash,
    Jump,
    Step,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterGuardVoiceType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterGuardVoiceType : uint8 {
    JustGuard,
    Guard,
    ProjectileGuard,
    GuardEnd,
    GuardBreak,
    Invalid = 255,
};


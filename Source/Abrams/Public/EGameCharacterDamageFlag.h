#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterDamageFlag.generated.h"

UENUM()
enum class EGameCharacterDamageFlag {
    None,
    IgnoreInvincible,
    IgnoreDead,
    BuffDebuff = 4,
    AddReceiveComboDisabled = 8,
    NotifyDisabled = 16,
    IgnoreCounter = 32,
    CheckJustGuard = 64,
    IgnoreArmor = 128,
    IgnoreGuardReaction = 256,
    IgnoreJustGuard = 512,
    All = 255,
};


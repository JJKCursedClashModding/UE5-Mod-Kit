#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterActionFlag.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterActionFlag : uint8 {
    None,
    ChangeSequenceEndDownAction,
    CounterAction,
    CasualDamageReceived = 4,
    GroundRestraintEnabled = 8,
    All = 255,
};


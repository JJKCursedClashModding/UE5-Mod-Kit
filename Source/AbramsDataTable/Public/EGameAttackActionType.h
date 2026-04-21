#pragma once
#include "CoreMinimal.h"
#include "EGameAttackActionType.generated.h"

UENUM(BlueprintType)
enum class EGameAttackActionType : uint8 {
    None,
    Attack,
    Charge,
    UnblockableAttack,
    AroundAttack,
    Invalid = 255,
};


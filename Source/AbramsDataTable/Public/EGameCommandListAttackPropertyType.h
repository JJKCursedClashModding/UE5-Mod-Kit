#pragma once
#include "CoreMinimal.h"
#include "EGameCommandListAttackPropertyType.generated.h"

UENUM(BlueprintType)
enum class EGameCommandListAttackPropertyType : uint8 {
    None,
    DirectAttack,
    Shooting,
    Buff,
    Debuff,
    Heal,
    Trap,
    Special,
    DomainExpansion,
    Invalid = 255,
};


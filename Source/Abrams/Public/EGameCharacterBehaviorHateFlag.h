#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterBehaviorHateFlag.generated.h"

UENUM()
enum class EGameCharacterBehaviorHateFlag {
    None,
    Target,
    LastAttacker,
    LastAttackerNotTarget = 4,
    LowestHitPoint = 8,
    NearestRival = 16,
    OwnerDownNonNearestRival = 32,
    TargetDown = 64,
    HalfTransfer = 128,
    DomainExpansionUser = 1024,
    NearTagComboDamage = 2048,
    StartNearestRival = 2097152,
    StartLastAttacker = 4194304,
    NotTarget = 1073741824,
};


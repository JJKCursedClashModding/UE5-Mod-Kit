#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterBehaviorMoveType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterBehaviorMoveType : uint8 {
    Idle,
    Chase,
    Escape,
    Dodge,
    ChaseTeammate,
    Keep,
    AvoidWall,
};


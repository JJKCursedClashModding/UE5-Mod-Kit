#pragma once
#include "CoreMinimal.h"
#include "EGameActorTeleportFlag.generated.h"

UENUM(BlueprintType)
enum class EGameActorTeleportFlag : uint8 {
    None,
    MoveStop,
    CollisionDisabled,
    All = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameDamageDirectionType.generated.h"

UENUM(BlueprintType)
enum class EGameDamageDirectionType : uint8 {
    None,
    AttackerDirection,
    ReceiverDirection,
    AttackerToReceiver,
    ActorDirection,
    ActorToReceiver,
    MovementDirection,
    Invalid = 255,
};


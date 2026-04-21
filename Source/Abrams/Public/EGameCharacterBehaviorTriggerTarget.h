#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterBehaviorTriggerTarget.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterBehaviorTriggerTarget : uint8 {
    Owner,
    Target,
    Attacker,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterBehaviorTriggerCondition.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterBehaviorTriggerCondition : uint8 {
    Equals,
    NotEquals,
    GreaterThanEquals,
    LessThanEquals,
};


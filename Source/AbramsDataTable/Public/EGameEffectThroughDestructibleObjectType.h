#pragma once
#include "CoreMinimal.h"
#include "EGameEffectThroughDestructibleObjectType.generated.h"

UENUM(BlueprintType)
enum class EGameEffectThroughDestructibleObjectType : uint8 {
    None,
    ThroughOnly,
    Always,
    AlwaysCheckObject,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameSimpleDomainCounterReceiveType.generated.h"

UENUM(BlueprintType)
enum class EGameSimpleDomainCounterReceiveType : uint8 {
    None,
    AttackActivate,
    Always,
    Invalid = 255,
};


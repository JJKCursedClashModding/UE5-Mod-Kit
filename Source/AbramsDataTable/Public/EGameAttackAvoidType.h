#pragma once
#include "CoreMinimal.h"
#include "EGameAttackAvoidType.generated.h"

UENUM(BlueprintType)
enum class EGameAttackAvoidType : uint8 {
    None,
    Guard,
    DodgeStep,
    AwayStep,
    AwayDash,
    AwayDashJump,
    Invalid = 255,
};


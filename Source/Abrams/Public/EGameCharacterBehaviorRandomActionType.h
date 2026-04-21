#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterBehaviorRandomActionType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterBehaviorRandomActionType : uint8 {
    None,
    Idle,
    Run,
    Jump,
    NormalAttack,
    Guard,
    Step,
    CursedEnergyAttack,
    SuperCursedEnergyAttack,
};


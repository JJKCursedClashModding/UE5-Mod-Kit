#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterTrainingAIMode.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterTrainingAIMode : uint8 {
    Idle,
    Guard,
    Jump,
    DashJump,
    Dash,
    Step,
    Run,
    NormalAttack_1,
    NormalAttack_1_1,
    NormalAttack_2,
    NormalAttack_2_1,
    NormalAttack_3,
    NormalAttack_3_1,
    CursedEnergyAttack_1,
    CursedEnergyAttack_1_1,
    CursedEnergyAttack_2,
    CursedEnergyAttack_2_1,
    SuperCursedEnergyAttack,
    ExtraAttack,
    Chase,
    Escape,
    RandomMove,
    Sandbag,
    TagCombo,
    StepDodge,
    JustGuard,
    Controller2P,
    AI,
    Num,
    Invalid = 255,
};


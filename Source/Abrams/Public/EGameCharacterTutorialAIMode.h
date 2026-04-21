#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterTutorialAIMode.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterTutorialAIMode : uint8 {
    Idle,
    TutorialAttack_1,
    TutorialAttack_2,
    TutorialGuard_1,
    AI,
    Num,
    Invalid = 255,
};


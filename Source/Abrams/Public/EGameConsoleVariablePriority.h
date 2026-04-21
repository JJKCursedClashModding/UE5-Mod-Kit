#pragma once
#include "CoreMinimal.h"
#include "EGameConsoleVariablePriority.generated.h"

UENUM()
enum class EGameConsoleVariablePriority {
    Invalid,
    LevelSequence = 300,
    Resident = 1000,
    Temp = 9999,
};


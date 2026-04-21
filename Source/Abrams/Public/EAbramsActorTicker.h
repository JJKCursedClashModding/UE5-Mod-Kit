#pragma once
#include "CoreMinimal.h"
#include "EAbramsActorTicker.generated.h"

UENUM()
enum class EAbramsActorTicker : int32 {
    Character,
    Trap,
    Effect,
    Manager,
};


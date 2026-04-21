#pragma once
#include "CoreMinimal.h"
#include "EGameFreeBattleSettings.generated.h"

UENUM(BlueprintType)
enum class EGameFreeBattleSettings : uint8 {
    None,
    Back,
    Character,
    Unique,
    Battle,
    CommandList,
    Start,
};


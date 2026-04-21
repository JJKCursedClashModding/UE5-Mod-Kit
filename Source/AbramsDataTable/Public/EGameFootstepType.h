#pragma once
#include "CoreMinimal.h"
#include "EGameFootstepType.generated.h"

UENUM(BlueprintType)
enum class EGameFootstepType : uint8 {
    None,
    ShoesMan,
    ShoesWoman,
    BareFoot,
    Zori,
    Gorilla,
    Totality,
    Invalid = 255,
};


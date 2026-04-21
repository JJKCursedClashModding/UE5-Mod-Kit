#pragma once
#include "CoreMinimal.h"
#include "EGameCursedEnergyCalcType.generated.h"

UENUM(BlueprintType)
enum class EGameCursedEnergyCalcType : uint8 {
    None,
    CheckOnly,
    Force,
    Invalid = 255,
};


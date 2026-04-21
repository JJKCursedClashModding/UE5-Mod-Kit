#pragma once
#include "CoreMinimal.h"
#include "EGameCursedEnergyGaugeType.generated.h"

UENUM(BlueprintType)
enum class EGameCursedEnergyGaugeType : uint8 {
    None,
    JujutsuSorcerers,
    CursedSpirits,
    Physical,
    CP_020,
    CP_110,
    Invalid = 255,
};


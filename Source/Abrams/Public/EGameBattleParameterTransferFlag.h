#pragma once
#include "CoreMinimal.h"
#include "EGameBattleParameterTransferFlag.generated.h"

UENUM(BlueprintType)
enum class EGameBattleParameterTransferFlag : uint8 {
    None,
    HitPoint,
    CursedEnergy,
    SoloSpecialAttackCount = 4,
    MaterialPattern = 8,
    ForceGauge = 16,
    ForceGaugeBarrier = 32,
    All = 63,
};


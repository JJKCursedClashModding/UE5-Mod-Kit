#pragma once
#include "CoreMinimal.h"
#include "EGameMissionOrderType.generated.h"

UENUM(BlueprintType)
enum class EGameMissionOrderType : uint8 {
    None,
    Normal,
    Boss,
    Protracted,
    Event,
    SuperCursedEnergyAttack,
    SuperCursedEnergyAttackFinish,
    DomainExpansion,
    SpecialTagCombo,
    Extra,
    Invalid = 255,
};


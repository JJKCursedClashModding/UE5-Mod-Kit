#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterBehaviorTriggerValue.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterBehaviorTriggerValue : uint8 {
    AttackerDistance,
    TeammateDistance,
    NearestRivalDistance,
    TargetDistance,
    TargetDistance2D,
    TargetToTeammateDistance,
    TargetZDifference,
    TargetZAngle,
    TargetToShikigamiDistance,
    GroundDistance,
    CeilingDistance,
    WallHeight,
    Operation,
    AILevel,
    UniqueValue1,
    UniqueValue2,
    UniqueValue3,
    UniqueValue4,
    UniqueValue5,
    OwnerHitPointRate,
    OwnerCursedEnergyRate,
    OwnerCursedEnergyValue,
    OwnerCursedEnergyLevel,
    OwnerGuardDurabilityRate,
    OwnerDashGuageRate,
    OwnerThroatGaugeRate,
    OwnerThroatTreatCount,
    OwnerUniqueMode,
    OwnerBuffDebuff,
    OwnerAttackActionCount,
    TargetHitPointRate,
    TargetGuardDurabilityRate,
    TargetBuffDebuff,
    ProjectionSorceryCancelCount,
};


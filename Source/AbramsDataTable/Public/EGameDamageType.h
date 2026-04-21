#pragma once
#include "CoreMinimal.h"
#include "EGameDamageType.generated.h"

UENUM(BlueprintType)
enum class EGameDamageType : uint8 {
    None,
    Normal,
    NormalAir,
    Down,
    Blow,
    BlowSmall,
    BlowLarge,
    BlowSpin,
    BlowGroundRestraint,
    GroundRestraint,
    Coercion,
    JugonStun,
    CentipedeRestraint,
    CentipedeRestraintFall,
    CrimsonBindingRestraint,
    SimpleDomainCounterStun,
    ProjectionSorcery,
    ProjectionSorceryBlow,
    FreezingRestraint,
    SoloSpecialAttack,
    TagCombo,
    TagComboBlow,
    TagComboCentipedeRestraint,
    TagComboProjectionSorcery,
    TagComboProjectionSorceryBlow,
    Invalid = 255,
};


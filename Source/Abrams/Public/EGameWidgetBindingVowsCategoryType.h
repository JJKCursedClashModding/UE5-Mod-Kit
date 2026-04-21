#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetBindingVowsCategoryType.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetBindingVowsCategoryType : uint8 {
    Invalid,
    AttackBuff,
    AttackDebuff,
    HitPointBuff,
    HitPointDebuff,
    MovementBuff,
    MovementDebuff,
    CursedEnergyBuff,
    CursedEnergyDebuff,
    OtherBuff,
    OtherDebuff,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCharacterFaceIconType.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetCharacterFaceIconType : uint8 {
    Normal,
    Attack,
    Damage,
    Pinch,
    CursedEnergyMax,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameRenderPostProcessMaterial.generated.h"

UENUM(BlueprintType)
enum class EGameRenderPostProcessMaterial : uint8 {
    RadialBlur,
    NegaPosition,
    Flare,
    ChromaticAberration,
    GrayScale,
    DeadEffect,
    TagComboDamage,
    TimeUpNotifyEffect,
    CursedEnergyLevelUpEffect,
    CursedEnergyLevelDownEffect,
    PlayerTeamPinchEffect,
    Invalid = 255,
};


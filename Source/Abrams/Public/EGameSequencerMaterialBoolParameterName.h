#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMaterialBoolParameterName.generated.h"

UENUM()
enum class EGameSequencerMaterialBoolParameterName : int32 {
    None,
    PointLight_Weight,
    BaseTexture_Override_Alpha,
    UseAdjustLight,
    HighLightPattern,
};


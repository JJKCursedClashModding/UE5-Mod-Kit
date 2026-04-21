#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUMGMaterialScalarParameterName.generated.h"

UENUM()
enum class EGameSequencerUMGMaterialScalarParameterName : int32 {
    None,
    BG_Position_U,
    BG_Position_V,
    BG_Scale,
    BG_Shake_Offset,
    BG_Shake_Offset_U,
    BG_Shake_Offset_V,
    BG_Shake_Speed_U,
    BG_Shake_Speed_V,
    Frame_MaskRate,
    Frame_FadeRate,
    Frame_Opacity,
    Speed_X,
    Speed_Y,
    Alpha,
    BG_Pivot_U,
    BG_Pivot_V,
    Frame_MaskRate_U,
    Frame_MaskRate_V,
    Frame_FadeRate_U,
    Frame_FadeRate_V,
    BG_FadeRate,
};


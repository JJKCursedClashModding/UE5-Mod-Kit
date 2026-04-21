#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUMGMaterialBoolParameterName.generated.h"

UENUM()
enum class EGameSequencerUMGMaterialBoolParameterName : int32 {
    None,
    BG_IsMovie,
    BG_IsCursedFrame,
    BG_IsFade_Top,
    BG_IsFade_Bottom,
    BG_IsFade_Left,
    BG_IsFade_Right,
};


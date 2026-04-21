#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMaterialVectorParameterName.generated.h"

UENUM()
enum class EGameSequencerMaterialVectorParameterName : int32 {
    None,
    Character_Light_Color,
    Character_Light_OverlayColor,
    Character_Light_ShadowColor,
    RimColor,
    BaseTexture_Override_Color,
    AfterLightColor,
    EmissiveColor,
    SecondShadowColor,
    ShadowColor,
    OutlineColor,
};


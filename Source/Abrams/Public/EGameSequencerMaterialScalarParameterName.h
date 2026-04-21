#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMaterialScalarParameterName.generated.h"

UENUM()
enum class EGameSequencerMaterialScalarParameterName : int32 {
    None,
    RimOffset,
    BaseTexture_Override_Alpha,
    Character_HighLight,
    OutlineWidth,
    WidthMin,
    FacePattern,
    ShadowRimOffset,
    DissolveOpacity,
    SecondShadowThreshold,
    Decal_Weight,
    TranslucentScale_Weight,
    U_Scroll,
    HighLightColorScale,
    ShadowThreshold,
    Shadow_Weight,
    SecondShadow_Weight,
    StoryDecal_Weight,
    OutlineEmissiveColor,
    Grayscale_Weight,
    DecayDecalDissolve_Weight,
    GradientDissolveOpacity,
    DecalDissolvePattern,
    DecalDissolve_Weight,
    Opacity,
    DitherAlpha,
    HideVCR_Weight,
};


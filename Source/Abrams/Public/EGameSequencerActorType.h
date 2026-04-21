#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerActorType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerActorType : uint8 {
    None,
    BillboardActor,
    BindingActor,
    BindingParameterActor,
    CameraFocusActor,
    CameraRootActor,
    CameraTransformActor,
    CameraActor,
    DecalActor,
    DirectionalLightActor,
    EmptyActor,
    LevelObject,
    OffsetActor,
    ParallaxMaterialActor,
    PointLightParamActor,
    PostProcessVolume,
    RootActor,
    SecondaryPointLightParamActor,
    SoundActor,
    TransformActor,
};


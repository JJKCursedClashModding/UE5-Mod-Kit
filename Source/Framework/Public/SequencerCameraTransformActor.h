#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerCameraTransformActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerCameraTransformActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerCameraTransformActor(const FObjectInitializer& ObjectInitializer);

};


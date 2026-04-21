#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerCameraFocusActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerCameraFocusActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerCameraFocusActor(const FObjectInitializer& ObjectInitializer);

};


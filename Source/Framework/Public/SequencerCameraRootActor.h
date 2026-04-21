#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerCameraRootActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerCameraRootActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerCameraRootActor(const FObjectInitializer& ObjectInitializer);

};


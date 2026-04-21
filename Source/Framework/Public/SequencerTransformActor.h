#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerTransformActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerTransformActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerTransformActor(const FObjectInitializer& ObjectInitializer);

};


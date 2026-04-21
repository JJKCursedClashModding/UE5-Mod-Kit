#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerBindingActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerBindingActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerBindingActor(const FObjectInitializer& ObjectInitializer);

};


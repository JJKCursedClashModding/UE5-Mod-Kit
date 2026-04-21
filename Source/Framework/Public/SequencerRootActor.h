#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerRootActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerRootActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerRootActor(const FObjectInitializer& ObjectInitializer);

};


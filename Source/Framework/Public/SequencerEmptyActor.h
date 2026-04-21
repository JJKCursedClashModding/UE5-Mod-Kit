#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerEmptyActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerEmptyActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerEmptyActor(const FObjectInitializer& ObjectInitializer);

};


#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerOffsetActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerOffsetActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerOffsetActor(const FObjectInitializer& ObjectInitializer);

};


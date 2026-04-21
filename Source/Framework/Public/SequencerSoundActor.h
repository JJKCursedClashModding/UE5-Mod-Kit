#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerSoundActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerSoundActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerSoundActor(const FObjectInitializer& ObjectInitializer);

};


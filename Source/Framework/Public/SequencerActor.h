#pragma once
#include "CoreMinimal.h"
#include "LevelSequenceActor.h"
#include "MovieSceneSequenceTickManagerClient.h"
#include "SequencerActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerActor : public ALevelSequenceActor, public IMovieSceneSequenceTickManagerClient {
    GENERATED_BODY()
public:
    ASequencerActor(const FObjectInitializer& ObjectInitializer);

    // IMovieSceneSequenceTickManagerClient — required pure virtual in UE 5.1
    virtual void TickFromSequenceTickManager(float DeltaSeconds, FMovieSceneEntitySystemRunner* Runner) override {}
};


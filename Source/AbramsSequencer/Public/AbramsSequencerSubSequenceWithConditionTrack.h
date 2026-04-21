#pragma once
#include "CoreMinimal.h"
#include "SequencerTrackInterface.h"
#include "Tracks/MovieSceneSubTrack.h"
#include "AbramsSequencerSubSequenceWithConditionTrack.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSubSequenceWithConditionTrack : public UMovieSceneSubTrack, public ISequencerTrackInterface {
    GENERATED_BODY()
public:
    UAbramsSequencerSubSequenceWithConditionTrack(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


    // Fix for true pure virtual functions not being implemented
};


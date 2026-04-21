#pragma once
#include "CoreMinimal.h"
#include "SequencerSoundActor.h"
#include "AbramsSequencerSoundActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerSoundActor : public ASequencerSoundActor {
    GENERATED_BODY()
public:
    AAbramsSequencerSoundActor(const FObjectInitializer& ObjectInitializer);

};


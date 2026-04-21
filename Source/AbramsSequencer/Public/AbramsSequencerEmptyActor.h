#pragma once
#include "CoreMinimal.h"
#include "SequencerEmptyActor.h"
#include "AbramsSequencerEmptyActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerEmptyActor : public ASequencerEmptyActor {
    GENERATED_BODY()
public:
    AAbramsSequencerEmptyActor(const FObjectInitializer& ObjectInitializer);

};


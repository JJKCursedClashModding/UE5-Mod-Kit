#pragma once
#include "CoreMinimal.h"
#include "SequencerRootActor.h"
#include "AbramsSequencerRootActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerRootActor : public ASequencerRootActor {
    GENERATED_BODY()
public:
    AAbramsSequencerRootActor(const FObjectInitializer& ObjectInitializer);

};


#pragma once
#include "CoreMinimal.h"
#include "SequencerBindingActor.h"
#include "AbramsSequencerBindingActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerBindingActor : public ASequencerBindingActor {
    GENERATED_BODY()
public:
    AAbramsSequencerBindingActor(const FObjectInitializer& ObjectInitializer);

};


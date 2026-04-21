#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "AbramsSequencerBindingParameterActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerBindingParameterActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    AAbramsSequencerBindingParameterActor(const FObjectInitializer& ObjectInitializer);

};


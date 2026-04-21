#pragma once
#include "CoreMinimal.h"
#include "SequencerTransformActor.h"
#include "AbramsSequencerTransformActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerTransformActor : public ASequencerTransformActor {
    GENERATED_BODY()
public:
    AAbramsSequencerTransformActor(const FObjectInitializer& ObjectInitializer);

};


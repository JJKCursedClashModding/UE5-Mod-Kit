#pragma once
#include "CoreMinimal.h"
#include "SequencerOffsetActor.h"
#include "AbramsSequencerOffsetActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerOffsetActor : public ASequencerOffsetActor {
    GENERATED_BODY()
public:
    AAbramsSequencerOffsetActor(const FObjectInitializer& ObjectInitializer);

};


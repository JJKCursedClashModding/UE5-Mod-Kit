#pragma once
#include "CoreMinimal.h"
#include "SequencerBillboardActor.h"
#include "AbramsSequencerBillboardActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerBillboardActor : public ASequencerBillboardActor {
    GENERATED_BODY()
public:
    AAbramsSequencerBillboardActor(const FObjectInitializer& ObjectInitializer);

};


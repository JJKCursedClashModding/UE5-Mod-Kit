#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "SequencerBillboardActor.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerBillboardActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
    ASequencerBillboardActor(const FObjectInitializer& ObjectInitializer);

};


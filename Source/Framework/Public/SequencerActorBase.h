#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SequencerActorInterface.h"
#include "SequencerActorBase.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerActorBase : public AActor, public ISequencerActorInterface {
    GENERATED_BODY()
public:
    ASequencerActorBase(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


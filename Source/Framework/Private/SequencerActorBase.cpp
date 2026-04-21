#include "SequencerActorBase.h"
#include "Components/SceneComponent.h"

ASequencerActorBase::ASequencerActorBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}



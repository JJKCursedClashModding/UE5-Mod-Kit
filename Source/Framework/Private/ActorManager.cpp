#include "ActorManager.h"
#include "Components/SceneComponent.h"

AActorManager::AActorManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}



#include "GameCharacterCaptureActor.h"
#include "Components/SceneComponent.h"

AGameCharacterCaptureActor::AGameCharacterCaptureActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->SpawnSceneCaptureBP = NULL;
}



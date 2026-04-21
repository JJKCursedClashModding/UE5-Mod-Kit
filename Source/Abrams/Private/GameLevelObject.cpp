#include "GameLevelObject.h"
#include "Components/SceneComponent.h"

AGameLevelObject::AGameLevelObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->MaterialController = NULL;
}



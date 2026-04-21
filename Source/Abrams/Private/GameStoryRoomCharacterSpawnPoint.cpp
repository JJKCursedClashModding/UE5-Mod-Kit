#include "GameStoryRoomCharacterSpawnPoint.h"
#include "Components/SceneComponent.h"

AGameStoryRoomCharacterSpawnPoint::AGameStoryRoomCharacterSpawnPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->SceneComponent = (USceneComponent*)RootComponent;
}



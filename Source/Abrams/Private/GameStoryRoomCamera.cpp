#include "GameStoryRoomCamera.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"

AGameStoryRoomCamera::AGameStoryRoomCamera(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->CameraComponent->SetupAttachment(RootComponent);
}



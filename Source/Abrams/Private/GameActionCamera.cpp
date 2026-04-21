#include "GameActionCamera.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGameActionCamera::AGameActionCamera(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    this->SpringArmComponent = (USpringArmComponent*)RootComponent;
    this->CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    this->PrevViewerTarget = NULL;
    this->CameraComponent->SetupAttachment(RootComponent);
}



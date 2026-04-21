#include "GameDebugCamera.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGameDebugCamera::AGameDebugCamera(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    this->Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    this->Camera->SetupAttachment(SpringArm);
    this->SpringArm->SetupAttachment(RootComponent);
}

void AGameDebugCamera::DebugCameraDeactivate_Implementation() {
}

void AGameDebugCamera::DebugCameraActivate_Implementation() {
}



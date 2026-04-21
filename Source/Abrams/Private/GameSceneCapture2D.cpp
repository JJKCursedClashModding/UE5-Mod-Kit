#include "GameSceneCapture2D.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/SceneComponent.h"

AGameSceneCapture2D::AGameSceneCapture2D(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->CaptureComponent2D = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("NewSceneCaptureComponent2D"));
    this->RenderTarget2D = NULL;
    this->CurrentCaptureParameter = NULL;
    this->CaptureComponent2D->SetupAttachment(RootComponent);
}



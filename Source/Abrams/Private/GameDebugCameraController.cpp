#include "GameDebugCameraController.h"

AGameDebugCameraController::AGameDebugCameraController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShowMouseCursor = true;
    this->ClickEventKeys.AddDefaulted(1);
}



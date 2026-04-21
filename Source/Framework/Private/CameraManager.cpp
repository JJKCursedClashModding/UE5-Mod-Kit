#include "CameraManager.h"

ACameraManager::ACameraManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultModifiers.AddDefaulted(1);
    this->CameraViewTarget = NULL;
}



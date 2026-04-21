#include "GameCameraManager.h"

AGameCameraManager::AGameCameraManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultModifiers.AddDefaulted(1);
    this->ActiveMode = NULL;
    this->ActionCamera = NULL;
    this->DebugCamera = NULL;
}



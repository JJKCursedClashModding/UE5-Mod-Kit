#include "AbramsPlayerController.h"
#include "GameCameraManager.h"
#include "GameCheatManager.h"

AAbramsPlayerController::AAbramsPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PlayerCameraManagerClass = AGameCameraManager::StaticClass();
    this->CheatClass = UGameCheatManager::StaticClass();
    this->ClickEventKeys.AddDefaulted(1);
}



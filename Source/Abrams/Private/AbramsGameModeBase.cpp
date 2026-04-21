#include "AbramsGameModeBase.h"
#include "AbramsPlayerController.h"

AAbramsGameModeBase::AAbramsGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GameSessionClass = NULL;
    this->PlayerControllerClass = AAbramsPlayerController::StaticClass();
    this->DefaultPawnClass = NULL;
    this->SpectatorClass = NULL;
    this->ReplaySpectatorPlayerControllerClass = NULL;
    this->ServerStatReplicatorClass = NULL;
}



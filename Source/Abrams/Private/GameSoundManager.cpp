#include "GameSoundManager.h"

AGameSoundManager::AGameSoundManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SystemSePlayer = NULL;
    this->AmbientSePlayer = NULL;
    this->SystemVoicePlayer = NULL;
}



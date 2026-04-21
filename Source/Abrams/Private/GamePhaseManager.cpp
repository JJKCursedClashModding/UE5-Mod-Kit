#include "GamePhaseManager.h"

AGamePhaseManager::AGamePhaseManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActiveGamePhase = NULL;
    this->NextGamePhase = NULL;
    this->PrevGamePhase = NULL;
}



#include "GameOnlineManager.h"

AGameOnlineManager::AGameOnlineManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OnlineBeaconHost = NULL;
    this->Kpi = NULL;
}



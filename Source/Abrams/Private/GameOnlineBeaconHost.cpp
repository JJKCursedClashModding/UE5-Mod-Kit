#include "GameOnlineBeaconHost.h"
#include "GameOnlineBeaconClient.h"

AGameOnlineBeaconHost::AGameOnlineBeaconHost(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BeaconTypeName = TEXT("GameOnlineBeaconClient");
    this->ClientBeaconActorClass = AGameOnlineBeaconClient::StaticClass();
}



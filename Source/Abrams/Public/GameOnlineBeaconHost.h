#pragma once
#include "CoreMinimal.h"
#include "OnlineBeaconHostObject.h"
#include "GameOnlineBeaconInterface.h"
#include "GameOnlineBeaconHost.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API AGameOnlineBeaconHost : public AOnlineBeaconHostObject, public IGameOnlineBeaconInterface {
    GENERATED_BODY()
public:
    AGameOnlineBeaconHost(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


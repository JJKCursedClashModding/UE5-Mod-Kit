#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameOnlineBeaconInterface.h"
#include "GameOnlineBeaconMock.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameOnlineBeaconMock : public AActor, public IGameOnlineBeaconInterface {
    GENERATED_BODY()
public:
    AGameOnlineBeaconMock(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


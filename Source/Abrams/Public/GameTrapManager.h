#pragma once
#include "CoreMinimal.h"
#include "ActorManager.h"
#include "GameTrapManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameTrapManager : public AActorManager {
    GENERATED_BODY()
public:
    AGameTrapManager(const FObjectInitializer& ObjectInitializer);

};


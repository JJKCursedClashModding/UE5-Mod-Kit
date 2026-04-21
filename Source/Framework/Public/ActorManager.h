#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API AActorManager : public AActor {
    GENERATED_BODY()
public:
    AActorManager(const FObjectInitializer& ObjectInitializer);

};


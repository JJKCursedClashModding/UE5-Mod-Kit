#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorTicker.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API AActorTicker : public AActor {
    GENERATED_BODY()
public:
    AActorTicker(const FObjectInitializer& ObjectInitializer);

};


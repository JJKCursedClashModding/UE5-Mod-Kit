#pragma once
#include "CoreMinimal.h"
#include "ActorManager.h"
#include "GameCharacterManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameCharacterManager : public AActorManager {
    GENERATED_BODY()
public:
    AGameCharacterManager(const FObjectInitializer& ObjectInitializer);

};


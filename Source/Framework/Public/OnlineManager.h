#pragma once
#include "CoreMinimal.h"
#include "ActorManager.h"
#include "OnlineManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API AOnlineManager : public AActorManager {
    GENERATED_BODY()
public:
    AOnlineManager(const FObjectInitializer& ObjectInitializer);

};


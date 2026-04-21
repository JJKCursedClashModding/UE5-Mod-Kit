#pragma once
#include "CoreMinimal.h"
#include "ActorManager.h"
#include "RenderManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ARenderManager : public AActorManager {
    GENERATED_BODY()
public:
    ARenderManager(const FObjectInitializer& ObjectInitializer);

};


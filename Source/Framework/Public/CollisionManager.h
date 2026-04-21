#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ACollisionManager : public AActor {
    GENERATED_BODY()
public:
    ACollisionManager(const FObjectInitializer& ObjectInitializer);

};


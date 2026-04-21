#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ATimeManager : public AActor {
    GENERATED_BODY()
public:
    ATimeManager(const FObjectInitializer& ObjectInitializer);

};


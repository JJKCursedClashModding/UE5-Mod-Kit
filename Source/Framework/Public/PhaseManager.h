#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhaseManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API APhaseManager : public AActor {
    GENERATED_BODY()
public:
    APhaseManager(const FObjectInitializer& ObjectInitializer);

};


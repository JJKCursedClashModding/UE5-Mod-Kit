#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PauseManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API APauseManager : public AActor {
    GENERATED_BODY()
public:
    APauseManager(const FObjectInitializer& ObjectInitializer);

};


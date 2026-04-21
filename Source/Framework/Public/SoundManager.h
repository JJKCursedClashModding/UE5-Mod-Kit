#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API ASoundManager : public AActor {
    GENERATED_BODY()
public:
    ASoundManager(const FObjectInitializer& ObjectInitializer);

};


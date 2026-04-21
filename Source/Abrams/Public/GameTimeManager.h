#pragma once
#include "CoreMinimal.h"
#include "TickableInterface.h"
#include "TimeManager.h"
#include "GameTimeManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameTimeManager : public ATimeManager, public ITickableInterface {
    GENERATED_BODY()
public:
    AGameTimeManager(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


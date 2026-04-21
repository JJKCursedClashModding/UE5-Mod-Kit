#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameCaptureActor.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API AGameCaptureActor : public AActor {
    GENERATED_BODY()
public:
    AGameCaptureActor(const FObjectInitializer& ObjectInitializer);

};


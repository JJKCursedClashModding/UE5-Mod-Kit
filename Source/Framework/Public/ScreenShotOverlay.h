#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScreenShotOverlay.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API AScreenShotOverlay : public AActor {
    GENERATED_BODY()
public:
    AScreenShotOverlay(const FObjectInitializer& ObjectInitializer);

};


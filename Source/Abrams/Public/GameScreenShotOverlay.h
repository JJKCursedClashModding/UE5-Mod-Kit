#pragma once
#include "CoreMinimal.h"
#include "ScreenShotOverlay.h"
#include "GameScreenShotOverlay.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameScreenShotOverlay : public AScreenShotOverlay {
    GENERATED_BODY()
public:
    AGameScreenShotOverlay(const FObjectInitializer& ObjectInitializer);

};


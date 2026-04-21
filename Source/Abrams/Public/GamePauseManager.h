#pragma once
#include "CoreMinimal.h"
#include "PauseManager.h"
#include "GamePauseManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGamePauseManager : public APauseManager {
    GENERATED_BODY()
public:
    AGamePauseManager(const FObjectInitializer& ObjectInitializer);

};


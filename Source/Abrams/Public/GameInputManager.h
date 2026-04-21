#pragma once
#include "CoreMinimal.h"
#include "InputManager.h"
#include "GameInputManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameInputManager : public AInputManager {
    GENERATED_BODY()
public:
    AGameInputManager(const FObjectInitializer& ObjectInitializer);

};


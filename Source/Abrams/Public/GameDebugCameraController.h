#pragma once
#include "CoreMinimal.h"
#include "Engine/DebugCameraController.h"
#include "GameDebugCameraController.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameDebugCameraController : public ADebugCameraController {
    GENERATED_BODY()
public:
    AGameDebugCameraController(const FObjectInitializer& ObjectInitializer);

};


#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AbramsPlayerController.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AAbramsPlayerController : public APlayerController {
    GENERATED_BODY()
public:
    AAbramsPlayerController(const FObjectInitializer& ObjectInitializer);

};


#pragma once
#include "CoreMinimal.h"
#include "GameActorMovementController.h"
#include "GameCharacterMovementController.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterMovementController : public UGameActorMovementController {
    GENERATED_BODY()
public:
    UGameCharacterMovementController();

};


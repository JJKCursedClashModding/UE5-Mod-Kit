#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameActorMovementController.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGameActorMovementController : public UObject {
    GENERATED_BODY()
public:
    UGameActorMovementController();

};


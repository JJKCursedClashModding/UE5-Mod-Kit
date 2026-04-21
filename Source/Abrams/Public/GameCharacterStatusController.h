#pragma once
#include "CoreMinimal.h"
#include "GameActorStatusController.h"
#include "GameCharacterStatusController.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterStatusController : public UGameActorStatusController {
    GENERATED_BODY()
public:
    UGameCharacterStatusController();

};


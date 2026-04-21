#pragma once
#include "CoreMinimal.h"
#include "GameActorBoneController.h"
#include "GameCharacterBoneController.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterBoneController : public UGameActorBoneController {
    GENERATED_BODY()
public:
    UGameCharacterBoneController();

};


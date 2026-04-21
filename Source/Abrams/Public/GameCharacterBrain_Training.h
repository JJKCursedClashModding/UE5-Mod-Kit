#pragma once
#include "CoreMinimal.h"
#include "GameCharacterBrain_AI.h"
#include "GameCharacterBrain_Training.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterBrain_Training : public UGameCharacterBrain_AI {
    GENERATED_BODY()
public:
    UGameCharacterBrain_Training();

};


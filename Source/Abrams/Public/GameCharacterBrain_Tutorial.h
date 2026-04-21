#pragma once
#include "CoreMinimal.h"
#include "GameCharacterBrain_AI.h"
#include "GameCharacterBrain_Tutorial.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterBrain_Tutorial : public UGameCharacterBrain_AI {
    GENERATED_BODY()
public:
    UGameCharacterBrain_Tutorial();

};


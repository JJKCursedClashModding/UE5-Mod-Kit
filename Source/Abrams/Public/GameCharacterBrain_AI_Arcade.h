#pragma once
#include "CoreMinimal.h"
#include "GameCharacterBrain_AI_PvE.h"
#include "GameCharacterBrain_AI_Arcade.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterBrain_AI_Arcade : public UGameCharacterBrain_AI_PvE {
    GENERATED_BODY()
public:
    UGameCharacterBrain_AI_Arcade();

};


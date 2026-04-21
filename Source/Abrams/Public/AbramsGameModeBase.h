#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AbramsGameModeBase.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API AAbramsGameModeBase : public AGameModeBase {
    GENERATED_BODY()
public:
    AAbramsGameModeBase(const FObjectInitializer& ObjectInitializer);

};


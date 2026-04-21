#pragma once
#include "CoreMinimal.h"
#include "CollisionKeeper.h"
#include "GameCollisionKeeper.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCollisionKeeper : public UCollisionKeeper {
    GENERATED_BODY()
public:
    UGameCollisionKeeper();

};


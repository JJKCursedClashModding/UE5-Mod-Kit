#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ModifiableInterface.h"
#include "GameCollisionModifier.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCollisionModifier : public UObject, public IModifiableInterface {
    GENERATED_BODY()
public:
    UGameCollisionModifier();


    // Fix for true pure virtual functions not being implemented
};


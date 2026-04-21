#pragma once
#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "ModifiableInterface.h"
#include "GameSphereComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameSphereComponent : public USphereComponent, public IModifiableInterface {
    GENERATED_BODY()
public:
    UGameSphereComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


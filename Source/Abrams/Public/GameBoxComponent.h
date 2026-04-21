#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "ModifiableInterface.h"
#include "GameBoxComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameBoxComponent : public UBoxComponent, public IModifiableInterface {
    GENERATED_BODY()
public:
    UGameBoxComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


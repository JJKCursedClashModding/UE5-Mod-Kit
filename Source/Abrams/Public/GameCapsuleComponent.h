#pragma once
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "ModifiableInterface.h"
#include "GameCapsuleComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameCapsuleComponent : public UCapsuleComponent, public IModifiableInterface {
    GENERATED_BODY()
public:
    UGameCapsuleComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


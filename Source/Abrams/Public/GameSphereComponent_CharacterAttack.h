#pragma once
#include "CoreMinimal.h"
#include "GameCollisionParameterInterface.h"
#include "GameSphereComponent.h"
#include "GameSphereComponent_CharacterAttack.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameSphereComponent_CharacterAttack : public UGameSphereComponent, public IGameCollisionParameterInterface {
    GENERATED_BODY()
public:
    UGameSphereComponent_CharacterAttack(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


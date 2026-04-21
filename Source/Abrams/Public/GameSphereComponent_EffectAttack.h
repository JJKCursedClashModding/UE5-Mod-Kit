#pragma once
#include "CoreMinimal.h"
#include "GameCollisionParameterInterface.h"
#include "GameSphereComponent.h"
#include "GameSphereComponent_EffectAttack.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameSphereComponent_EffectAttack : public UGameSphereComponent, public IGameCollisionParameterInterface {
    GENERATED_BODY()
public:
    UGameSphereComponent_EffectAttack(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


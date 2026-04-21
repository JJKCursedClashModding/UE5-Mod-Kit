#pragma once
#include "CoreMinimal.h"
#include "GameCapsuleComponent.h"
#include "GameCollisionParameterInterface.h"
#include "GameCapsuleComponent_CharacterAttack.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameCapsuleComponent_CharacterAttack : public UGameCapsuleComponent, public IGameCollisionParameterInterface {
    GENERATED_BODY()
public:
    UGameCapsuleComponent_CharacterAttack(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};


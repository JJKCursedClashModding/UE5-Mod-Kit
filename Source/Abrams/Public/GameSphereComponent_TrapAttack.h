#pragma once
#include "CoreMinimal.h"
#include "GameSphereComponent.h"
#include "GameSphereComponent_TrapAttack.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameSphereComponent_TrapAttack : public UGameSphereComponent {
    GENERATED_BODY()
public:
    UGameSphereComponent_TrapAttack(const FObjectInitializer& ObjectInitializer);

};


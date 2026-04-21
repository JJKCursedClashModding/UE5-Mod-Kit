#pragma once
#include "CoreMinimal.h"
#include "GameSphereComponent.h"
#include "GameSphereComponent_TrapDamage.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameSphereComponent_TrapDamage : public UGameSphereComponent {
    GENERATED_BODY()
public:
    UGameSphereComponent_TrapDamage(const FObjectInitializer& ObjectInitializer);

};


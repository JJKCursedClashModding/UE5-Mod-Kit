#pragma once
#include "CoreMinimal.h"
#include "GameSphereComponent.h"
#include "GameSphereComponent_EffectDamage.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameSphereComponent_EffectDamage : public UGameSphereComponent {
    GENERATED_BODY()
public:
    UGameSphereComponent_EffectDamage(const FObjectInitializer& ObjectInitializer);

};


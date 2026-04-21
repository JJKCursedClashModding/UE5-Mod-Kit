#pragma once
#include "CoreMinimal.h"
#include "GameCapsuleComponent.h"
#include "GameCapsuleComponent_EffectDamage.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameCapsuleComponent_EffectDamage : public UGameCapsuleComponent {
    GENERATED_BODY()
public:
    UGameCapsuleComponent_EffectDamage(const FObjectInitializer& ObjectInitializer);

};


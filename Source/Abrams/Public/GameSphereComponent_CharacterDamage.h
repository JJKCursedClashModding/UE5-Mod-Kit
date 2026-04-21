#pragma once
#include "CoreMinimal.h"
#include "GameSphereComponent.h"
#include "GameSphereComponent_CharacterDamage.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameSphereComponent_CharacterDamage : public UGameSphereComponent {
    GENERATED_BODY()
public:
    UGameSphereComponent_CharacterDamage(const FObjectInitializer& ObjectInitializer);

};


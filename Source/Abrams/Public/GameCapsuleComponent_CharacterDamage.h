#pragma once
#include "CoreMinimal.h"
#include "GameCapsuleComponent.h"
#include "GameCapsuleComponent_CharacterDamage.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameCapsuleComponent_CharacterDamage : public UGameCapsuleComponent {
    GENERATED_BODY()
public:
    UGameCapsuleComponent_CharacterDamage(const FObjectInitializer& ObjectInitializer);

};


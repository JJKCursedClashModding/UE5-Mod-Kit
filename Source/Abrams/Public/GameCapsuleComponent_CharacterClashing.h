#pragma once
#include "CoreMinimal.h"
#include "GameCapsuleComponent.h"
#include "GameCapsuleComponent_CharacterClashing.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameCapsuleComponent_CharacterClashing : public UGameCapsuleComponent {
    GENERATED_BODY()
public:
    UGameCapsuleComponent_CharacterClashing(const FObjectInitializer& ObjectInitializer);

};


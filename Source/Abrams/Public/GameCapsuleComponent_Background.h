#pragma once
#include "CoreMinimal.h"
#include "GameCapsuleComponent.h"
#include "GameCapsuleComponent_Background.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameCapsuleComponent_Background : public UGameCapsuleComponent {
    GENERATED_BODY()
public:
    UGameCapsuleComponent_Background(const FObjectInitializer& ObjectInitializer);

};


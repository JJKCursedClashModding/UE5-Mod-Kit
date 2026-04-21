#pragma once
#include "CoreMinimal.h"
#include "GameSphereComponent.h"
#include "GameSphereComponent_Background.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameSphereComponent_Background : public UGameSphereComponent {
    GENERATED_BODY()
public:
    UGameSphereComponent_Background(const FObjectInitializer& ObjectInitializer);

};


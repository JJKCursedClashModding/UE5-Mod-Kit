#pragma once
#include "CoreMinimal.h"
#include "GameBoxComponent.h"
#include "GameBoxComponent_Background.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameBoxComponent_Background : public UGameBoxComponent {
    GENERATED_BODY()
public:
    UGameBoxComponent_Background(const FObjectInitializer& ObjectInitializer);

};


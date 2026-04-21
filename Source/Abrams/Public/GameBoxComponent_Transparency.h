#pragma once
#include "CoreMinimal.h"
#include "GameBoxComponent.h"
#include "GameBoxComponent_Transparency.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameBoxComponent_Transparency : public UGameBoxComponent {
    GENERATED_BODY()
public:
    UGameBoxComponent_Transparency(const FObjectInitializer& ObjectInitializer);

};


#pragma once
#include "CoreMinimal.h"
#include "GameBoxComponent.h"
#include "GameBoxComponent_Destructible.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameBoxComponent_Destructible : public UGameBoxComponent {
    GENERATED_BODY()
public:
    UGameBoxComponent_Destructible(const FObjectInitializer& ObjectInitializer);

};


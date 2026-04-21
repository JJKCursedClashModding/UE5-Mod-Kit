#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameWidgetNiagaraEffectActor.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameWidgetNiagaraEffectActor : public AGameActor {
    GENERATED_BODY()
public:
    AGameWidgetNiagaraEffectActor(const FObjectInitializer& ObjectInitializer);

};


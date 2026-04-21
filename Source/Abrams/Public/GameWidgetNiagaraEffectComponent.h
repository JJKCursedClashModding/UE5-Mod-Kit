#pragma once
#include "CoreMinimal.h"
#include "NiagaraUIComponent.h"
#include "GameWidgetNiagaraEffectComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameWidgetNiagaraEffectComponent : public UNiagaraUIComponent {
    GENERATED_BODY()
public:
    UGameWidgetNiagaraEffectComponent(const FObjectInitializer& ObjectInitializer);

};


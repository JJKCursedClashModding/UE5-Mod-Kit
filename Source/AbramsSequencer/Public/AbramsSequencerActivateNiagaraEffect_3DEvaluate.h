#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateBindingEffectBase.h"
#include "AbramsSequencerActivateNiagaraEffect_3DEvaluate.generated.h"

class UNiagaraComponent;

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerActivateNiagaraEffect_3DEvaluate : public FAbramsSequencerEvaluateBindingEffectBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraComponent*> NiagaraComponents;
    
public:
    FAbramsSequencerActivateNiagaraEffect_3DEvaluate();
};


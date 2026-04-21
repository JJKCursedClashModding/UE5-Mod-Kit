#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateUMGBindingNiagaraComponentBase.h"
#include "AbramsSequencerSetUMGNiagaraIntParameterEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetUMGNiagaraIntParameterEvaluate : public FAbramsSequencerEvaluateUMGBindingNiagaraComponentBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetUMGNiagaraIntParameterEvaluate();
};


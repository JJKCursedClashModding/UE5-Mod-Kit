#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateUMGBindingNiagaraComponentBase.h"
#include "AbramsSequencerSetUMGNiagaraFloatParameterEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetUMGNiagaraFloatParameterEvaluate : public FAbramsSequencerEvaluateUMGBindingNiagaraComponentBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetUMGNiagaraFloatParameterEvaluate();
};


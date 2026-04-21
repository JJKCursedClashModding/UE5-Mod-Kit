#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateUMGBindingNiagaraComponentBase.h"
#include "AbramsSequencerSetUMGNiagaraVectorParameterEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetUMGNiagaraVectorParameterEvaluate : public FAbramsSequencerEvaluateUMGBindingNiagaraComponentBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetUMGNiagaraVectorParameterEvaluate();
};


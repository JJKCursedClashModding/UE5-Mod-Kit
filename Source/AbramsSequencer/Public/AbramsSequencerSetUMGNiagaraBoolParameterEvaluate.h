#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateUMGBindingNiagaraComponentBase.h"
#include "AbramsSequencerSetUMGNiagaraBoolParameterEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetUMGNiagaraBoolParameterEvaluate : public FAbramsSequencerEvaluateUMGBindingNiagaraComponentBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetUMGNiagaraBoolParameterEvaluate();
};


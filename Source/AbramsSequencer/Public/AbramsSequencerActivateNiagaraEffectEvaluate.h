#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateUMGBindingBase.h"
#include "AbramsSequencerActivateNiagaraEffectEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerActivateNiagaraEffectEvaluate : public FAbramsSequencerEvaluateUMGBindingBase {
    GENERATED_BODY()
public:
    FAbramsSequencerActivateNiagaraEffectEvaluate();

private:
    virtual UScriptStruct& GetScriptStructImpl() const override { return *StaticStruct(); }
};


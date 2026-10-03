#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateUMGBindingBase.h"
#include "AbramsSequencerSetUMGMaterialScalarParameterEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetUMGMaterialScalarParameterEvaluate : public FAbramsSequencerEvaluateUMGBindingBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetUMGMaterialScalarParameterEvaluate();

private:
    virtual UScriptStruct& GetScriptStructImpl() const override { return *StaticStruct(); }
};


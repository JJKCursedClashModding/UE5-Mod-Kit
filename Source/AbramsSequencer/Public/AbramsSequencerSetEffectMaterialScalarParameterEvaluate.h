#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateEffectMaterialParamBase.h"
#include "AbramsSequencerSetEffectMaterialScalarParameterEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetEffectMaterialScalarParameterEvaluate : public FAbramsSequencerEvaluateEffectMaterialParamBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetEffectMaterialScalarParameterEvaluate();
};


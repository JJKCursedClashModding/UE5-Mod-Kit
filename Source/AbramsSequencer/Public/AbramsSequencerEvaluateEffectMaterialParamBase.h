#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateBindingEffectBase.h"
#include "AbramsSequencerEvaluateEffectMaterialParamBase.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerEvaluateEffectMaterialParamBase : public FAbramsSequencerEvaluateBindingEffectBase {
    GENERATED_BODY()
public:
    FAbramsSequencerEvaluateEffectMaterialParamBase();
};


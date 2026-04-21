#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluatePostProcessMaterialBase.h"
#include "AbramsSequencerSetDeadEffectEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetDeadEffectEvaluate : public FAbramsSequencerEvaluatePostProcessMaterialBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetDeadEffectEvaluate();
};


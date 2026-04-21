#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateBase.h"
#include "AbramsSequencerSetFrustumCullingEnabledEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetFrustumCullingEnabledEvaluate : public FAbramsSequencerEvaluateBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetFrustumCullingEnabledEvaluate();
};


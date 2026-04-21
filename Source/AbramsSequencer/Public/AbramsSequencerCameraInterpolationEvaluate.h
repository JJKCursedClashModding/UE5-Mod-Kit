#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateBindingBase.h"
#include "AbramsSequencerCameraInterpolationEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerCameraInterpolationEvaluate : public FAbramsSequencerEvaluateBindingBase {
    GENERATED_BODY()
public:
    FAbramsSequencerCameraInterpolationEvaluate();
};


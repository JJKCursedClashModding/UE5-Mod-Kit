#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateAnimationBase.h"
#include "AbramsSequencerPlayAnimSequenceEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerPlayAnimSequenceEvaluate : public FAbramsSequencerEvaluateAnimationBase {
    GENERATED_BODY()
public:
    FAbramsSequencerPlayAnimSequenceEvaluate();
};


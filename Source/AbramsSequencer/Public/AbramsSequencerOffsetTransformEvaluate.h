#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateGameActorConstraintBase.h"
#include "AbramsSequencerOffsetTransformEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerOffsetTransformEvaluate : public FAbramsSequencerEvaluateGameActorConstraintBase {
    GENERATED_BODY()
public:
    FAbramsSequencerOffsetTransformEvaluate();
};


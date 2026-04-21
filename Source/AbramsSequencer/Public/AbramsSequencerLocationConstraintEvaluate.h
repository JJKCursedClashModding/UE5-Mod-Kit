#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluate3DConstraintBase.h"
#include "AbramsSequencerLocationConstraintEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerLocationConstraintEvaluate : public FAbramsSequencerEvaluate3DConstraintBase {
    GENERATED_BODY()
public:
    FAbramsSequencerLocationConstraintEvaluate();
};


#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluate3DConstraintBase.h"
#include "AbramsSequencerLookAtConstraintEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerLookAtConstraintEvaluate : public FAbramsSequencerEvaluate3DConstraintBase {
    GENERATED_BODY()
public:
    FAbramsSequencerLookAtConstraintEvaluate();
};


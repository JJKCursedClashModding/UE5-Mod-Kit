#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateBase.h"
#include "AbramsSequencerResetPhysicsEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerResetPhysicsEvaluate : public FAbramsSequencerEvaluateBase {
    GENERATED_BODY()
public:
    FAbramsSequencerResetPhysicsEvaluate();
};


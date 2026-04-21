#pragma once
#include "CoreMinimal.h"
#include "SequencerEvaluateBase.h"
#include "AbramsSequencerEvaluateBase.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerEvaluateBase : public FSequencerEvaluateBase {
    GENERATED_BODY()
public:
    FAbramsSequencerEvaluateBase();
};


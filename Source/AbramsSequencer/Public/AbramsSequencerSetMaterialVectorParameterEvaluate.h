#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateBase.h"
#include "AbramsSequencerSetMaterialVectorParameterEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetMaterialVectorParameterEvaluate : public FAbramsSequencerEvaluateBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetMaterialVectorParameterEvaluate();
};


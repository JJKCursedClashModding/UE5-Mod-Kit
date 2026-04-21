#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateBase.h"
#include "AbramsSequencerWeaponVisibilityEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerWeaponVisibilityEvaluate : public FAbramsSequencerEvaluateBase {
    GENERATED_BODY()
public:
    FAbramsSequencerWeaponVisibilityEvaluate();
};


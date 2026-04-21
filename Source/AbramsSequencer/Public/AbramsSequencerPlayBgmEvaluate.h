#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateMasterSoundBase.h"
#include "AbramsSequencerPlayBgmEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerPlayBgmEvaluate : public FAbramsSequencerEvaluateMasterSoundBase {
    GENERATED_BODY()
public:
    FAbramsSequencerPlayBgmEvaluate();
};


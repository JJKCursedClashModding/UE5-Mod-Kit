#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateSoundTrackBase.h"
#include "AbramsSequencerEvaluateMasterSoundBase.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerEvaluateMasterSoundBase : public FAbramsSequencerEvaluateSoundTrackBase {
    GENERATED_BODY()
public:
    FAbramsSequencerEvaluateMasterSoundBase();
};

